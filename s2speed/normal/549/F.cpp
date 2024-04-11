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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<pll> val;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , {0 , -1});
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < sze(a)){
				val[x] = {a[lx] , lx};
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	pll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return {0 , -1};
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		pll a = cal(l , r , ln , lx , m) , b = cal(l , r , rn , m , rx);
		return max(a , b);
	}

	pll cal(ll l , ll r){
		return cal(l , r , 0 , 0 , sz);
	}

};

ll n , k;
segtree st;
int cnt[20][maxn];
ll ps[maxn] , ans = 0;
vector<ll> a;

void dv(ll l , ll r , ll j){
	if(l >= r) return;
	if(r - l == 1){
		ans++;
		return;
	}
	ll m = st.cal(l , r).second , mid = (r + l) >> 1;
	ll mx = a[m] % k;
	if(m <= mid){
		for(ll i = l ; i < m ; i++) cnt[j][ps[i]]--;
		for(ll i = l ; i < m ; i++){
			ll h = mx + ps[i]; h -= (h >= k) * k;
			ans += cnt[j][h];
		}
		ll h = mx + (l ? ps[l - 1] : 0); h -= (h >= k) * k;
		ans += cnt[j][h];
		cnt[j][ps[m]]--;
		dv(m + 1 , r , j);
		j++;
		for(ll i = l ; i < m ; i++){
			cnt[j][ps[i]]++;
		}
		dv(l , m , j);
		for(ll i = l ; i < m ; i++){
			cnt[j][ps[i]]--;
		}
		j--;
		for(ll i = l ; i <= m ; i++) cnt[j][ps[i]]++;
		return;
	}
	for(ll i = m ; i < r ; i++){
		cnt[j][ps[i]]--;
	}
	cnt[j][(l ? ps[l - 1] : 0)]++;
	for(ll i = m ; i < r ; i++){
		ll h = ps[i] - mx; h += (h < 0) * k;
		ans += cnt[j][h];
	}
	cnt[j][(l ? ps[l - 1] : 0)]--;
	dv(l , m , j);
	j++;
	for(ll i = m + 1 ; i < r ; i++){
		cnt[j][ps[i]]++;
	}
	dv(m + 1 , r , j);
	for(ll i = m + 1 ; i < r ; i++){
		cnt[j][ps[i]]--;
	}
	j--;
	for(ll i = m ; i < r ; i++){
		cnt[j][ps[i]]++;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	cin>>n>>k;
	a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ps[0] = a[0] % k;
	for(ll i = 1 ; i < n ; i++){
		ps[i] = a[i] + ps[i - 1]; ps[i] %= k;
	}
	st.init(n);
	st.build(a);
	for(ll i = 0 ; i < n ; i++){
		cnt[0][ps[i]]++;
	}
	dv(0 , n , 0);
	cout<<ans - n<<'\n';
	return 0;
}