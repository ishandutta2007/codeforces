#include <bits/stdc++.h>

using namespace std;

struct Node {
	string type;
	Node *lChild, *rChild;
	int value=-1;
	bool matters=false;

	void dfs() {
		if (type=="IN") return;
		lChild->dfs();
		if (type=="NOT") {
			value=!lChild->value;
			return;
		}
		rChild->dfs();
		if (type=="AND") {
			value=lChild->value&rChild->value;
		}
		else if (type=="OR") {
			value=lChild->value|rChild->value;
		}
		else if (type=="XOR") {
			value=lChild->value ^ rChild->value;
		}
		//cout<<type<<" value: "<<value<<endl;
	}

	void mattersDFS() {
		matters=true;
		if (type=="IN") return;
		if (type=="NOT") {
			lChild->mattersDFS();
			return;
		}
		if (type=="XOR") {
			lChild->mattersDFS();
			rChild->mattersDFS();
		}
		else if (type=="AND") {
			if (value) {
				lChild->mattersDFS();
				rChild->mattersDFS();
			}
			else if (lChild->value) {
				rChild->mattersDFS();
			}
			else if (rChild->value) {
				lChild->mattersDFS();
			}
		}
		else if (type=="OR") {
			if (!value) {
				lChild->mattersDFS();
				rChild->mattersDFS();
			}
			else if (!lChild->value) {
				rChild->mattersDFS();
			}
			else if (!rChild->value) {
				lChild->mattersDFS();
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int nNodes; cin>>nNodes;
	Node nodes[nNodes];
	vector<int> inputNodes;
	for (int i=0; i<nNodes; i++) {
		string type; cin>>type;
		nodes[i].type=type;
		if (type=="IN") {
			int value; cin>>value;
			inputNodes.push_back(i);
			nodes[i].lChild=nodes[i].rChild=NULL;
			nodes[i].value=value;
		}
		else if (type=="NOT") {
			int lChild; cin>>lChild;
			lChild--;
			nodes[i].rChild=NULL;
			nodes[i].lChild=&(nodes[lChild]);
		}
		else {
			int lChild, rChild; cin>>lChild>>rChild;
			lChild--;
			rChild--;
			nodes[i].lChild=&(nodes[lChild]);
			nodes[i].rChild=&(nodes[rChild]);
		}
	}
	nodes[0].dfs();
	nodes[0].mattersDFS();
	for (int i:inputNodes) {
		if (nodes[i].matters) {
			cout<<!(nodes[0].value);
		}
		else {
			cout<<nodes[0].value;
		}
	}
	cout<<endl;
	return 0;
}