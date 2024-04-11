#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin>>n>>m;
	vector<int> inDegree(n, 0), outDegree(n, 0);
	vector<vector<int>> inEdges(n, vector<int>());
	for (int i=0; i<m; i++) {
		int a, b; cin>>a>>b; a--; b--;
		if (a>b) swap(a, b);
		inEdges[a].push_back(b);
		inDegree[a]++;
		outDegree[b]++;
	}
	ll total=0;
	for (int i=0; i<n; i++) {
		total+=inDegree[i]*(ll)outDegree[i];
	}
	cout<<total<<'\n';
	int q; cin>>q;
	for (int qq=0; qq<q; qq++) {
		int toGiveRaise; cin>>toGiveRaise; toGiveRaise--;
		//cout<<"Giving raise to "<<toGiveRaise<<endl;
		total-=inDegree[toGiveRaise]*(ll)outDegree[toGiveRaise];
		for (int to:inEdges[toGiveRaise]) {
			total-=inDegree[to]*(ll)outDegree[to];
			//cout<<"After subtracting "<<to<<": "<<total<<end;
			inDegree[to]++;
			outDegree[to]--;
			total+=inDegree[to]*(ll)outDegree[to];
			//cout<<"After subtracting "<<to<<": "<<total<<end;
			inEdges[to].push_back(toGiveRaise);
		}
		outDegree[toGiveRaise]+=inDegree[toGiveRaise];
		inDegree[toGiveRaise]=0;
		inEdges[toGiveRaise].clear();
		cout<<total<<'\n';
	}
	return 0;
}