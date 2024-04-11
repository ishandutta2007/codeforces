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

const int N = 31;

ll c[N];

int main() {
    ios::sync_with_stdio(false);

    memset(c, 0x3f, sizeof(c));
    int n;
    ll w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 1; i < N; ++i)
        c[i] = min(c[i], c[i-1]*2);

    ll ans = LINF;
    bool was = false;
    for (int j = 0; j < N; ++j) {
        if ((w & (1 << j))) {
            if (was)
                continue;
            was = true;
        }
        ll cans = 0;
        for (int i = N - 1; i >= j; --i)
            if (i == j || (w & (1LL << i)))
                cans += c[i];
        ans = min(ans, cans);
    }

    std::cout << ans << "\n";
    return 0;
}