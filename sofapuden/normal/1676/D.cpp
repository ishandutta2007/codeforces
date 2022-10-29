#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

void solve(){
	int n; cin >> n;
	int m; cin >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for(auto &x : v)for(auto &y : x)cin >> y;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int cu = 0;
			for(int k = -n; k < n; ++k){
				if(i+k < n && j+k < m && i+k >= 0 && j+k >= 0){
					cu+=v[i+k][j+k];
				}
			}
			for(int k = -n; k < n; ++k){
				if(k == 0)continue;
				if(i-k < n && j+k < m && i-k >= 0 && j+k >= 0){
					cu+=v[i-k][j+k];
				}
			}
			ans = max(ans,cu);
		}
	}
	cout << ans << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}