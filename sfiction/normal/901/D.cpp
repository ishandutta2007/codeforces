#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int N = 1E5 + 10, M = 1E5 + 10;

int n, m;
vector<pii> E[N];
int dep[N];
pii fa[N];
vector<int> adj;

int mark[M], vis[N];

ll c[N], val[M];

void DFS(int u){
	vis[u] = true;
	for (auto &x: E[u]){
		if (mark[x.nd])
			continue;
		mark[x.nd] = true;
		int v = x.st;
		if (vis[v]){
			if (dep[u] - dep[v] + 1 & 1)
				adj = {u, v, x.nd};
		}
		else{
			dep[v] = dep[u] + 1;
			fa[v] = {u, x.nd};
			DFS(v);
			c[u] -= val[x.nd] = c[v];
			c[v] = 0;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", c + i);
	for (int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].emplace_back(v, i);
		E[v].emplace_back(u, i);
	}
	dep[1] = 0;
	DFS(1);

	if (adj.size()){
		int t = (dep[adj[1]] & 1 ? -1 : 1) * c[1] >> 1;
		val[adj[2]] = t;
		for (int u = adj[0]; u != 1; u = fa[u].st){
			if (u == adj[1])
				t <<= 1;
			val[fa[u].nd] += (t = -t);
		}
		c[1] = 0;
	}
	if (c[1])
		puts("NO");
	else{
		puts("YES");		
		for (int i = 0; i < m; ++i)
			printf("%lld\n", val[i]);
	}
	return 0;
}