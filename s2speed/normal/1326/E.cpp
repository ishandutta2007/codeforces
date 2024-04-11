#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
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
	vector<ll> val , xal;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		xal.assign(sz << 1 , 0);
		return;
	}

	void add(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] += k; xal[x] += k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			add(i , k , ln , lx , m);
		} else {
			add(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		xal[x] = max(xal[rn] , xal[ln] + val[rn]);
		return;
	}

	void add(ll i , ll k){
		add(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(){
		return xal[0];
	}

};

segtree st;
ll a[maxn] , p[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		p[a[i]] = i;
	}
	st.init(n);
	st.add(p[n - 1] , 1);
	ll ans = n - 1;
	cout<<ans + 1<<' ';
	for(ll i = 0 ; i < n - 1 ; i++){
		ll h;
		cin>>h; h--;
		st.add(h , -1);
		while(st.cal() <= 0){
			st.add(p[--ans] , 1);
		}
		cout<<ans + 1<<' ';
	}
	return 0;
}