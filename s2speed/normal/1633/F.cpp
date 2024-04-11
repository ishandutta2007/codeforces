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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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
	vector<ll> sum , val;
	vector<bool> laz;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		sum.assign(sz << 1 , 0);
		laz.assign(sz << 1 , false);
		return;
	}

	void build(vector<ll> &a , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			if(lx < sze(a)){
				sum[x] = a[lx];
			}
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		build(a , ln , lx , m); build(a , rn , m , rx);
		sum[x] = sum[ln] + sum[rn];
		return;
	}

	void build(vector<ll> &a){
		build(a , 0 , 0 , sz);
		return;
	}

	void shift(ll x , ll lx , ll rx){
		bool h = laz[x];
		laz[x] = false;
		if(!h) return;
		val[x] = sum[x] - val[x];
		if(rx - lx == 1) return;
		ll ln = (x << 1) + 1 , rn = ln + 1;
		laz[ln] = !laz[ln]; laz[rn] = !laz[rn];
		return;
	}

	void flip(ll l , ll r , ll x , ll lx , ll rx){
		shift(x , lx , rx);
		if(rx <= l || lx >= r) return;
		if(rx <= r && lx >= l){
			laz[x] = true;
			shift(x , lx , rx);
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		flip(l , r , ln , lx , m); flip(l , r , rn , m , rx);
		val[x] = val[ln] + val[rn];
		return;
	}

	void flip(ll l , ll r){
		flip(l , r , 0 , 0 , sz);
		return;
	}

	ll cal(){
		return val[0];
	}

};

segtree cnt , sum;
vector<ll> adj[maxn];
ll z[maxn] , hc[maxn] , hp[maxn] , pr[maxn] , w[maxn] , lb[maxn] , cur = 0;
bitset<maxn> hv , ac;
vector<pll> ed;

void pDFS(ll r , ll par){
	pr[r] = par;
	z[r] = 1;
	pll mx = {-1 , -1};
	for(auto i : adj[r]){
		if(i == par) continue;
		pDFS(i , r);
		z[r] += z[i];
		mx = max(mx , {z[i] , i});
	}
	hc[r] = mx.second;
	if(z[r] > 1){
		hv[mx.second] = true;
	}
	return;
}

void lDFS(ll r , ll par){
	lb[r] = cur++;
	hp[r] = (hv[r] ? hp[par] : r);
	if(hc[r] != -1) lDFS(hc[r] , r);
	for(auto i : adj[r]){
		if(i == par || i == hc[r]) continue;
		lDFS(i , r);
	}
	return;
}

void flip(ll v){
	while(~v){
		sum.flip(lb[hp[v]] , lb[v] + 1);
		cnt.flip(lb[hp[v]] , lb[v] + 1);
//		cout<<v<<' '<<lb[hp[v]]<<' '<<lb[v] + 1<<' '<<cnt.cal()<<'\n';
		v = pr[hp[v]];
	}
	return;
}

vector<ll> a , qu;

void qDFS(ll r , ll par){
	z[r] = ac[r];
	for(auto i : adj[r]){
		if(i == par) continue;
		qDFS(i , r);
		z[r] += z[i];
	}
	if(z[r] & 1) qu.push_back(w[r]);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	a.assign(n , 1); a[0] = 0;
	for(ll i = 1 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({v , u});
	}
	pDFS(0 , -1);
	lDFS(0 , -1);
	sum.init(n); cnt.init(n);
	cnt.build(a); a[0] = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll v = ed[i].first , u = ed[i].second;
		if(pr[u] == v) swap(v , u);
		w[v] = a[lb[v]] = i + 1;
	}
	sum.build(a);
//	for(ll i = 0 ; i < n ; i++){
//		cout<<hp[i]<<' ';
//	}
//	cout<<'\n';
//	cout<<cnt.cal()<<' ';
//	flip(3);
//	cout<<cnt.cal()<<' ';
	ll pr , cur = 1;
	ac[0] = true;
	while(true){
		ll t;
		cin>>t;
		if(t == 0 || t == 3) return 0;
		if(t == 1){
			ll i;
			cin>>i; i--;
			flip(i);
			cur++;
			ac[i] = true;
			if(cur & 1){
				pr = 0;
				cout<<pr<<endl;
				continue;
			}
			ll h = cur >> 1;
			if(cnt.cal() != h){
				pr = 0;
				cout<<pr<<endl;
				continue;
			}
			pr = sum.cal();
			cout<<pr<<endl;
			continue;
		}
		if(pr == 0){
			cout<<pr<<endl;
			continue;
		}
		qu.clear();
		qDFS(0 , -1);
		cout<<sze(qu)<<' ';
		sort(all(qu));
		for(auto i : qu){
			cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}

/*
6
1 4
6 1
3 2
1 2
5 1
1 4
2
3
*/