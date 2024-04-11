#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int , int> pii;

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;

ll tav(ll n , ll k){
    ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}
 
ll fact[MAX_N] , fact_md[MAX_N];
 
void fact_build(){
    fact[0] = 1;
    fact_md[0] = 1;
    for(int i = 1 ; i < MAX_N ; i++){
	fact[i] = fact[i - 1] * i;
	fact[i] %= md;
        fact_md[i] = tav(fact[i] , md - 2);
    }
}
 
ll chs(ll n, ll k){
    if(k > n) return 0;
    return (((fact[n] * fact_md[k]) % md) * fact_md[n - k]) % md;
}

ll cnt[MAX_N] , ps[MAX_N];

void solve(){
	ll n , m , k;
	ll ans = 0;
	cin>>n>>m>>k;
	for(int i = 0 ; i < n ; i++){
		cnt[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		int h;
		cin>>h; h--;
		cnt[h]++;
	}
	ps[0] = cnt[0];
	for(int i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + cnt[i];
	}
	int x = 0 , y = -k - 1;
	while(x < n){
		ll h = ps[x] , q;
		if(y >= 0){
			h -= ps[y];
		}
		q = h - cnt[x];
		h = chs(h , m);
		q = chs(q , m);
		h -= q;
		h += md;
		h %= md;
		ans += h;
		ans %= md;
		x++; y++;
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}