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

const int N = 1 << 17;

int bin(int a, int b) {
    int r = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            r = (1LL * a * r) % MOD;
        a = (1LL * a * a) % MOD;
    }
    return r;
}
int nr = bin(N, MOD - 2);

void kukarekAnd(int* a) {
    for (int b = 0; b < 17; ++b)
        for (int i = N - 1; i >= 0; --i)
            if (i & (1 << b))
                (a[i ^ (1 << b)] += a[i]) %= MOD;
}
void kukarekAndRev(int* a) {
    for (int b = 16; b >= 0; --b)
        for (int i = 0; i < N; ++i)
            if (i & (1 << b))
                (a[i ^ (1 << b)] += MOD - a[i]) %= MOD;
}

void kukarekXor(int* a) {
    for (int b = 0; b < 17; ++b)
        for (int i = 0; i < N; ++i) {
            if (i & (1 << b))
                continue;
            int j = i ^ (1 << b);
            int x = (a[i] + a[j]) % MOD;
            int y = (a[i] - a[j] + MOD) % MOD;
            a[i] = x;
            a[j] = y;
        }
}
void kukarekXorRev(int* a) {
    for (int b = 0; b < 17; ++b)
        for (int i = 0; i < N; ++i) {
            if (i & (1 << b))
                continue;
            int j = i ^ (1 << b);
            int x = (a[i] + a[j]) % MOD;
            int y = (a[i] - a[j] + MOD) % MOD;
            a[i] = x;
            a[j] = y;
        }
    for (int i = 0; i < N; ++i)
        a[i] = (1LL * a[i] * nr) % MOD;
}

int fib[N];
int a[N];
int a1[N];
int a3[N];
int c[N];

int main() {
    ios::sync_with_stdio(false);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; ++i)
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;

    int nn;
    scanf("%d", &nn);
    for (int i = 0; i < nn; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i; true; (--j) &= i) {
            int x1 = (N-1) ^ i;
            int x2 = j;
            a1[x1 | x2] = (a1[x1 | x2] + 1LL * a[x1] * a[x2]) % MOD;
            if (j == 0)
                break;
        }
    }

    memcpy(a3, a, sizeof(a3));
    kukarekXor(a3);
    for (int i = 0; i < N; ++i)
        a3[i] = (1LL * a3[i] * a3[i]) % MOD;
    kukarekXorRev(a3);

    for (int i = 0; i < N; ++i)
        a[i] = (1LL * a[i] * fib[i]) % MOD;
    for (int i = 0; i < N; ++i)
        a1[i] = (1LL * a1[i] * fib[i]) % MOD;
    for (int i = 0; i < N; ++i)
        a3[i] = (1LL * a3[i] * fib[i]) % MOD;

    kukarekAnd(a);
    kukarekAnd(a1);
    kukarekAnd(a3);
    for (int i = 0; i < N; ++i) {
        c[i] = (1LL * a[i] * a3[i]) % MOD;
        c[i] = (1LL * c[i] * a1[i]) % MOD;
    }
    kukarekAndRev(c);
    int ans = 0;
    for (int i = 1; i < N; i <<= 1) {
        (ans += c[i]) %= MOD;
    }
    cout << ans << "\n";

    return 0;
}