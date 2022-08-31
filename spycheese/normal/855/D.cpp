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
const int D = 17;

int n;
vector < ipair > e[N];
int dp[D][N], dep[N];
int c1[N], c2[N];
int comp[N], ccnt;

void dfs(int v, int p = -1, int cdep = 0, int cc1 = 0, int cc2 = 0) {
    c1[v] = cc1;
    c2[v] = cc2;
    dep[v] = cdep;
    comp[v] = ccnt;
    dp[0][v] = p;
    for (int i = 1; i < D; ++i)
        dp[i][v] = (dp[i-1][v] == -1 ? -1 : dp[i-1][dp[i-1][v]]);

    for (ipair nv : e[v]) {
        dfs(nv.X, v, cdep + 1, cc1 + (nv.Y==1), cc2 + (nv.Y==2));
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    int rem = dep[x] - dep[y];
    for (int i = D - 1; i >= 0; --i)
        if (rem & (1 << i))
            x = dp[i][x];
    if (x == y)
        return x;
    for (int i = D - 1; i >= 0; --i) {
        if (dp[i][x] != dp[i][y]) {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, z;
        cin >> p >> z;
        ++z;
        --p;
        if (p >= 0) {
            e[p].push_back({i, z});
        }
    }

    for (int i = 0; i < n; ++i)
        if (!comp[i]) {
            ++ccnt;
            dfs(i);
        }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        --y;
        if (x == y || comp[x] != comp[y]) {
            cout << "NO\n";
            continue;
        }
        int z = lca(x, y);
        if (t == 1) {
            if (z == x && c2[x] == c2[y])
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            if (c2[x] == c2[z] && c1[z] == c1[y] && z != y)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}