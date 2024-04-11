#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

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

int n, m;
vector < int > e[N], en[N];
vector < int > edir[N];
bool vis[N], vis2[N];
bool bad[N], flag[N];
vector < int > bads;

void dfs1(int v) {
    if (vis[v])
        return;
    vis[v] = true;
    if (bad[v])
        bads.push_back(v);
    for (int nv : e[v])
        dfs1(nv);
}

bool dfs2(int v) {
    if (vis2[v])
        return false;
    vis2[v] = true;
    bool res = flag[v];
    for (int i = 0; i < sz(e[v]); ++i) {
        int nv = e[v][i];
        bool d = dfs2(nv);
        if (d) {
            res ^= 1;
            edir[v][i] ^= 1;
            edir[nv][en[v][i]] ^= 1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        en[x].push_back(sz(e[y]));
        en[y].push_back(sz(e[x]));
        e[x].push_back(y);
        edir[x].push_back(1);
        e[y].push_back(x);
        edir[y].push_back(0);
        bad[y] ^= 1;
    }

    for (int v0 = 0; v0 < n; ++v0) {
        if (vis[v0])
            continue;
        bads.clear();
        dfs1(v0);
        if (sz(bads) % 2 == 1)
            bads.pop_back();
        for (int x : bads)
            flag[x] = true;
        dfs2(v0);
    }

    struct Triple {
        int x, y, z;
    };
    vector < Triple > ans;
    for (int v = 0; v < n; ++v) {
        vector < int > v1;
        for (int i = 0; i < sz(e[v]); ++i)
            if (edir[v][i] == 0)
                v1.push_back(e[v][i]);
        if (sz(v1) % 2 == 1)
            v1.pop_back();
        for (int i = 0; i < sz(v1); i += 2)
            ans.push_back({v1[i], v, v1[i+1]});
    }

    cout << sz(ans) << "\n";
    for (Triple t : ans)
        cout << t.x+1 << " " << t.y+1 << " " << t.z+1 << "\n";

    return 0;
}