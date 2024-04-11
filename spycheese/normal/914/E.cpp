#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 200179;

int n;
vector<int> e[N];
int val[N];
bool deld[N];
ll ans[N];
int ss[N];

int dfs1(int v, int p) {
    int cs = 1;
    for (int i = 0; i < sz(e[v]); ++i) {
        int nv = e[v][i];
        if (nv == p)
            continue;
        if (deld[nv]) {
            e[v][i] = e[v].back();
            e[v].pop_back();
            --i;
            continue;
        }
        cs += dfs1(nv, v);
    }
    return ss[v] = cs;
}

int dfs2(int v, int p, int sb) {
    for (int nv : e[v]) {
        if (nv == p)
            continue;
        int nr = dfs2(nv, v, sb);
        if (nr != -1)
            return nr;
    }
    if (ss[v] * 2 >= sb)
        return v;
    return -1;
}

int cnt[1 << 20];
void dfs3(int v, int p, int cx, int i, int vv) {
    cx ^= val[v];
    cnt[cx] += vv;
    for (int nv : e[v])
        if (nv != p)
            dfs3(nv, v, cx, i, vv);
}

pair<ll,ll> dfs4(int v, int p, int cx, int j) {
    cx ^= val[v];
    ll res = cnt[cx];
    ll res2 = !(cx & (cx-1));
    for (int i = 0; i < 20; ++i)
        res += cnt[cx ^ (1 << i)];
    for (int nv : e[v])
        if (nv != p) {
            auto nres = dfs4(nv, v, cx, j);
            res += nres.X;
            res2 += nres.Y;
        }
    ans[v] += res;
    return {res, res2};
}

void go(int v0) {
    dfs1(v0, -1);
    int root = dfs2(v0, -1, ss[v0]);

    cnt[0] = 1;
    for (int i = 0; i < sz(e[root]); ++i)
        dfs3(e[root][i], root, 0, i, 1);
    ll ra = 0;
    for (int i = 0; i < sz(e[root]); ++i) {
        dfs3(e[root][i], root, 0, i, -1);
        auto r = dfs4(e[root][i], root, val[root], i);
        dfs3(e[root][i], root, 0, i, 1);
        ra += r.X + r.Y;
    }
    ans[root] += ra / 2;

    for (int i = 0; i < sz(e[root]); ++i)
        dfs3(e[root][i], root, 0, i, -1);

    deld[root] = true;
    for (int nv : e[root])
        go(nv);
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    static char sss[N];
    scanf("%s", sss);
    for (int i = 0; i < n; ++i)
        val[i] = (1 << (sss[i] - 'a'));

    for (int i = 0; i < n; ++i)
        ans[i] = 1;

    go(0);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}