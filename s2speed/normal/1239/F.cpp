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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll n , m;
vector<ll> adj[maxn] , bfs , v;
ll d[maxn] , dis[maxn] , par[maxn] , c[maxn] , o , rt[maxn];
bitset<maxn> mark , mrk;
ll s;

void BFS(ll r){
	bfs.clear();
	dis[r] = 0; par[r] = -1;
	bfs.push_back(r);
	ll x = 0;
	while(x < sze(bfs)){
		ll v = bfs[x++];
		for(auto i : adj[v]){
			if(i == s) continue;
			if(dis[i] != inf) continue;
			dis[i] = dis[v] + 1;
			bfs.push_back(i);
			par[i] = v;
		}
	}
	return;
}

void dor(){
	ll x = 1 , a = -1 , b , sz = sze(bfs);
	for(ll c = 1 ; x < sz ; c++){
		v.clear();
		for(ll e = x ; true ; e++){
			if(e == sz){
				x = sz;
				break;
			}
			ll i = bfs[e];
			if(dis[i] == c + 1){
				x = e;
				break;
			}
			v.push_back(i);
		}
		for(auto i : v){
			for(auto j : adj[i]){
				if(dis[j] == c){
					a = i;
					b = j;
					break;
				}
			}
			if(a != -1) break;
		}
		if(a != -1){
			while(a != b){
				mark[a] = mark[b] = true;
				a = par[a]; b = par[b];
			}
			mark[a] = true;
			return;
		}
		for(auto i : v){
			for(auto j : adj[i]){
				if(dis[j] == c + 1 && par[j] != i){
					a = i; b = j;
					break;
				}
			}
			if(a != -1) break;
		}
		if(a != -1){
			mark[b] = true; b = par[b];
			while(a != b){
				mark[a] = mark[b] = true;
				a = par[a]; b = par[b];
			}
			mark[a] = true;
			return;
		}
	}
	return;
}

void DFS(ll r , ll par){
	mark[r] = true;
	for(auto i : adj[r]){
		if(i == par || i == s) continue;
		DFS(i , r);
	}
	return;
}

void solve(){
	v.clear(); s = -1;
	cin>>n>>m;
	fill(c , c + n , -1);
	for(ll i = 0 ; i < n ; i++){
		adj[i].clear(); mark[i] = mrk[i] = false; dis[i] = inf;
	}
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	if(n == 1){
		cout<<"No\n";
		return;
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		d[i] = sze(adj[i]) % 3;
		if(d[i] == 0){
			cout<<"Yes\n"<<n - 1<<'\n';
			for(ll j = 0 ; j < n ; j++){
				if(j == i) continue;
				cout<<j + 1<<' ';
			}
			cout<<'\n';
			return;
		}
		cnt += (d[i] == 1);
	}
	if(cnt >= 2){
		ll r;
		for(ll i = 0 ; i < n ; i++){
			if(d[i] == 1){
				BFS(i);
				r = i;
				break;
			}
		}
		ll h;
		for(ll e = 1 ; e < n ; e++){
			ll i = bfs[e];
			if(d[i] == 1){
				h = i;
				break;
			}
		}
		ll cnt = 0;
		while(h != -1){
			mark[h] = true;
			h = par[h];
			cnt++;
		}
		if(cnt == n){
			cout<<"No\n";
			return;
		}
		cout<<"Yes\n"<<n - cnt<<'\n';
		for(ll i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			cout<<i + 1<<' ';
		}
		cout<<'\n';
		return;
	}
	if(cnt == 0){
		BFS(0);
		dor();
		ll cnt = 0;
		for(ll i = 0 ; i < n ; i++){
			cnt += !mark[i];
		}
		if(cnt == 0){
			cout<<"No\n";
			return;
		}
		cout<<"Yes\n"<<cnt<<'\n';
		for(ll i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			cout<<i + 1<<' ';
		}
		cout<<'\n';
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		if(d[i] == 1){
			s = i;
			break;
		}
	}
	o = 0;
	mrk[s] = true;
	for(ll r = 0 ; r < n ; r++){
		if(mrk[r]) continue;
		BFS(r);
		dor();
		ll cnt = 0;
		for(auto i : bfs){
			mrk[i] = true;
			c[i] = o;
			cnt += mark[i];
		}
		rt[o++] = r;
		if(cnt != 0){
			cout<<"Yes\n"<<n - cnt<<'\n';
			for(ll i = 0 ; i < n ; i++){
				if(mark[i]) continue;
				cout<<i + 1<<' ';
			}
			cout<<'\n';
			return;
		}
		for(auto i : bfs){
			mark[i] = false; dis[i] = inf;
		}
	}
	if(o > 2){
		cout<<"Yes\n";
		ll cnt = 0;
		for(ll i = 0 ; i < n ; i++){
			cnt += (c[i] >= 2);
		}
		cout<<cnt<<'\n';
		for(ll i = 0 ; i < n ; i++){
			if(c[i] >= 2){
				cout<<i + 1<<' ';
			}
		}
		cout<<'\n';
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		if(i == s) continue;
		if(sze(adj[i]) > 3){
			ll cnt = 0;
			for(auto j : adj[i]){
				if(j == s) continue;
				DFS(j , i);
				cnt++;
				if(cnt == 3) break;
			}
			cnt = 0;
			for(ll j = 0 ; j < n ; j++){
				cnt += mark[j];
			}
			cout<<"Yes\n"<<cnt<<'\n';
			for(ll j = 0 ; j < n ; j++){
				if(mark[j]){
					cout<<j + 1<<' ';
				}
			}
			cout<<'\n';
			return;
		}
	}
	cout<<"No\n";
	return;
}

/*
1
13 20
2 3
2 4
4 5
4 6
4 7
5 8
5 9
5 10
5 11
1 3
1 4
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
12 13
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}