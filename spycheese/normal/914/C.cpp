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

const int N = 1024;

string ns;
int cnt[N], n[N];
int cnk[N][N];

int solve(int k) {
    int ans = 0;
    for (int i = N - 1; k >= 0 && i >= 0; --i)
        if (n[i] == 1) {
            (ans += cnk[i][k]) %= MOD;
            --k;
        }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < N; ++i) {
        cnk[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            cnk[i][j] = (cnk[i-1][j-1] + cnk[i-1][j]) % MOD;
    }

    int k;
    cin >> ns >> k;
    for (int i = 0; i < sz(ns); ++i)
        n[sz(ns)-i-1] = ns[i] - '0';
    for (int i = 0; i < N; ++i) {
        n[i] ^= 1;
        if (n[i] == 1)
            break;
    }

    if (k > 5) {
        cout << "0\n";
        return 0;
    }
    if (k == 0) {
        cout << "1\n";
        return 0;
    }

    for (int i = 2; i < N; ++i)
        cnt[i] = cnt[__builtin_popcount(i)] + 1;
    int ans = 0;
    for (int i = 1; i < N; ++i)
        if (cnt[i] == k - 1)
            (ans += solve(i)) %= MOD;
    if (k == 1) {
        (ans += MOD - 1) %= MOD;
    }
    cout << ans << "\n";


    return 0;
}