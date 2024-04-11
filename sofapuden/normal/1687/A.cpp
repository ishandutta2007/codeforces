#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
void solve(){
	ll n, m; cin >> n >> m;
	vector<ll> v(n); for(auto &x : v)cin >> x;
	ll ans = 0;
	if(m > n){
		ans = accumulate(v.begin(),v.end(),0ll);
		ans+=m*n;
		ans-=n*(n+1)/2;
		cout << ans << '\n';

	}
	else{
		ans+=m*(m-1)/2;
		ll cu = 0;
		for(int i = 0; i < m; ++i){
			cu+=v[i];
		}
		ll mx = cu;
		for(int j = m; j < n; ++j){
			cu+=v[j];
			cu-=v[j-m];
			mx = max(mx,cu);
		}
		cout << ans+mx << '\n';
	}
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}