#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 3e5 + 20 , md = 2000000357 , md2 = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll tav(ll n , ll k , ll m){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= m;
		}
		n *= n;
		n %= m;
		k /= 2;
	}
	return res;
}

struct segtree {

	ll sz = 1;
	vector<ll> val;

	void init(ll n){
		while(sz < n) sz *= 2;
		val.assign(2 * sz , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = val[ln] + val[rn];
		return;
	}

	void set(ll i , ll k){
		if(i == -1) return;
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) / 2 , ln = 2 * x + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return inf;
		return cal(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
	}

};

ll p = 31 , p2 = 29 , tm1 = tav(p , md - 2 , md) , tm2 = tav(p2 , md2 - 2 , md2) , e = 1 , e2 = 1 , c1 = 0 , c2 = 0;
ll tme = 0 , st[MAXN] , ft[MAXN];
pll h[MAXN];
vector<ll> adj[MAXN];
string s;

void hDFS(ll r , ll par){
	st[r] = tme++;
	c1 += 1ll * (s[r] - 'a' + 1) * e; c1 %= md;
	c2 += 1ll * (s[r] - 'a' + 1) * e2; c2 %= md2;
	h[r] = {c1 , c2};
//	cout<<c1<<' '<<c2<<' '<<r<<'\n';
	for(auto i : adj[r]){
		if(i == par) continue;
		e *= p; e %= md;
		e2 *= p2; e2 %= md2;
		hDFS(i , r);
		e *= tm1; e %= md;
		e2 *= tm2; e2 %= md2;
	}
	c1 -= 1ll * (s[r] - 'a' + 1) * e; c1 %= md; c1 += md; c1 %= md;
	c2 -= 1ll * (s[r] - 'a' + 1) * e2; c2 %= md2; c2 += md2; c2 %= md2;
	ft[r] = tme;
	return;
}

ll l[MAXN] , pr[MAXN] , a[MAXN] , c[MAXN] , ans[MAXN] , b[MAXN];
vector<pll> v;
vector<plll> q;
segtree str;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>c[i];
	}
	cin>>s;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	hDFS(0 , -1);
	str.init(n);
	for(ll i = 0 ; i < n ; i++){
		v.push_back(h[i]);
		q.push_back({ft[i] , {st[i] , i}});
	}
	sort(all(q));
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		b[i] = lower_bound(all(v) , h[i]) - v.begin();
		a[st[i]] = b[i];
	}
	memset(l , -1 , sizeof(l));
	memset(pr , -1 , sizeof(pr));
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(l[a[i]] == -1){
			l[a[i]] = i;
			continue;
		}
		pr[l[a[i]]] = i;
		l[a[i]] = i;
	}
	q.push_back({inf , {inf , -1}});
	ll x = 0;
	for(ll i = 0 ; i < n ; i++){
		str.set(pr[i] , 0);
		str.set(i , 1);
		while(q[x].first == i + 1){
			ll r = q[x].first , l = q[x].second.first , j = q[x].second.second , h;
			h = str.cal(l , r);
			ans[j] = h;
			x++;
		}
	}
	ll m = 0;
	vector<ll> y;
	for(ll i = 0 ; i < n ; i++){
//		cout<<ans[i]<<' ';
		if(ans[i] + c[i] > m){
			y.clear();
			y.push_back(i + 1);
			m = ans[i] + c[i];
		} else if(ans[i] + c[i] == m){
			y.push_back(i + 1);
		}
	}
	cout<<m<<'\n'<<y.size()<<'\n';
	return 0;
}

/*
6
0 2 4 1 1 1
raaaba
1 2
2 3
2 4
2 5
3 6
*/