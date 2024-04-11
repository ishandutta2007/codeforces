#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, p, k; cin >> n >> p >> k;
	map<ll,ll> M;
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ll x; cin >> x;
		ans+=M[(x*x%p*x%p*x%p-k*x+k*p)%p]++;
	}
	cout << ans << '\n';
}