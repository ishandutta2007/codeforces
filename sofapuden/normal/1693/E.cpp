#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> bit(n+1,0);
	vector<vector<int>> h(n+1);
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		h[x].push_back(i+1);
	}
	int lo = 1, hi = n+1;
	ll ans = 0;
	for(int i = n; i; --i){
		if(h[i].empty())continue;

		int lslo = lo;
		lo = min(hi+1,h[i][0]);
		hi = max(lslo-1,h[i].back());

		for(auto x : h[i])for(int j = x; j <= n; j+=(j&-j))bit[j]++;

		for(int j = lo-1; j; j ^= (j & -j))ans-=bit[j]; 
		for(int j = hi; j; j ^= (j & -j))ans+=bit[j]; 
	}
	cout << ans << '\n';
}