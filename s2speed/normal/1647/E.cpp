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

vector<ll> adj[maxn];
ll jad[maxn][30] , p[maxn] , b[maxn] , a[maxn];
vector<ll> dor[maxn];
bitset<maxn> mark , comp , f , chs , app;
vector<ll> c;
set<ll> np;

void jDFS(ll r){
	if(!f[r]){
		jad[r][0] = p[r];
		for(ll j = 1 ; j < 30 ; j++){
			jad[r][j] = jad[jad[r][j - 1]][j - 1];
		}
		f[r] = true;
	}
	for(auto i : adj[r]){
		if(f[i]) continue;
		jDFS(i);
	}
	return;
}

ll find_jad(ll v , ll d){
	for(ll j = 0 ; j < 30 ; j++){
		if(d & (1 << j)){
			v = jad[v][j];
		}
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>p[i]; p[i]--;
		adj[p[i]].push_back(i);
	}
	ll mx = -1 , lf = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		mx = max(mx , a[i]);
		lf += adj[i].empty();
		if(a[i] < n){
			app[a[i]] = true;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(app[i]) continue;
		np.insert(i);
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(comp[i]) continue;
		ll v = i;
		while(true){
			mark[v] = true;
			c.push_back(v);
			v = p[v];
			if(comp[v]) break;
			if(mark[v]){
				while(c.back() != v){
					ll u = c.back(); c.pop_back();
					comp[u] = f[u] = true;
					dor[cnt].push_back(u);
				}
				comp[v] = f[v] = true;
				dor[cnt++].push_back(v);
				break;
			}
		}
		for(auto v : c){
			comp[v] = true;
		}
		c.clear();
	}
	for(ll i = 0 ; i < cnt ; i++){
		for(auto v : dor[i]){
			jad[v][0] = p[v];
		}
		for(ll j = 1 ; j < 30 ; j++){
			for(auto v : dor[i]){
				jad[v][j] = jad[jad[v][j - 1]][j - 1];
			}
		}
		for(auto v : dor[i]) jDFS(v);
	}
	ll t = (mx - n + 1) / lf;
	for(ll i = 0 ; i < n ; i++){
		ll h = find_jad(i , t);
		if(chs[h]){
			b[i] = *np.upper_bound(a[h]);
			np.erase(b[i]);
		} else {
			b[i] = a[h];
			chs[h] = true;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<b[i] + 1<<' ';
	}
	cout<<'\n';
	return 0;
}