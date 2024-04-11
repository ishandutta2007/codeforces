#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct Node {
	vector<Node *> adj;
	vector<Node *> treeEdges;
	bool visited=false;
	int nNodesInSubtree;
	ll subtreeDegreeSum=0;
	ll value;
	ll returnableValue=0;
	ll unreturnableBonus=0;
	int index;

	Node(int index, ll value): index(index), value(value) {}

	void dfs(int parentIndex) {
		visited=true;
		nNodesInSubtree=1;
		if (parentIndex==-1) subtreeDegreeSum=adj.size();
		else subtreeDegreeSum=adj.size()-1;

		for (Node *n:adj) {
			if (n->visited) continue;
			if (n->index==parentIndex) continue;
			treeEdges.push_back(n);
			n->dfs(index);
			nNodesInSubtree+=n->nNodesInSubtree;	
			subtreeDegreeSum+=n->subtreeDegreeSum;
			returnableValue+=n->returnableValue;
			unreturnableBonus=max(unreturnableBonus, n->unreturnableBonus);
		}
		if (subtreeDegreeSum>=nNodesInSubtree) {
			returnableValue+=value;
		}
		else {
			unreturnableBonus+=value;
		}
		//cout<<"index: "<<index<<" returnable: "<<returnableValue<<" unreturnable:" << unreturnableBonus<<endl;
	}
};

int main() {
	int n, m; cin>>n>>m;
	vector<Node> nodes;
	for (int i=0; i<n; i++) {
		ll value; cin>>value;
		nodes.push_back(Node(i, value));
	}
	for (int i=0; i<m; i++) {
		int a, b; cin>>a>>b;
		a--; b--;
		nodes[a].adj.push_back(&nodes[b]);
		nodes[b].adj.push_back(&nodes[a]);
	}
	int startNode; cin>>startNode;
	startNode--;
	nodes[startNode].dfs(-1);
	cout<<(nodes[startNode].returnableValue+
			nodes[startNode].unreturnableBonus)<<endl;
	return 0;
}