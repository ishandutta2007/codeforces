#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
	vector<Node*> adj;
	int preorder, postorder;
	int color;

	Node(int color): color(color) {}

	int dfs(int preorder, Node* par) {
		this->preorder=preorder;
		for (Node *n:adj)
			if (n!=par)
				preorder=n->dfs(preorder+1, this);
		return this->postorder=preorder;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<Node> nodes;
	for (int i=0; i<n; i++) {
		int c; cin>>c; nodes.emplace_back(c);
	}

	for (int i=1; i<n; i++) {
		int a, b; cin>>a>>b;
		a--; b--;
		nodes[a].adj.push_back(&nodes[b]);
		nodes[b].adj.push_back(&nodes[a]);
	}

	nodes[0].dfs(0, NULL);
	vector<int> aCount(n, 0), bCount(n, 0);
	for (int i=0; i<n; i++)
		if (nodes[i].color==1)
			aCount[nodes[i].preorder]++;
		else if (nodes[i].color==2)
			bCount[nodes[i].preorder]++;
	vector<int> acs(n+1, 0), bcs(n+1, 0);
	for (int i=1; i<=n; i++) {
		acs[i]=acs[i-1]+aCount[i-1];
		bcs[i]=bcs[i-1]+bCount[i-1];
	}
	int working=0;
	for (int i=1; i<n; i++) {
		int aCount=acs[nodes[i].postorder+1]-acs[nodes[i].preorder];
		int bCount=bcs[nodes[i].postorder+1]-bcs[nodes[i].preorder];
		//cout<<"For the parent of "<<i<<" counts are: "<<aCount<<" "<<bCount<<endl;
		//cout<<"Preorder/postorder: "<<nodes[i].preorder<<" "<<nodes[i].postorder<<endl;
		if (aCount==0&&bCount==bcs[n]) working++;
		else if (aCount==acs[n]&&bCount==0) working++;
	}
	cout<<working<<'\n';
	return 0;
}