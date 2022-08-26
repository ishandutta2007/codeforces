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

int n;
int p[N];
vector < int > e[N];
int vis[N];
int dfs(int v) {
    if (vis[v])
        return 0;
    int x = 1;
    vis[v] = 1;
    for (int nv : e[v])
        x += dfs(nv);
    return x;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        p[x] = y;
        e[y].push_back(x);
    }

    int ans = 1;
    for (int i = 0; i < n*2; ++i) {
        if (vis[i])
            continue;
        if (p[i] == i) {
            dfs(i);
        } else if (p[i] == -1) {
            ans = (1LL*ans*dfs(i)) % MOD;
        }
    }

    int zuz = 2;
    for (int i = 0; i < n*2; ++i) {
        if (vis[i])
            continue;
        int v = i;
        while (true) {
            if (vis[v] == zuz) {
                ans = (ans*2LL) % MOD;
                break;
            }
            if (vis[v])
                break;
            vis[v] = zuz;
            v = p[v];
        }
        ++zuz;
    }
    cout << ans << "\n";

    return 0;
}