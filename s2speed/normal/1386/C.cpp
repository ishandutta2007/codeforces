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

ll ds[maxn] , dsz[maxn];
bool dc[maxn];
vector<ll> upd;

ll dsu(ll v){
	return (v == ds[v] ? v : dsu(ds[v]));
}

bool dsc(ll v){
	return (v == ds[v] ? false : dc[v] ^ dsc(ds[v]));
}

bool merge(ll v , ll u){
	bool h = !(dsc(v) ^ dsc(u));
	v = dsu(v); u = dsu(u);
	if(v == u){
		upd.push_back(-1);
		return !h;
	}
	if(dsz[v] < dsz[u]) swap(v , u);
	ds[u] = v;
	dsz[v] += dsz[u];
	dc[u] = h;
	upd.push_back(u);
	return true;
}

void undo(){
	ll u = upd.back(); upd.pop_back();
	if(u == -1) return;
	ll v = ds[u];
	dsz[v] -= dsz[u];
	ds[u] = u;
	dc[u] = false;
	return;
}

ll f[maxn];
vector<pll> ed;

void div(ll l , ll r , ll opl , ll opr){
	if(l >= r) return;
	ll m = (r + l) >> 1;
	for(ll i = l ; i < m ; i++){
		merge(ed[i].first , ed[i].second);
	}
	for(ll i = opr - 1 ; i >= opl - 1 ; i--){
		if(!merge(ed[i].first , ed[i].second)){
			f[m] = i + 1;
			undo();
			break;
		}
	}
//	cout<<l<<' '<<r<<' '<<opl<<' '<<opr<<endl;
	for(ll i = f[m] ; i < opr ; i++) undo();
	if(r - l == 1) return;
	div(m , r , f[m] , opr);
	for(ll i = l ; i < m ; i++) undo();
	for(ll i = opr - 1 ; i >= f[m] ; i--) merge(ed[i].first , ed[i].second);
	div(l , m , opl , f[m]);
	for(ll i = opr - 1 ; i >= f[m] ; i--) undo();
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(f , 63 , sizeof(f));
	ll n , m , q;
	cin>>n>>m>>q;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
	}
	for(ll i = 0 ; i < n ; i++){
		ds[i] = i;
		dsz[i] = 1;
		dc[i] = false;
	}
	ll r = -1;
	for(ll i = 0 ; i < m ; i++){
		if(!merge(ed[i].first , ed[i].second)){
			r = i;
			break;
		}
	}
	if(r == -1){
		for(ll i = 0 ; i < q ; i++){
			cout<<"NO\n";
		}
		return 0;
	}
	for(ll i = 0 ; i <= r ; i++) undo();
	div(0 , r + 1 , 0 , m);
//	for(ll i = 0 ; i <= r ; i++){
//		cout<<f[i]<<' ';
//	}
	for(ll i = 0 ; i < q ; i++){
		ll l , r;
		cin>>l>>r; l--;
		cout<<(f[l] > r ? "YES\n" : "NO\n");
	}
	return 0;
}

/*
6 8 0
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
*/