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

bool bld[14];

int main() {
    ios::sync_with_stdio(false);

    ll h, m, s;
    cin >> h >> m >> s;
    h %= 12;

    bld[h] = true;
    bld[m / 5] = true;
    bld[s / 5] = true;

    int t1, t2;
    cin >> t1 >> t2;
    t1 %= 12;
    t2 %= 12;

    int i = t1;
    while (true) {
        if (i == t2) {
            cout << "YES\n";
            return 0;
        }
        if (bld[i])
            break;
        (++i) %= 12;
    }
    i = t1;
    while (true) {
        if (i == t2) {
            cout << "YES\n";
            return 0;
        }
        (i += 11) %= 12;
        if (bld[i])
            break;
    }
    cout << "NO\n";

    return 0;
}