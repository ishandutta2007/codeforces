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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 72 , maxv = 1e7 + 16 , md = 2000000357 , inf = 2e9;

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

int ds[maxn] , dsz[maxn];

int dsu(int v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

void merge(int v , int u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	ds[u] = v;
	dsz[v] += dsz[u];
	return;
}

int n , m , a , b;
vector<pii> c;
vector<int> adj[maxn] , bdj[maxn];
int lb[maxn] , o = 0 , lm , dis[maxv];
bitset<maxn> mark;
deque<pii> aq , bq;

void dij(){
	int ms = (dsz[ds[0]] >= 4 ? (1 << lb[ds[0]]) : 0);
	aq.push_back({0 , ms});
	dis[ms] = 0;
	while(!aq.empty() || !bq.empty()){
		pii p;
		if(aq.empty()){
			p = bq.front();
			bq.pop_front();
		} else if(bq.empty()){
			p = aq.front();
			aq.pop_front();
		} else {
			if(aq.front().first <= bq.front().first){
				p = aq.front(); aq.pop_front();
			} else {
				p = bq.front(); bq.pop_front();
			}
		}
		int v = p.second / lm , mask = p.second % lm , t = p.second;
		if(dis[t] < p.first) continue;
		for(auto j : adj[v]){
			int i = j * lm + mask;
			if(dis[i] > dis[t] + a){
				dis[i] = dis[t] + a;
				aq.push_back({dis[i] , i});
			}
		}
		for(auto j : bdj[v]){
			int msk = mask | (dsz[ds[j]] >= 4 ? (1 << lb[ds[j]]) : 0) , i;
			if(ds[j] == ds[v]) continue;
			if(mask == msk && dsz[ds[j]] >= 4) continue;
			i = j * lm + msk;
			if(dis[i] > dis[t] + b){
				dis[i] = dis[t] + b;
				bq.push_back({dis[i] , i});
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	cin>>n>>m>>a>>b;
	iota(ds , ds + n , 0);
	fill(dsz , dsz + n , 1);
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin>>v>>u>>w; v--; u--;
		if(w == a){
			merge(v , u);
			adj[v].push_back(u); adj[u].push_back(v);
		} else {
			bdj[v].push_back(u); bdj[u].push_back(v);
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[dsu(i)]) continue;
		mark[ds[i]] = true;
		c.push_back({dsz[ds[i]] , ds[i]});
	}
	sort(all(c) , greater<pii>());
	int cs = sze(c);
	for(int e = 0 ; e < cs ; e++){
		int j = c[e].second;
		lb[j] = e;
		if(c[e].first >= 4) o++;
	}
	lm = (1 << o);
	dij();
	for(int i = 0 ; i < n ; i++){
		int ans = inf;
		for(int j = 0 ; j < lm ; j++){
			ans = min(ans , dis[i * lm + j]);
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}