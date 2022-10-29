#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		int cn = 0;
		ll ans = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				char c; cin >> c;
				cn+= c == '#';
				ans<<=c == '#';
				ans%= (ll)1e9+7;
			}
		}
		cout << ans - (cn == n*m) << '\n';
	}
}