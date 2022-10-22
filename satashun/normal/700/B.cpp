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

const int MX = 200010;

int n, k;
ll ret;
int par[MX];
int vs[MX];
int u[MX];
int dep[MX];
vi g[MX];
int pp[19][MX];

void dfs(int v, int p, int d, int &now)
{
    vs[v] = now++;
    par[v] = p;
    dep[v] = d;

    for (int to : g[v]) if (to != p) {
	dfs(to, v, d + 1, now);
    }
}

int lca(int u, int v)
{
    if (dep[u] > dep[v]) swap(u, v);

    for (int i = 18; i >= 0; --i) {
	if (((dep[v] - dep[u]) >> i) & 1) v = pp[i][v];
    }

    if (u == v) return u;

    for (int i = 18; i >= 0; --i) {
	if (pp[i][u] != pp[i][v]) {
	    u = pp[i][u];
	    v = pp[i][v];
	}
    }

    return pp[0][u];
}

int main() {
    scanf("%d %d", &n, &k);

    rep(i, k * 2) {
	scanf("%d", &u[i]);
	--u[i];
    }

    rep(i, n - 1) {
	int a, b;
	scanf("%d %d", &a, &b);
	--a; --b;
	g[a].pb(b);
	g[b].pb(a);
    }

    int now = 0;
    dfs(0, -1, 0, now);

    rep(i, n) pp[0][i] = par[i];

    rep(i, 18) {
	rep(j, n) {
	    pp[i + 1][j] = (pp[i][j] == -1 ? -1 : pp[i][pp[i][j]]);
	}
    }

    vector<pii> vec(k * 2);

    rep(i, k * 2) vec[i] = mp(vs[u[i]], u[i]);
    sort(ALL(vec));

    rep(i, k) {
	int u = vec[i].se, v = vec[i + k].se;

	ll t = dep[u] + dep[v] - 2 * dep[lca(u, v)];
	ret += t;
    }

    cout << ret << endl;

    return 0;
}