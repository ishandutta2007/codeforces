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

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int k1, k2;
    cin >> k1 >> k2;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] -= x;
    }
    for (int i = 0; i < n; ++i)
        a[i] = abs(a[i]);

    for (int i = 0; i < k1 + k2; ++i) {
        auto j = max_element(all(a));
        if (*j)
            --*j;
        else
            ++*j;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i]*a[i];
    cout << ans << "\n";

    return 0;
}