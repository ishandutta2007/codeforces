#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> gr(n), ingr(n);
	for(int i =0 ; i < m; ++i){
		int a, b; cin >> a >> b, a--, b--;
		gr[a].push_back(b);
		ingr[b].push_back(a);
	}
	vector<int> dp(n,-1);
	vector<int> sz(n);
	for(int i = 0; i < n; ++i)sz[i] = gr[i].size();
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,n-1});
	while(pq.size()){
		auto x = pq.top();
		pq.pop();
		if(dp[x.second] != -1)continue;
		dp[x.second] = x.first;
		for(auto y : ingr[x.second]){
			pq.push({sz[y]+dp[x.second],y});
			sz[y]--;
		}
	}
	cout << dp[0] << '\n';
}