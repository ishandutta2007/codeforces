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

const int N = 100179;

int n;
ipair a[N];
vector < int > e[N];
vector < vector < int > > ans;
bool vis[N];
void dfs(int v) {
    if (vis[v])
        return;
    ans.back().push_back(v);
    vis[v] = 1;
    for (int x : e[v])
        dfs(x);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].X);
        a[i].Y = i;
    }

    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        e[i].push_back(a[i].Y);
        e[a[i].Y].push_back(i);
    }

    for (int i = 0; i < n; ++i)
        if (!vis[i]) {
            ans.push_back(vector<int>());
            dfs(i);
        }
    cout << sz(ans) << "\n";
    for (auto&xx:ans) {
        sort(xx.begin(), xx.end());
        cout << sz(xx);
        for (int x : xx)
            cout << " " << x+1;
        cout << "\n";
    }

    return 0;
}