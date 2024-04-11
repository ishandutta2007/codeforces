#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
}

mt19937 generator;

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}


long long mod = 1000000007;
const int N = 1000001;
vector <int> divisors[N + 1];
int cnt[N + 1];

long long f[N];
long long r[N];
long long fi[N];

void pre() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            cnt[j] += 1;
        }
    }
    int cc = 0;
    for (int i = 1; i < N; ++i) {
        cc += cnt[i];
        divisors[i].reserve(cnt[i]);
    }
    clr(cnt);
    for (int i = N - 1; i >= 1; --i) {
        for (int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
    f[0] = fi[0] = 1;
    r[1] = 1;
    for (int i = 2; i < N; ++i) {
        r[i] = (-mod / i * r[mod % i] % mod + mod) % mod;
    }
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = fi[i - 1] * r[i] % mod;
    }
    cerr << (double)clock() / CLOCKS_PER_SEC << endl;
}

long long bin(int n, int k) {
    if (k > n) return 0;
    return f[n] * fi[n - k] % mod * fi[k] % mod;
}

long long dp[N];

long long delta[N];

long long ans = 0;

int k;

void addNumber(int x) {
    for (int d : divisors[x]) {
        delta[d] %= mod;
        ans -= dp[d] * d;
        cnt[d] += 1;
        long long v = bin(cnt[d], k) - delta[d];
        if (v < 0) {
            v += mod;
        }
        long long dd = v - dp[d];
        if (dd < 0) {
            dd += mod;
        }
        dp[d] = v;
        ans += dp[d] * d;
        ans %= mod;
        for (int q : divisors[d]) {
            if (q != d) {
                delta[q] += dd;
            }
        }
    }
}

void solve(int test) {
    int n = nxt();
    k = nxt();
    int q = nxt();
    ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = nxt();
        addNumber(x);
    }
    //cerr << "A " << ans << "\n";
    for (int i = 0; i < q; ++i) {
        int x = nxt();
        addNumber(x);
        cout << (ans + mod) % mod << "\n";
    }
}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
#ifdef LOCAL

    int t = 1;
#else
    int t = 1;
#endif

    int c = 0;
    while (t--) {
        solve(++c);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}