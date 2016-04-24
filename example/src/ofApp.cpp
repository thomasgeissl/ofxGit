#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	
    ofAddListener(repo.complete, this, &ofApp::onCloneComplete);
	
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	ofDirectory dir("ofxFaceTracker");
	if (dir.exists())
		dir.remove(true);
	
	if (!repo.open("ofxFaceTracker"))
	{
		// $ git clone https://github.com/kylemcdonald/ofxFaceTracker.git
		repo.clone("https://github.com/kylemcdonald/ofxFaceTracker.git", false);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{

}

//--------------------------------------------------------------
void ofApp::onCloneComplete(ofEventArgs&)
{
	ofSystemAlertDialog("clone done");
	
	cout << "1: ==============================" << endl;
	
	// $ git branch -a
	repo.dump();
	cout << "cur branch: " << repo.getCurrentBranchName() << endl;
	
	cout << "2: ==============================" << endl;
	
	// $ git checkout -b origin/osc-syphon
	repo.getBranch("origin/osc-syphon")->fork("osc-syphon")->makeHead();
	repo.dump();
	cout << "cur branch: " << repo.getCurrentBranchName() << endl;
	
	cout << "3: ==============================" << endl;
	
	// $ git checkout master
	repo.getBranch("master")->makeHead();
	repo.dump();
	cout << "cur branch: " << repo.getCurrentBranchName() << endl;
	
	cout << "4: ==============================" << endl;
	
	// $ git branch -d osc-syphon
	repo.getBranch("osc-syphon")->remove();
	repo.dump();
	cout << "cur branch: " << repo.getCurrentBranchName() << endl;
	
	cout << "5: ==============================" << endl;

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
