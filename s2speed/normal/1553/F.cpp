#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		return;
	}

	void add(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] += k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , ln , lx , m);
		} else {
			add(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void add(ll i , ll k){
		add(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m); b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

segtree st;
ll a[maxn] , ps[maxn] , ans[maxn] , dp[maxn];
vector<ll> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ans , 0 , sizeof(ans));
	st.init(maxn);
	ll n , sq;
	cin>>n>>a[0]; sq = min(500ll , n);
	ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for(ll j = 0 ; (j + 1) * sq < n ; j++){
		for(ll i = 0 ; i < maxn ; i++) v[i].clear();
		ll lm = (j + 1) * sq;
		for(ll i = j * sq ; i < lm ; i++){
			for(ll k = a[i] ; k < maxn ; k += a[i]){
				v[k].push_back(a[i]);
			}
		}
		dp[0] = 0;
		for(ll i = 1 ; i < maxn ; i++){
			dp[i] = dp[i - 1] + sq;
			for(auto k : v[i]){
				dp[i] -= k;
			}
		}
		for(ll i = lm ; i < n ; i++){
			ans[i] += dp[a[i]];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ans[i] += (i ? ans[i - 1] + ps[i - 1] : 0);
		for(ll j = a[i] ; j < maxn ; j += a[i]){
			ll r = min(j + a[i] , maxn) , h;
			h = st.cal(j , r);
			ans[i] -= 1ll * j * h;
		}
		st.add(a[i] , 1);
		for(ll j = i - 1 ; (j + sq) % sq != sq - 1 ; j--){
			ans[i] += a[i] % a[j];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}