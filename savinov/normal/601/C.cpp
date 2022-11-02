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

void solve(int test) {
#define double long double
    int n = nxt();
    int m = nxt();
    if (m == 1) {
        cout << "1\n";
        return;
    }
    int x[n];
    for (int i = 0; i < n; ++i) x[i] = nxt() - 1;

    int s = accumulate(x, x + n, 0);

    double dp[n * m];
    clr(dp);

    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        double dp2[n * m];
        double sum = 0;
        int k = 0;
        for (int j = 0; j < n * m; ++j) {
            while (k + m <= j) {
                sum -= dp[k];
                ++k;
            }
            assert(j - k < m);
            sum += dp[j];
            dp2[j] = sum;
        }

        for (int j = x[i]; j < n * m; ++j) {
            dp2[j] -= dp[j - x[i]];
        }

        memcpy(dp, dp2, sizeof(dp));
    }

    double c1 = 0;
    for (int i = 0; i < s; ++i) {
        c1 += dp[i];
    }
    double c2 = 0;
    for (int i = 0; i < n * m; ++i) {
        c2 += dp[i];
    }
    cerr << c1 << " " << c2 << "\n";
    cerr << s << "\n";
    cout << setprecision(20) << fixed;
    cout << 1 + (m - 1) * c1 / c2 << "\n";
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

    //test();
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