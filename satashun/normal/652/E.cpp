#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

class unionfind {
    vector<int> par, rank;

    public:
    void init(int n) {
	par.resize(n);
	rank.resize(n);

	for (int i = 0; i < n; i++) {
	    par[i] = i;
	    rank[i] = 0;
	}
    }

    int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return ;

	if (rank[x] < rank[y]) par[x] = y;
	else {
	    par[y] = x;
	    if (rank[x] == rank[y]) ++rank[x];
	}
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
} uf;

const int MX = 300010;

vector<pii> G[MX];
int ord[MX], low[MX];
bool vis[MX];
set<pii> br;

void dfs(int v, int p, int &k)
{
    vis[v] = true;
    ord[v] = low[v] = k++;

    for (pii e : G[v]) {
	if (!vis[e.fi]) {
	    dfs(e.fi, v, k);
	    low[v] = min(low[v], low[e.fi]);
	    if (ord[v] < low[e.fi]) {
		br.insert(mp(v, e.fi));
		br.insert(mp(e.fi, v));
	    }
	}

	else if (e.fi != p) {
	    low[v] = min(low[v], ord[e.fi]);
	}
    }
}

int n, m;
bool art[MX];
vector<int> gg[MX];
set<pii> es;
set<pii> way;

int par[MX];
int s, t;

void dfs2(int v, int p)
{
    par[v] = p;

    for (int to : gg[v]) {
	if (to != p) {
	    dfs2(to, v);
	}
    }
}

int main() {
    cin >> n >> m;

    rep(i, m) {
	int a, b, c;
	cin >> a >> b >> c;
	--a; --b;
	G[a].eb(b, c);
	G[b].eb(a, c);
    }

    cin >> s >> t;
    --s; --t;

    int now = 0;
    dfs(0, -1, now);

    uf.init(n);

    rep(i, n) {
	for (pii e : G[i]) {
	    if (!br.count(mp(i, e.fi))) {
		uf.unite(i, e.fi);
	    }
	}
    }

    rep(i, n) {
	for (pii e : G[i]) {
	    int u = uf.find(i), v = uf.find(e.fi);
	    if (u != v) {
		if (!es.count(mp(u, v))) {
		    gg[u].eb(v);
		    gg[v].eb(u);
		    es.insert(mp(u, v));
		    es.insert(mp(v, u));
		    if (e.se) {
			way.insert(mp(u, v));
			way.insert(mp(v, u));
		    }
		}
	    } else art[u] |= e.se;
	}
    }

    int r = uf.find(s);

    dfs2(r, -1);

    bool ans = 0;
    int cur = uf.find(t);

    while (cur != -1) {
	ans |= art[cur];
	ans |= way.count(mp(cur, par[cur]));
	cur = par[cur];
    }

    puts(ans ? "YES" : "NO");

    return 0;
}