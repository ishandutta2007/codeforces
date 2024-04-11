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
const int X = 10;

int x;
struct DP {
    int d0[X+1], d1[X+1], d2[X+1];
    DP() {
        memset(d0, 0, sizeof(d0));
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
    }
};
int cnt0, cnt2;

int n;
vector < int > e[N];

DP dfs(int v, int p = -1) {
    DP cd;
    cd.d0[0] = cnt0;
    cd.d1[1] = 1;
    cd.d2[0] = cnt2;

    for (int nv : e[v]) {
        if (nv == p)
            continue;
        auto nd = dfs(nv, v);

        DP ncd;
        for (int px = x; px >= 0; --px) {
            for (int cx = 0; cx+px <= x; ++cx) {
                ncd.d0[cx + px] = (ncd.d0[cx+px] + cd.d0[px] * (1LL*nd.d0[cx]+nd.d1[cx]+nd.d2[cx])) % MOD;
                ncd.d1[cx + px] = (ncd.d1[cx+px] + cd.d1[px] * (1LL*nd.d0[cx])) % MOD;
                ncd.d2[cx + px] = (ncd.d2[cx+px] + cd.d2[px] * (1LL*nd.d0[cx]+1LL*nd.d2[cx])) % MOD;
            }
        }
        cd = ncd;
    }

    return cd;
}

int main() {
    ios::sync_with_stdio(false);

    int types;
    cin >> n >> types;
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    int k;
    cin >> k >> x;
    cnt0 = k - 1;
    cnt2 = types - k;

    auto d = dfs(0);
    ll ans = 0;
    for (int y : d.d0)
        ans += y;
    for (int y : d.d1)
        ans += y;
    for (int y : d.d2)
        ans += y;
    cout << ans % MOD << "\n";

    return 0;
}