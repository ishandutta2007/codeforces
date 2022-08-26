#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

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
const double PI = acos(-1.0);
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
int w[N];
vector<int> e[N];
int col[N];
int size[N][2];

int ans = 0;

void dfs(int v, int p = -1, int cc = 0) {
    col[v] = cc;
    size[v][cc] = 1;
    for (int i = 0; i < sz(e[v]); ++i) {
        int nv = e[v][i];
        if (nv == p) {
            e[v][i] = e[v].back();
            e[v].pop_back();
            --i;
            continue;
        }
        dfs(nv, v, cc ^ 1);
        size[v][0] += size[nv][0];
        size[v][1] += size[nv][1];
    }
}

void solve(int v, vector<ipair> const& as) {
    ll cnt = 0;
    int sx = 0, sy = 0;
    for (ipair a : as) {
        sx += a.X;
        sy += a.Y;
    }
    cnt += sx*(sx-1LL);
    cnt -= sy*(sy-1LL);
    for (ipair a : as) {
        cnt -= a.X*(a.X-1LL);
        cnt += a.Y*(a.Y-1LL);
    }
    cnt += sx*2 + 1;

    cnt %= MOD;
    ans = (ans + cnt * w[v]) % MOD;
    if (ans < 0)
        ans += MOD;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
        if (w[i] < 0)
            w[i] += MOD;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(0);
    for (int v = 0; v < n; ++v) {
        vector<ipair> a;
        for (int nv : e[v])
            a.push_back({size[nv][col[v]], size[nv][!col[v]]});
        if (v != 0)
            a.push_back({size[0][col[v]] - size[v][col[v]], size[0][!col[v]] - size[v][!col[v]]});
        solve(v, a);
    }

    cout << ans << "\n";

    return 0;
}