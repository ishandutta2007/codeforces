#include<bits/stdc++.h>

#define pb emplace_back
#define sz(a) ((int)a.size())
#define x first
#define y second
#define bpt(x) (__builtin_popcount(x))
#define bit(x, y) (((x)>>(y))&1)
#define bclz(x) (__builtin_clz(x))
#define bctz(x) (__builtin_ctz(x))

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<INT, int> pii;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

int n, m, s;
struct DomiTree{
	
	static const int maxN = 200111;
	int parent[maxN], label[maxN], cnt, who[maxN];
	int semi[maxN], idom[maxN], ancestor[maxN], best[maxN];
	vector<int> edge[maxN], succ[maxN], pred[maxN];
	deque<int> bucket[maxN];
	 
	void dfs(int u) {
	  label[u] = ++cnt; who[cnt] = u;
	  for (vector<int>::iterator it = edge[u].begin(); it != edge[u].end(); ++it) {
	    int v = *it;
	    if (v == parent[u] || label[v] != -1) continue;
	    parent[v] = u;
	    dfs(v);
	  }
	}
	 
	void link(int v, int w) {
	  ancestor[w] = v;
	}
	 
	void compress(int v) {
	  int a = ancestor[v];
	  if (ancestor[a] == 0) return;
	  compress(a);
	  if (semi[best[v]] > semi[best[a]]) best[v] = best[a];
	  ancestor[v] = ancestor[a];
	}
	 
	 VI adj[maxN];
	 
	int eval(int v) {
	  if (ancestor[v] == 0) return v;
	  compress(v);
	  return best[v];
	}
	 
	void dominator() {
	  cnt = 0;
	  for (int i = 1; i <= n; ++i) {
	    label[i] = -1;
	    succ[i].clear(), pred[i].clear();
	  }
	  dfs(s); // n is root
	  for (int u = 1; u <= n; ++u) {
	    for (vector<int>::iterator it = edge[u].begin(); it != edge[u].end(); ++it) {
	      int v = *it;
	      if (label[u] != -1 && label[v] != -1) {
	        succ[label[u]].push_back(label[v]);
	        pred[label[v]].push_back(label[u]);
	      }
	    }
	  }
	  for (int i = 1; i <= n; ++i) {
	    semi[i] = best[i] = i;
	    idom[i] = ancestor[i] = 0;
	    bucket[i].clear();
	  }
	  for (int w = cnt; w >= 2; --w) {
	    int p = label[parent[who[w]]];
	    for (vector<int>::iterator it = pred[w].begin(); it != pred[w].end(); ++it) {
	      int v = *it;
	      int u = eval(v);
	      if (semi[w] > semi[u]) semi[w] = semi[u];
	    }
	    bucket[semi[w]].push_back(w);
	    link(p, w);
	    while (!bucket[p].empty()) {
	      int v = bucket[p].front();
	      bucket[p].pop_front();
	      int u = eval(v);
	      idom[v] = (semi[u] < p ? u : p);
	    }
	  }
	  for (int w = 2; w <= cnt; ++w) {
	    if (idom[w] != semi[w]) idom[w] = idom[idom[w]];
	  }
	  idom[1] = 0;
	  for (int i = 1; i <= cnt; ++i) {
	    int u = who[idom[i]], v = who[i];
	    if(u) adj[u].pb(v);
	    // u is immediate dominator of v (i == 1?)
	  }
	}
	
	int son[maxN];
	int solve(int u) {
		son[u] = 1;
		int ans = 0;
		for(int v : adj[u]) {
			solve(v);
			son[u]+=son[v];
			smax(ans, son[v]);
		}
		return ans;
	}
} dt;

#define NN 200011
#define INF 0x3f3f3f3f3f3f3f3fLL
vector<pii> adj[NN];
INT dst[NN];
set<pii> ss;

void dijkstra() {
	for(int i=1; i<=n; i++) {
		dst[i] = INF;
		if(i==s) dst[i]=0;
		ss.insert(pii(dst[i], i));
	}
	for(int i=0; i<n; i++) {
		int u=ss.begin()->y;
		ss.erase(ss.begin());
		for(pii &tmp : adj[u]) {
			int v=tmp.x;
			if(dst[v] > dst[u] + tmp.y) {
				ss.erase(pii(dst[v], v));
				ss.insert(pii(dst[v]=dst[u]+tmp.y, v));
			}
		}
	}
}


int solve() {
	cin >> n >> m >> s;
	for(int i=0; i<m; i++) {
		int u, v, w; gn(u); gn(v); gn(w);
		adj[u].pb(v, w);
		adj[v].pb(u, w);
	}
	dijkstra();
	for(int i=1; i<=n; i++) {
		for(pii &tmp : adj[i]) {
			int v=tmp.x;
			if(dst[v] == dst[i] + tmp.y) dt.edge[i].pb(v);
		}
	}
	dt.dominator();
	println(dt.solve(s));
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}