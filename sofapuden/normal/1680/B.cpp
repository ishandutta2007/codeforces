#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<string> v(n);
		for(auto &x : v)cin >> x;
		int mnx = n-1, mny = m-1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(v[i][j] == 'R')mnx = min(mnx,i), mny = min(mny,j);
			}
		}
		cout << (v[mnx][mny] == 'R' ? "YES" : "NO") << '\n';
	}
}