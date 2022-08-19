//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<ll, ll>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 300005;
int n;
int a[maxn];
int fa[maxn];
int fl[maxn]; // root
int gfa(int a) {
    if (fa[a] == a) return a;
    return fa[a] = gfa(fa[a]);
}
int ok[maxn], hv[maxn];
int t = 1;
int gnx() {
    while (hv[t]) t++;
    return t;
}
vector<pi> rg;

void fillx(int l, int r) {
    for (int j = l; j <= r; j += 2) {
        int cc = gnx();
        a[j] = a[j + 1] = cc;
        hv[cc] = 1;
    }
}
void fillrg(int id, int to) {
    pi cur = rg[id];
    if (to == a[cur.fi - 1]) {
        a[cur.fi] = to;
        fillx(cur.fi + 1, cur.se);
    }
    else {
        a[cur.se] = to;
        fillx(cur.fi, cur.se - 1);
    }
}
namespace mat {

using namespace std;

const int BufL = 1100000;

char buf[BufL], *ins = buf, *outs = buf;

inline int getint()
{
	while (*ins < '0' || *ins > '9')
		++ins;

	int res = 0;
	while (*ins >= '0' && *ins <= '9')
		res = res * 10 + *ins++ - '0';
	return res;
}
inline void putint(int x, char c = ' ')
{
	if (!x)
		*outs++ = '0';
	else
	{
		char s_pool[4], *s = s_pool;
		for (; x; x /= 10)
			*s++ = x % 10 + '0';

		while (s-- != s_pool)
			*outs++ = *s;
	}
	*outs++ = c;
}

const int MaxN = 601;
const int MaxM = MaxN * (MaxN - 1);

int n, m;
int nE, adj[MaxN];
int next[MaxM], go[MaxM];

inline void addEdge(const int &u, const int &v)
{
	next[++nE] = adj[u], go[adj[u] = nE] = v;
	next[++nE] = adj[v], go[adj[v] = nE] = u;
}

int n_matches;
int mate[MaxN];

int q_n;
int q[MaxN];
int book_mark;
int book[MaxN];

int type[MaxN];
int fa[MaxN];
int bel[MaxN];

inline void augment(int u)
{
	while (u)
	{
		int nu = mate[fa[u]];
		mate[mate[u] = fa[u]] = u;
		u = nu;
	}
}

inline int get_lca(int u, int v)
{
	++book_mark;
	while (true)
	{
		if (u)
		{
			if (book[u] == book_mark)
				return u;
			book[u] = book_mark;
			u = bel[fa[mate[u]]];
		}
		swap(u, v);
	}
}

inline void go_up(int u, int v, const int &mv)
{
	while (bel[u] != mv)
	{
		fa[u] = v;
		v = mate[u];
		if (type[v] == 1)
			type[q[++q_n] = v] = 0;
		if (bel[u] == u)
			bel[u] = mv;
		if (bel[v] == v)
			bel[v] = mv;
		u = fa[v];
	}
}
inline void after_go_up()
{
	for (int u = 1; u <= n; ++u)
		bel[u] = bel[bel[u]];
}

inline bool match(const int &sv)
{
	for (int u = 1; u <= n; ++u)
		bel[u] = u, type[u] = -1;
	type[q[q_n = 1] = sv] = 0;

	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (int e = adj[u]; e; e = next[e])
		{
			int v = go[e];
			if (!~type[v])
			{
				fa[v] = u, type[v] = 1;
				int nu = mate[v];
				if (!nu)
				{
					augment(v);
					return true;
				}
				type[q[++q_n] = nu] = 0;
			}
			else if (!type[v] && bel[u] != bel[v])
			{
				int lca = get_lca(u, v);
				go_up(u, v, lca);
				go_up(v, u, lca);
				after_go_up();
			}
		}
	}
	return false;
}

inline void calc_max_match()
{
	n_matches = 0;
	for (int u = 1; u <= n; ++u)
		if (!mate[u] && match(u))
			++n_matches;
}
    vi cal(int x, vector<pi> a) {
        n = x;
        for (auto v : a)
            addEdge(v.fi, v.se);
        calc_max_match();
        vi res(n + 1);
        for (int u = 1; u <= n; u++)
            res[u] = mate[u];
        return res;
    }
}

const int h = 605;
int id[h][h];
int usa[maxn];

vector<pi> neg[maxn]; // to, ind in rg
void ade(int u, int v, int ind) {
    neg[u].pb(mp(v, ind));
    neg[v].pb(mp(u, ind));
}
void dfs(int u, int f) {
    for (auto v : neg[u]) {
        if (v.fi == f) continue;
        fillrg(v.se, v.fi);
        dfs(v.fi, u);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]), hv[a[i]] = 1;
    for (int i = 1; i <= n; i++)
        fa[i] = i, fl[i] = 0;
    for (int i = 1; i <= n; ) {
        if (a[i]) {
            i++;
            continue;
        }
        int j = i;
        while(j <= n && !a[j]) j++;
        rg.pb(mp(i, j - 1));
        i = j;
    }
    vector<pi> nx;
    for (auto v : rg) {
        if (v.fi == 1) {
            while (v.fi + 1 <= v.se) {
                int cc = gnx();
                a[v.fi] = a[v.fi + 1] = cc;
                hv[cc] = 1;
                v.fi += 2;
            }
            if (v.fi == v.se) {
                if (v.fi != n) a[v.fi] = a[v.fi + 1];
                else a[v.fi] = a[v.fi - 1];
            }
        }
        else if (v.se == n) {
            while (v.se - 1 >= v.fi) {
                int cc = gnx();
                a[v.se - 1] = a[v.se] = cc;
                hv[cc] = 1;
                v.se -= 2;
            }
            if (v.fi == v.se)
                a[v.fi] = a[v.fi - 1];
        }
        else nx.pb(v);
    }
    
    for (int i = 1; i <= n; i++) {
        hv[a[i]] = 1;
        if (a[i] == a[i + 1]) fl[a[i]] = a[i];
    } 
    rg = nx;
    for (int i = 0; i < rg.size(); i++) {
        pi v = rg[i];
        int le = v.se - v.fi + 1;
        if (le % 2 == 1) {
            int aa = a[v.fi - 1], b = a[v.se + 1];
            int af = gfa(aa), bf = gfa(b);
            if (af == bf) fl[af] = aa, fillrg(i, aa);
            else {
                fa[af] = bf;
                if (fl[af]) fl[bf] = fl[af];
                ade(aa, b, i);
            }
        }
    }
    #define ar3 array<int, 3>
    vector<array<int, 3> > g;
    vector<pi> ceg;
    for (int i = 0; i < rg.size(); i++) {
        pi v = rg[i];
        int le = v.se - v.fi + 1;
        if (le % 2 == 0) {
            int aa = a[v.fi - 1], b = a[v.se + 1];
            int af = gfa(aa), bf = gfa(b);
            if (fl[af] || fl[bf]) continue;
            g.pb(ar3{af, bf, i});
            ceg.pb(mp(af, bf));
        }
    }
    int dd = min(600, n);
    vi res = mat::cal(dd, ceg);
    for (auto v : g)
        id[v[0]][v[1]] = v[2], id[v[1]][v[0]] = v[2];
    for (int i = 1; i <= dd; i++) {
        if (res[i]) {
            int cid = id[i][res[i]];
            pi v = rg[cid]; int aa = a[v.fi - 1], b = a[v.se + 1];
            if (gfa(b) == i) swap(aa, b);
            dfs(aa, 0);
            usa[id[i][res[i]]] = 1;
        }
        else {
            if (fa[i] == i) {
                if (fl[i]) dfs(fl[i], 0);
                else dfs(i, 0);
            }
        }
    }
    for (int i = 0; i < rg.size(); i++) {
        pi v = rg[i];
        int le = v.se - v.fi + 1;
        if (le % 2 == 0) {
            if (usa[i]) {
                a[v.fi] = a[v.fi - 1], a[v.se] = a[v.se + 1];
                fillx(v.fi + 1, v.se - 1);
            }
            else fillx(v.fi, v.se);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return (0-0); //<3
}