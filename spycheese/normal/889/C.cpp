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

const int N = 1000179;
int pw(int a, int b) {
    int r = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            r = (1LL*a*r) % MOD;
        a = (1LL*a*a) % MOD;
    }
    return r;
}
int fact[N], ofact[N];

int main() {
    ios::sync_with_stdio(false);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = (1LL*fact[i-1]*i) % MOD;
    ofact[N-1] = pw(fact[N-1], MOD-2);
    for (int i = N - 2; i >= 0; --i)
        ofact[i] = (1LL*ofact[i+1]*(i+1)) % MOD;

    int n, k;
    scanf("%d%d", &n, &k);
    static int d[N], ds[N];
    int ans = 0;
    for (int m = 0; m < n; ++m) {
        if (m <= k)
            d[m] = fact[m];
        else {
            d[m] = (ds[m] - ds[m-k] + MOD) % MOD;
            d[m] = (1LL*fact[m-1]*d[m]) % MOD;
        }
        ds[m+1] = (ds[m] + 1LL*d[m]*ofact[m]) % MOD;

        int nans = d[m];
        nans = (1LL * nans * fact[n-1]) % MOD;
        nans = (1LL * nans * ofact[m]) % MOD;
        ans = (ans + nans) % MOD;
    }
    ans = (fact[n] - ans + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}