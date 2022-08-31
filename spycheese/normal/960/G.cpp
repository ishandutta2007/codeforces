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

const int D = 18;
const int N = 1 << D;
const int MOD = 998244353;
const int W = 841431251;

int pw(int x, int y) {
    int r = 1;
    for (; y; y >>= 1) {
        if (y & 1)
            r = (1LL*r*x) % MOD;
        x = (1LL*x*x) % MOD;
    }
    return r;
}

int w[N];
int perm[N];
void fftInit() {
    w[0] = 1;
    for (int i = 1; i < N; ++i) {
        w[i] = (1LL * W * w[i-1]) % MOD;
    }

    perm[0] = 0;
    int cb = 0;
    for (int i = 1; i < N; ++i) {
        if (!(i & (1 << cb)))
            ++cb;
        perm[i] = perm[i ^ (1 << cb)] ^ (1 << (D-1-cb));
    }
}

void fft(int *a) {
    for (int i = 0; i < N; ++i)
        if (perm[i] < i)
            swap(a[i], a[perm[i]]);

    for (int n = 2; n <= N; n *= 2) {
        for (int s = 0; s < N; s += n) {
            for (int i = s; i < s + n / 2; ++i) {
                int f1 = a[i];
                int f2 = (1LL * a[i + n / 2] * w[N / n * (i-s)]) % MOD;
                a[i] = f1 + f2;
                if (a[i] >= MOD)
                    a[i] -= MOD;
                a[i+n/2] = f1 - f2;
                if (a[i+n/2] < 0)
                    a[i+n/2] += MOD;
            }
        }
    }
}

void sqr(int *a) {
    int ni = pw(N, MOD - 2);
    for (int i = 0; i < N; ++i) {
        a[i] = a[i] * 1LL * a[i] % MOD;
        a[i] = 1LL * a[i] * ni % MOD;
    }
    reverse(a + 1, a + N);
    fft(a);
}

int lpows[D][N];

void mul(int *a, int *b) {
    fft(a);
    int ni = pw(N, MOD - 2);
    for (int i = 0; i < N; ++i) {
        a[i] = a[i] * 1LL * b[i] % MOD;
        a[i] = 1LL * a[i] * ni % MOD;
    }
    reverse(a + 1, a + N);
    fft(a);
}

const int M = 100111;

void mpow(int b, int *r) {
    memset(r, 0, sizeof(int) * N);
    r[0] = 1;
    int cur = 0;
    for (; b; b >>= 1) {
        if (b & 1) {
            mul(r, lpows[cur]);
            memset(r + M, 0, sizeof(int) * (N - M));
        }
        ++cur;
    }
}

int fact[N], ofact[N];
void calc(int a, int *r) {
    mpow(a, r);
    for (int i = 0; i < M; ++i)
        r[i] = r[i] * 1LL * ofact[a] % MOD;
    for (int i = 0; i < M; ++i)
        r[i] = 1LL * r[i] * fact[i] % MOD;
}


int main() {
    fftInit();
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    ofact[N - 1] = pw(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        ofact[i] = 1LL * ofact[i + 1] * (i + 1) % MOD;

    lpows[0][0] = 0;
    for (int i = 1; i < M; ++i)
        lpows[0][i] = 1LL * fact[i - 1] * ofact[i] % MOD;
    for (int i = 0; i < D; ++i) {
        if (i != 0) {
            fft(lpows[i]);
            sqr(lpows[i]);
            memset(lpows[i] + M, 0, sizeof(int) * (N - M));
        }
        if (i != D - 1)
            memcpy(lpows[i+1], lpows[i], sizeof(int) * N);
        fft(lpows[i]);
    }

    int n, a, b;
    cin >> n >> a >> b;
    if (a == 0 || b == 0) {
        cout << "0\n";
        return 0;
    }
    static int pa[N], pb[N];
    calc(a - 1, pa);
    calc(b - 1, pb);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cans = fact[n - 1];
        cans = 1LL * cans * ofact[i] % MOD;
        cans = 1LL * cans * ofact[n-1-i] % MOD;
        cans = 1LL * cans * pa[i] % MOD;
        cans = 1LL * cans * pb[n-1-i] % MOD;
        ans = (ans + cans) % MOD;
    }
    cout << ans << "\n";

    return 0;
}