#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

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

bitset<maxn> ans , done , dir;
vector<pll> v[maxn] , g[maxn] , ed;
vector<ll> adj[maxn];
ll d[maxn] , a[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;

void bDFS(ll r){
//	cout<<r<<' ';
	done[r] = true;
	for(auto i : adj[r]){
		if(dir[i]) continue;
		ans[a[i]] = (r == ed[i].second);
		ll v = (ans[a[i]] ? ed[i].first : ed[i].second);
		dir[i] = true;
		if(done[v]) return;
		bDFS(v);
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(d , 0 , sizeof(d));
	ll n , m;
	cin>>m>>n;
	for(ll i = 0 ; i < m ; i++){
		ll k;
		cin>>k;
		for(ll j = 0 ; j < k ; j++){
			ll x;
			cin>>x;
			ll h = abs(x) - 1 , o = (x > 0);
			v[i].push_back({h , o});
			g[h].push_back({i , o});
		}
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(sze(g[i]) == 1){
			ans[i] = g[i][0].second;
			done[g[i][0].first] = true;
			continue;
		}
		if(sze(g[i]) == 0){
			ans[i] = false;
			continue;
		}
		bool f = false;
		for(auto p : g[i]){
			f ^= p.second;
		}
		ll v = g[i][0].first , u = g[i][1].first , o = g[i][0].second;
		if(f){
			if(o){
				ed.push_back({u , v});
			} else {
				ed.push_back({v , u});
			}
			adj[v].push_back(cnt); adj[u].push_back(cnt);
			a[cnt++] = i;
			d[v]++; d[u]++;
			continue;
		}
		done[v] = done[u] = true;
		ans[i] = o;
	}
	for(ll i = 0 ; i < m ; i++){
//		cout<<i<<' '<<d[i]<<' '<<done[i]<<'\n';
		if(done[i]) continue;
		pq.push({d[i] , i});
	}
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(d[v] != p.first) continue;
//		cout<<v<<' '<<d[v]<<'\n';
		if(d[v] == 0){
			cout<<"NO\n";
			return 0;
		}
		if(d[v] >= 2) break;
		for(auto i : adj[v]){
			if(dir[i]) continue;
			dir[i] = true;
			done[v] = true;
			ans[a[i]] = (v == ed[i].second);
			ll u = (ans[a[i]] ? ed[i].first : ed[i].second);
			d[u]--;
			if(!done[u]) pq.push({d[u] , u});
		}
	}
	for(ll i = 0 ; i < m ; i++){
		if(done[i]) continue;
		bDFS(i);
//		cout<<'\n';
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i];
	}
	cout<<'\n';
	return 0;
}

/*
4 5
2 1 2
3 -1 3 4
3 -2 -3 5
2 -4 -5
*/