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

const int N = 100179;

ll solve(ll la, ll t1a, ll ta, ll lb, ll t1b, ll tb) {
    ll sa = ((lb - la) % ta + ta) % ta;
    ll shift = gcd(ta, tb);
    sa %= shift;
    if (sa >= t1a)
        return 0;
    return min(t1a - sa, t1b);
}

int main() {
    ios::sync_with_stdio(false);

    ll la, t1a, ta;
    cin >> la >> t1a >> ta;
    t1a = t1a - la + 1;
    ll lb, t1b, tb;
    cin >> lb >> t1b >> tb;
    t1b = t1b - lb + 1;

    cout << max(
        solve(la, t1a, ta, lb, t1b, tb),
        solve(lb, t1b, tb, la, t1a, ta)
    ) << "\n";


    return 0;
}