#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll { ll first , second , third; };
typedef pair<int , pii> piii;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 1e16;
// check problem statement

vector<pii> adj[MAXN] , emd;
vector<int> tdj[MAXN] , cdj[MAXN];
int c[MAXN] , cc[MAXN] , x = 0 , y = 0 , st[MAXN] , ft[MAXN] , nt[MAXN] , xt[MAXN] , par[MAXN] , tme = 0 , jad[MAXN][20] , dis[MAXN] , dep = 0 , a[MAXN] , b[MAXN];
bitset<MAXN> mark , em , tree , zero;
bool ans = true;

void tDFS(int r){
	st[r] = tme++;
	mark[r] = true;
	for(auto p : adj[r]){
		int i = p.first;
		if(mark[i]) continue;
		tdj[r].push_back(i);
		par[i] = p.second;
		tDFS(i);
	}
	ft[r] = tme;
	return;
}

void eDFS(int r , int pr){
	mark[r] = true;
	for(auto i : tdj[r]){
		eDFS(i , r);
	}
	nt[r] = st[r];
	xt[r] = st[r];
	for(auto i : tdj[r]){
		nt[r] = min(nt[r] , nt[i]);
		xt[r] = max(xt[r] , xt[i]);
	}
	for(auto p : adj[r]){
		int i = p.first , ind = p.second;
		if(ind == par[r]) continue;
		nt[r] = min(nt[r] , st[i]);
		xt[r] = max(xt[r] , st[i]);
	}
	if(pr == -1) return;
	if(nt[r] >= st[r] && xt[r] < ft[r]){
		em[par[r]] = true;
		emd.push_back({r , pr});
	}
	return;
}

void cDFS(int r){
	mark[r] = true;
	c[r] = x;
	for(auto p : adj[r]){
		int i = p.first , ind = p.second;
		if(mark[i] || em[ind]) continue;
		cDFS(i);
	}
	return;
}

void fDFS(int r){
	dis[r] = dep++;
	mark[r] = true;
	cc[r] = y;
	for(int j = 1 ; j < 20 ; j++){
		if(jad[r][j - 1] == -1) break;
		jad[r][j] = jad[jad[r][j - 1]][j - 1];
	}
	for(auto i : cdj[r]){
		if(i == jad[r][0]) continue;
		jad[i][0] = r;
		fDFS(i);
	}
	dep--;
	return;
}

void dDFS(int r){
	mark[r] = true;
	for(auto i : cdj[r]){
		if(i == jad[r][0]) continue;
		dDFS(i);
	}
	for(auto i : cdj[r]){
		if(i == jad[r][0]) continue;
		a[r] += a[i];
		b[r] += b[i];
	}
	if(a[r] > 0 && b[r] > 0) ans = false;
	return;
}

int find_jad(int v , int d){
	for(int j = 0 ; j < 20 ; j++){
		if(d & 1){
			v = jad[v][j];
		}
		d /= 2;
	}
	return v;
}

int LCA(int v , int u){
	if(v == u) return v;
	for(int j = 19 ; j >= 0 ; j--){
		if(jad[v][j] != jad[u][j]){
			v = jad[v][j];
			u = jad[u][j];
		}
	}
	return jad[v][0];
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(jad , -1 , sizeof(jad));
	memset(a , 0 , sizeof(a));
	memset(b , 0 , sizeof(b));
	int n , m , q;
	cin>>n>>m>>q;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin>>v>>u; v--; u--;
		adj[v].push_back({u , i}); adj[u].push_back({v , i});
	}
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		par[i] = -1;
		tDFS(i);
	}
	mark &= zero;
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		eDFS(i , -1);
	}
	mark &= zero;
	for(int i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		cDFS(i);
		x++;
	}
	for(auto p : emd){
		int v = c[p.first] , u = c[p.second];
		cdj[v].push_back(u); cdj[u].push_back(v);
	}
	mark &= zero;
	for(int i = 0 ; i < x ; i++){
		if(mark[i]) continue;
		fDFS(i);
		y++;
	}
	for(int i = 0 ; i < q ; i++){
		int v , u , h , o , l;
		cin>>v>>u; v--; u--; v = c[v]; u = c[u];
		if(cc[v] != cc[u]){
			cout<<"No\n";
			return 0;
		}
		if(dis[v] > dis[u]){
			h = find_jad(v , dis[v] - dis[u]);
			o = u;
		} else {
			h = find_jad(u , dis[u] - dis[v]);
			o = v;
		}
		l = LCA(h , o);
		a[v]++;
		a[l]--;
		b[u]++;
		b[l]--;
	}
	mark &= zero;
	for(int i = 0 ; i < x ; i++){
		if(mark[i]) continue;
		dDFS(i);
	}
	cout<<(ans ? "Yes\n" : "No\n");
	return 0;
}

/*

*/