#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

void solve(){
	int n, q; cin >> n;
	vector<ll> pre(n);
	for(auto &x : pre)cin >> x;
	cin >> q;
	for(int i = 1; i < n; ++i)pre[i]+=pre[i-1];
	ll mx = 0;
	for(int i = 0; i < n; ++i){
		mx = max(mx, (pre[i]+i)/(i+1));
	}
	while(q--){
		ll x; cin >> x;
		if(x < mx){
			cout << -1 << '\n';
			continue;
		}
		cout << (pre[n-1]+x-1)/x << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();

}