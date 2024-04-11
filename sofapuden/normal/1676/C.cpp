#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	vector<string> v(n);for(auto &x : v)cin >> x;
	int ans = 10000000;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			int cu = 0;
			for(int k = 0; k < m; ++k){
				cu+=abs(v[i][k]-v[j][k]);
			}
			ans = min(ans,cu);
		}
	}
	cout << ans << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}