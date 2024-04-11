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

int n;
ll a[N], x1, x2, x3;
ll m1[N], m2[N];
ll mn1[N], mn2[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> x1 >> x2 >> x3;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    m1[0] = a[0];
    for (int i = 1; i < n; ++i)
        m1[i] = max(m1[i-1], a[i]);
    m2[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; --i)
        m2[i] = max(m2[i+1], a[i]);
    mn1[0] = a[0];
    for (int i = 1; i < n; ++i)
        mn1[i] = min(mn1[i-1], a[i]);
    mn2[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; --i)
        mn2[i] = min(mn2[i+1], a[i]);

    ll ans = -3.1e18;
    for (int i = 0; i < n; ++i)
        ans = max(ans, x2*a[i] + x1*(x1 > 0 ? m1 : mn1)[i] + x3*(x3 > 0 ? m2 : mn2)[i]);
    cout << ans << "\n";

    return 0;
}