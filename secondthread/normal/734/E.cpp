#include <bits/stdc++.h>

using namespace std;

struct Node {
	vector<Node*> adj;
	int moves;
	int maxDownSize;
	char color;
	
	Node(char color): color(color) {}

	void precalc(Node* par) {
		if ((adj.size()==1 && par!=NULL) || (adj.size()==0&&par==NULL)) {
			maxDownSize=0;
			return;
		}
		
		maxDownSize=0;
		for (Node* child:adj) {
			if (child==par) continue;
			child->precalc(this);
			maxDownSize=max(maxDownSize, (color==child->color?0:1)+child->maxDownSize);
		}
	}

	int down(Node* other) {
		if (other==NULL) return 0;
		int ans=other->maxDownSize;
		if (other->color != color) ans++;
		return ans;
	}

	void calc(Node* par, int maxSizeUp) {
		Node *biggestChild=NULL, *secondBiggest=NULL;
		moves=maxSizeUp;
		for (Node* nn:adj) {
			if (nn==par) continue;
			if (down(nn)>down(biggestChild)) {
				secondBiggest=biggestChild;
				biggestChild=nn;
			}
			else if (down(nn)>down(secondBiggest))
				secondBiggest=nn;
		}
		for (Node* nn:adj) {
			if (nn==par) continue;
			Node* nextBiggest=(nn==biggestChild?secondBiggest:biggestChild);
			int otherSize=max(down(nextBiggest), maxSizeUp);
			if (nn->color!=color) otherSize++;
			nn->calc(this, otherSize);
		}
		moves=max(moves, down(biggestChild));
	}


};

int main() {
	int n; cin>>n;
	vector<char> colors; colors.resize(n);
	for (int i=0; i<n; i++) cin>>colors[i];
	vector<Node> nodes; 
	for (int i=0; i<n; i++) {
		nodes.push_back(Node(colors[i]));
	}

	for (int i=1; i<n; i++) {
		int a, b; cin>>a>>b; a--; b--;
		nodes[a].adj.push_back(&nodes[b]);
		nodes[b].adj.push_back(&nodes[a]);
	}
	nodes[0].precalc(NULL);
	nodes[0].calc(NULL, 0);
	int minAns=1<<21;
	for (int i=0; i<n; i++)
		minAns=min(minAns, nodes[i].moves);
	cout<<minAns<<'\n';
	return 0;
}