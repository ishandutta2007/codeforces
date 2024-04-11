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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

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

struct fentree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void add(ll i , ll k){
		ll h = i;
		while(h < sz){
			val[h] += k; val[h] %= md;
			h |= (h + 1);
		}
		return;
	}

	ll cal(ll i){
		ll res = 0 , h = i;
		while(h > -1){
			res += val[h]; res %= md;
			h &= h + 1; h--;
		}
		return res;
	}

	ll cal(ll l , ll r){
		ll res = cal(r - 1) - cal(l - 1);
		if(res < 0) res += md;
		return res;
	}

};

fentree st;
ll x[maxn] , y[maxn] , w[maxn] , z[maxn] , dp[maxn];
bool s[maxn];
vector<pll> t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	st.init(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i]>>y[i]>>s[i];
		t.push_back({y[i] , i});
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		w[i] = x[i + 1] - x[i];
	}
	w[n - 1] = 1;
	ll p = 0;
	sort(all(t));
	for(ll i = 0 ; i < n ; i++){
		while(x[p] < t[i].first) p++;
		z[t[i].second] = p;
	}
	ll ans = x[0];
	for(ll i = 0 ; i < n ; i++){
		ll h = st.cal(z[i] , i) + w[i] + x[z[i]] - y[i];
		h %= md; if(h < 0) h += md;
		dp[i] = h;
		if(s[i]){
			ans += dp[i];
		} else {
			ans += w[i];
		}
		ans %= md;
		st.add(i , dp[i]);
//		cout<<st.cal(z[i] , i)<<' ';
	}
//	cout<<'\n';
	cout<<ans<<'\n';
	return 0;
}