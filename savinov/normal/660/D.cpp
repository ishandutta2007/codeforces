#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)

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

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}
long long mod = 1000000007;

long long solve(int m, const string &s) {
    long long dp[s.length() + 1];
    int last[m];
    clr(last);
    dp[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        dp[i] = (dp[i - 1] * 2);
        if (last[s[i - 1] - 'a'] != 0) dp[i] = (dp[i] - dp[last[s[i - 1] - 'a'] - 1]);
        last[s[i - 1] - 'a'] = i;
    }
    return dp[s.length()];
}

long long res = 0;

void rec(int pos, int n, int m, const string & s) {
    if (pos == n) {
        res += solve(m, s);
        return;
    }
    for (int i = 0; i < m; ++i) {
        rec(pos + 1, n, m, s + (char)(i + 'a'));
    }
}

void solve(int test) {
    int n = nxt();
    long long x[n], y[n];

    for (int i = 0; i < n; ++i) {
        x[i] = nxt();
        y[i] = nxt();
    }

    cerr << "OK\n";

    vector <long long> p;

    p.reserve(n * (n - 1) / 2);

    long long M = 2000000001;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long sx = x[i] + x[j];
            long long sy = y[i] + y[j];
            p.push_back(sx * M + sy);
        }
    }

    sort(all(p));

    long long ans = 0;

    for (int i = 0; i < p.size(); ++i) {
        int j = i;
        while (j < p.size() && p[i] == p[j]) {
            ++j;
        }
        ans += (j - i) * (j - i - 1);
        i = j - 1;
    }

    ans /= 2;
    cout << ans << "\n";

}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;

#ifdef LOCAL
#else
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