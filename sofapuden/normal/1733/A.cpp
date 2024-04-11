#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> v(m, 0);
	for(int i = 0; i < n; ++i){
		ll x; cin >> x;
		v[i%m] = max(v[i%m],x);
	}
	cout << accumulate(v.begin(),v.end(),0ll) << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}