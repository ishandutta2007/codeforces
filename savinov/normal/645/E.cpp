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

long long solve3(string t, int k) {
    int last[k];
    memset(last, 255, sizeof(last));

    int m = t.length();

    long long dp[m + 1];
    long long sum[m + 1];

    dp[0] = 1;
    sum[0] = 1;

    for (int i = 0; i < m; ++i) {
        dp[i + 1] = sum[i];
        if (last[t[i] - 'a'] != -1) {
            dp[i + 1] += mod - sum[last[t[i] - 'a']];
            dp[i + 1] %= mod;
        }
        sum[i + 1] = (sum[i] + dp[i + 1]) % mod;
        last[t[i] - 'a'] = i;
    }

    return sum[m];
}

long long solve1(int n, int k, string t) {
    int last[k];
    memset(last, 255, sizeof(last));

    int m = t.length();

    long long dp[n + m + 1];
    long long sum[n + m + 1];

    dp[0] = 1;
    sum[0] = 1;

    for (int i = 0; i < m; ++i) {
        dp[i + 1] = sum[i];
        if (last[t[i] - 'a'] != -1) {
            dp[i + 1] += mod - sum[last[t[i] - 'a']];
            dp[i + 1] %= mod;
        }
        sum[i + 1] = (sum[i] + dp[i + 1]) % mod;
        last[t[i] - 'a'] = i;
    }

    for (int i = m; i < m + n; ++i) {
        int pos = min_element(last, last + k) - last;
        dp[i + 1] = sum[i];
        if (last[pos] != -1) {
            dp[i + 1] += mod - sum[last[pos]];
            dp[i + 1] %= mod;
        }
        sum[i + 1] = (sum[i] + dp[i + 1]) % mod;
        last[pos] = i;
    }

    return sum[m + n];
}

long long res;

void rec(string t, int n, int k) {
    if (n == 0) {
        res = max(res, solve3(t, k));
        return;
    }

    for (int i = 0; i < k; ++i) {
        rec(t + (char)('a' + i), n - 1, k);
    }
}

void stress() {
    int it = 100000;
    while (it--) {
        int n = rand() % 3;
        int m = rand() % 4;
        int k = rand() % 4 + 1;
        string z;

        for (int i = 0; i < m; ++i) {
            z += (char)(rand() % k + 'a');
        }

        res = 0;

        rec(z, n, k);
        //cerr << res << " " << solve1(n, k, z) << "\n";
        assert(res == solve1(n, k, z));
    }
}

void solve(int test) {
    int n = nxt();
    int k = nxt();

    string t;
    cin >> t;

    cout << solve1(n, k, t) << "\n";
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
    stress();
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