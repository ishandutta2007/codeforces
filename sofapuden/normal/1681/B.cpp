#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n;cin >> n;
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	int m; cin >> m;
	ll su = 0;
	for(int i = 0; i < m; ++i){
		ll x; cin >> x;
		su+=x;
	}
	cout << v[su%n] << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}