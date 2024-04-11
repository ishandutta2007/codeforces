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

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

vector<pll> ed , ans , be[maxn];
bitset<maxn> hm , mark;
ll d[maxn] , t[maxn] , dis[maxn] , dep , x[maxn] , bs[maxn];
vector<ll> f , adj[maxn] , ch[maxn];

void bDFS(ll r){
	mark[r] = true;
	dis[r] = dep++;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		bDFS(i);
	}
	dep--;
	return;
}

void jDFS(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		jDFS(i);
	}
	for(ll i = 0 ; i < sze(ch[r]) ; i++){
		ll v = ch[r][i];
		ans.push_back({r , v});
		x[v]++;
		if(x[v] < bs[v]){
			ch[be[v][x[v]].second].push_back(v);
		}
	}
	ll cs = sze(ch[r]);
	if((cs & 1) ^ t[r]){
		ans.push_back({r , be[r][0].second});
		x[r]++;
	}
	if(x[r] < bs[r]){
		ch[be[r][x[r]].second].push_back(r);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		ed.push_back({v , u});
		d[v] ^= 1; d[u] ^= 1;
		if(v == u){
			ans.push_back({v , v});
			t[v] ^= 1;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(d[i]) f.push_back(i);
	}
	ll fs = sze(f);
	for(ll i = 0 ; i < fs ; i += 2){
		ed.push_back({f[i] , f[i + 1]});
	}
	m = sze(ed);
	ll ig = -1;
	if(m & 1){
		t[0] ^= 1;
		ans.push_back({0 , 0});
	}
	for(ll i = 0 ; i < m ; i++){
		if(i == ig) continue;
		ll v = ed[i].first , u = ed[i].second;
		if(v == u) continue;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	bDFS(0);
	for(ll i = 0 ; i < n ; i++){
		for(auto v : adj[i]){
			if(dis[v] > dis[i]) continue;
			be[i].push_back({dis[v] , v});
		}
		sort(all(be[i]) , greater<pll>());
		bs[i] = sze(be[i]);
	}
	mark.reset();
	jDFS(0);
	if(ig != -1){
		ans.push_back(ed[ig]);
		ans.push_back({ed[ig].first , ed[ig].first});
	}
	cout<<sze(ans)<<'\n';
	for(auto p : ans){
		cout<<p.first + 1<<' '<<p.second + 1<<'\n';
	}
	return 0;
}