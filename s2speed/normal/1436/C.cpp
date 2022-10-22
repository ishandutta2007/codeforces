#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1001 , md = 1e9 + 7;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x % md;
	} else {
		return x * x % md * n % md;
	}
}

ll fact[MAX_N];

void fact_build(){
	fact[0] = 1;
	for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
	}
}

ll chs(ll n, ll k){
    if(k > n) return 0;
    return (((fact[n] * tav(fact[k] , md - 2)) % md) * tav(fact[n - k] , md - 2)) % md;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fact_build();
	ll n , x , p;
	cin>>n>>x>>p;
	ll b = 0 , s = 0;
	ll l = 0 , r = n;
	while(l < r){
		ll m = (r + l) / 2;
		if(p == m){
			l = m + 1;
		} else {
			if(p > m){
				l = m + 1;
				s++;
			} else {
				r = m;
				b++;
			}
		}
	}
	ll ans;
	ans = chs(x - 1 , s);
	ans *= fact[s];
	ans %= md;
	ans *= chs(n - x , b);
	ans %= md;
	ans *= fact[b];
	ans %= md;
	ans *= fact[n - s - b - 1];
	ans %= md;
	cout<<ans<<"\n";
	return 0;
}