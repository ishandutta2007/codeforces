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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , -inf);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll k , ll x , ll lx , ll rx){
		if(val[x] <= k) return -1;
		if(rx <= l || lx >= r) return -1;
		if(rx - lx == 1){
			return lx;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a = cal(l , r , k , rn , m , rx);
		if(a != -1) return a;
		return cal(l , r , k , ln , lx , m);
	}

	ll cal(ll l , ll r , ll k){
		return cal(l , r , k , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

segtree st;
ll a[maxn] , dp[maxn] , ps[maxn] , pr[maxn];

void solve(){
	st.clear();
	ll n;
	cin>>n;
	st.init(n + 1);
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
		st.set(i , ps[i]);
	}
	a[0] = -1;
	for(ll i = 1 ; i <= n ; i++){
		if(a[i] != 0) continue;
		if(a[i - 1] == 0){
			pr[i] = pr[i - 1];
		} else {
			pr[i] = i;
		}
	}
	dp[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		if(ps[i] > 0){
			dp[i] = i;
			continue;
		}
		ll h = st.cal(0 , i , ps[i]) + 1;
		if(a[i] == 0 && h == pr[i]){
			dp[i] = dp[i - 1];
			continue;
		}
		dp[i] = i - h - (a[h] < 0) + dp[h - 1];
	}
	cout<<dp[n]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	ll T;
//	cin>>T;
//	while(T--) solve();
	ll n;
	cin>>n;
	ll k = n / 3;
	if(n % 3 != 0){
		ll ans = 2 * k + 1;
		cout<<ans<<'\n';
		ll x = 1 , y = k + 1;
		while(y){
			cout<<x<<' '<<y<<'\n';
			x++; y--;
		}
		x = k + 2; y = ans;
		while(x <= ans){
			cout<<x<<' '<<y<<'\n';
			x++; y--;
		}
		return 0;
	}
	cout<<2 * k<<'\n';
	k--;
	ll ans = 2 * k + 1;
	ll x = 1 , y = k + 1;
	while(y){
		cout<<x<<' '<<y<<'\n';
		x++; y--;
	}
	x = k + 2; y = ans;
	while(x <= ans){
		cout<<x<<' '<<y<<'\n';
		x++; y--;
	}
	cout<<n<<' '<<n<<'\n';
	return 0;
}