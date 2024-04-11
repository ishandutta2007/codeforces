#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		ll cur = 1;
		ll ans = 0;
		for(ll i = 2; cur <= n; ++i){
			if(cur%i){
				ll x = i/__gcd(i,cur);
				ans+=i*((n/cur)-(n/(x*cur)));
				cur*=x;
				ans%=MOD;
			}
		}
		cout << ans << '\n';
	}
}