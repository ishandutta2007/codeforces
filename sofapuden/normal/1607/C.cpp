#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	sort(v.begin(),v.end());
	ll su = 0;
	ll mx = -(1ll<<60);
	for(int i = 0; i < n; ++i){
		v[i]+=su;
		mx = max(mx,v[i]);
		su-=v[i];
	}
	cout << mx << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t--){
		solve();
	}
}