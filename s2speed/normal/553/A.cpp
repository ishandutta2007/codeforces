#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e4 , md = 1e9 + 7;

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
	fact_build();
	ll n , cnt = 0 , ans = 1;
	cin>>n>>cnt;
	for(int i = 1 ; i < n ; i++){
		ll inp , z;
		cin>>inp; inp--;
		z = chs(cnt + inp , cnt);
		ans *= z;
		ans %= md;
		cnt += inp + 1;
	}
	cout<<ans<<"\n";
}