#include <bits/stdc++.h>


#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
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
const long double PI = 3.1415926535897932384626433832795L;

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

mt19937 generator;


long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return pw(a, mod - 2);
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    long long l = nxt<ll>();
    int k = nxt();

    long long numBlocks = l / n;
    long long rem = l % n;

    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] = nxt();
    }
    sort(b, b + n);
    int sz = unique(b, b + n) - b;
    int sum[sz + 1];
    clr(sum);
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b, b + sz, a[i]) - b;
        sum[a[i]] += 1;
    }

//    for (int i = 0; i < sz; ++i) {
//        sum[i + 1] += sum[i];
//    }

    long long dp[sz + 1];
    for (int i = 0; i <= sz; ++i) {
        dp[i] = 1;
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        long long tmp[sz + 1];
        clr(tmp);
        for (int j = 0; j < sz; ++j) {
            tmp[j + 1] += sum[j] * dp[j + 1];
            tmp[j + 1] %= mod;
        }
        dp[0] = 0;
        for (int j = 0; j < sz; ++j) {
            dp[j + 1] = dp[j] + tmp[j + 1];
            dp[j + 1] %= mod;
        }
        int v = i + 1;
        if (v <= numBlocks) {
            ans += (numBlocks - v + 1) % mod * dp[sz];
            ans %= mod;
        }
    }

    cerr << ans << "\n";
    cerr << numBlocks << " " << rem << endl;

    reverse(sum, sum + sz);

    clr(dp);

    for (int i = 0; i < rem; ++i) {
        dp[sz - a[i]] += 1;
    }

    for (int i = 0; i < sz; ++i) {
        dp[i + 1] += dp[i];
    }

    for (int i = 0; i < k; ++i) {
        int v = i;
        if (v <= numBlocks) {
            ans += dp[sz];
            ans %= mod;
        }
        long long tmp[sz + 1];
        clr(tmp);
        for (int j = 0; j < sz; ++j) {
            tmp[j + 1] += sum[j] * dp[j + 1];
            tmp[j + 1] %= mod;
        }
        dp[0] = 0;
        for (int j = 0; j < sz; ++j) {
            dp[j + 1] = dp[j] + tmp[j + 1];
            dp[j + 1] %= mod;
        }
    }

    cout << ans << "\n";






#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}