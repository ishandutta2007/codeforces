#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e17;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll fact[maxn] , fact_md[maxn];

void fact_build(){
	fact[0] = 1;
	fact_md[0] = 1;
	for(int i = 1 ; i < maxn ; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= md;
		fact_md[i] = tav(fact[i] , md - 2);
	}
}

ll chs(ll n , ll k){
	if(k > n || k < 0) return 0;
	return fact[n] * fact_md[k] % md * fact_md[n - k] % md;
}

ll z[maxn] , ch[maxn] , cnt[maxn];
vector<ll> dv[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	iota(z , z + maxn , 0);
	for(ll i = 1 ; i < maxn ; i++){
		dv[i].push_back(i);
		for(ll j = i << 1 ; j < maxn ; j += i){
			dv[j].push_back(i);
			z[j] -= z[i];
		}
	}
	fact_build();
	ll n , k , q , cur = 0;
	cin>>n>>k>>q;
	for(ll i = 0 ; i < maxn ; i++){
		ch[i] = chs(i , k);
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(auto j : dv[h]){
			cur -= 1ll * ch[cnt[j]++] * z[j] % md;
			cur += 1ll * ch[cnt[j]] * z[j] % md;
			cur %= md; if(cur < 0) cur += md;
		}
	}
	for(ll i = 0 ; i < q ; i++){
		ll h;
		cin>>h;
		for(auto j : dv[h]){
			cur -= 1ll * ch[cnt[j]++] * z[j] % md;
			cur += 1ll * ch[cnt[j]] * z[j] % md;
			cur %= md; if(cur < 0) cur += md;
		}
		cout<<cur<<'\n';
	}
	return 0;
}