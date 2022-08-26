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

const int N = 100179;

int n, m;
vector<ipair> e[N];
vector<int> e1[N];
int col[N];
int pred[N];
int predI[N];
ll c[N];
vector<ipair> edges;
ll ans[N];

void dfs(int v, int cc, int p = -1, int pi = -1) {
    if (col[v] != -1)
        return;
    col[v] = cc;
    pred[v] = p;
    predI[v] = pi;
    if (p != -1)
        e1[p].push_back(v);
    for (ipair nv : e[v])
        dfs(nv.X, cc ^ 1, v, nv.Y);
}

void dfs2(int v) {
    for (int nv : e1[v]) {
        dfs2(nv);
        ll x = c[nv];
        ans[predI[nv]] += x;
        c[nv] -= x;
        c[v] -= x;
    }
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &c[i]);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
        edges.push_back({x, y});
    }
    memset(col, -1, sizeof(col));
    dfs(0, 0, -1);

    ll sum[2] = {0, 0};
    for (int i = 0; i < n; ++i)
        sum[col[i]] += c[i];
    if ((sum[0] - sum[1]) % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    if (sum[0] != sum[1]) {
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            int x = edges[i].X;
            int y = edges[i].Y;
            if (col[x] == col[y]) {
                ok = true;
                ans[i] = (sum[col[x]] - sum[col[x]^1]) / 2;
                c[x] -= ans[i];
                c[y] -= ans[i];
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return 0;
        }
    }

    dfs2(0);

    cout << "YES\n";
    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";

    return 0;
}