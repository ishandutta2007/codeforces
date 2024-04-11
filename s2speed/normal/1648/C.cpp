#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

struct fentree {

	ll sz;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i , ll k){
		ll h = i;
		while(h < sz){
			val[h] += k;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll h = i , res = 0;
		while(~h){
			res += val[h];
			h &= (h + 1); h--;
		}
		return res;
	}

};

fentree ft;
ll cnt[maxn] , b[maxn] , inv[maxn] , fact[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , m;
	cin>>n>>m;
	ft.init(maxn);
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		cnt[h]++;
		ft.add(h , 1);
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i]; b[i]--;
	}
	ll cur = 1 , ans = 0;
	fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = i * fact[i - 1] % md;
		inv[i] = tav(i , md - 2);
	}
	cur = fact[n];
	for(ll i = 0 ; i < maxn ; i++){
		cur *= tav(fact[cnt[i]] , md - 2); cur %= md;
	}
	ll lm = min(n , m);
	for(ll i = 0 ; i < lm ; i++){
		ll h = ft.cal(b[i] - 1) * cur % md * inv[n - i] % md;
		ans += h;
		if(cnt[b[i]] == 0){
			cur = 0;
			break;
		}
		cur *= cnt[b[i]]--; cur %= md;
		cur *= inv[n - i]; cur %= md;
		ft.add(b[i] , -1);
	}
	ans += cur * (n < m);
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}