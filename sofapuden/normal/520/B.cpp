#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	set<int> vis;
	queue<pair<int,int>> Q;
	Q.push({n,0});
	while(Q.size()){
		auto x = Q.front();
		Q.pop();
		if(x.first > 40000 || x.first < 0)continue;
		if(vis.count(x.first))continue;
		vis.insert(x.first);
		if(x.first == m)cout << x.second << "\n";
		Q.push({x.first*2,x.second+1});
		Q.push({x.first-1,x.second+1});

	}	
}