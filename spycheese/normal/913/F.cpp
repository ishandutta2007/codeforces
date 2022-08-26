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
const int MOD = 998244353;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 2011;

int pw(int x, int y) {
    int r = 1;
    for (; y; y >>= 1) {
        if (y & 1)
            r = (1LL * r * x) % MOD;
        x = (1LL * x * x) % MOD;
    }
    return r;
}

int n;
int ppow[N*N], p1pow[N*N];
int d1[N][N];
int ssp[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false);

    int n0;
    cin >> n0;
    int pq1, pq2;
    cin >> pq1 >> pq2;
    ppow[0] = 1;
    ppow[1] = (1LL * pq1 * pw(pq2, MOD - 2)) % MOD;
    for (int i = 2; i < N*N; ++i)
        ppow[i] = (1LL * ppow[i-1] * ppow[1]) % MOD;
    p1pow[0] = 1;
    p1pow[1] = (MOD + 1 - ppow[1]) % MOD;
    for (int i = 2; i < N*N; ++i)
        p1pow[i] = (1LL * p1pow[i-1] * p1pow[1]) % MOD;

    d1[0][0] = 1;
    for (int n = 1; n <= n0; ++n) {
        ssp[n] = 1;
        d1[n][0] = 1;
        for (int cnt = 1; cnt <= n; ++cnt) {
            d1[n][cnt] = (1LL * d1[n-1][cnt] * ppow[cnt]) % MOD;
            d1[n][cnt] = (d1[n][cnt] + 1LL * d1[n-1][cnt-1] * p1pow[n-cnt]) % MOD;
            if (cnt != n) {
                ssp[n] = (ssp[n] - 1LL * d1[n][cnt] * ssp[cnt]) % MOD;
                if (ssp[n] < 0)
                    ssp[n] += MOD;
            }
        }
    }

    ans[1] = 0;
    for (int n = 2; n <= n0; ++n) {
        for (int cnt = 1; cnt < n; ++cnt) {
            int ca = cnt * (n - cnt) + cnt*(cnt-1) / 2;
            ca = (1LL*ca + ans[cnt] + ans[n-cnt]) % MOD;
            ca = (1LL * ca * ssp[cnt]) % MOD;
            ans[n] = (ans[n] + 1LL * ca * d1[n][cnt]) % MOD;
        }
        ans[n] = (ans[n] + 1LL*n*(n-1)/2*ssp[n]) % MOD;
        ans[n] = (1LL * ans[n] * pw((MOD+1-ssp[n]) % MOD, MOD - 2)) % MOD;
    }

    std::cout << ans[n0] << "\n";

    return 0;
}