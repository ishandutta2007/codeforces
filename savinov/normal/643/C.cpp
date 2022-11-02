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
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

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

struct Line {
    ld m, b;

    ld eval(ld x) {
        return m * x + b;
    }
};


ld comp(Line a, Line b, Line c) {
    return (b.m - a.m) * (c.b - a.b) + (b.b - a.b) * (a.m - c.m);
}
ld inf = 1e40;

struct Hull {
    vector <Line> lines;
    int ptr;
    Hull() {
        ptr = 0;
    }
    void add(const Line &line) {
        //if (!lines.empty()) assert(line.m > lines.back().m || (line.m == lines.back().m && line.b < /* < for minima */ lines.back().b));
        while (lines.size() >= 2 && comp(lines[lines.size() - 2], lines[lines.size() - 1], line) >= 0 /* <= 0 for minima */) {
            lines.pop_back();
        }
        lines.push_back(line);
    }

    ld eval(ld x) {

        if (lines.empty()) return -inf;
        ptr = min(ptr, (int)lines.size() - 1);
        while (ptr + 1 < lines.size() && lines[ptr].eval(x) < lines[ptr + 1].eval(x)) {
            ++ptr;
        }
        return lines[ptr].eval(x);
    }
};

void solve(int test) {
    int n = nxt();
    int k = nxt();

    ll a[n];
    forn(i, n) a[i] = nxt();

    ll s[n + 1];
    s[0] = 0;
    forn(i, n) {
        s[i + 1] = s[i] + a[i];
    }

    ld x[n + 1];
    x[0] = 0;

    ld y[n + 1];
    y[0] = 0;

    forn(i, n) {
        x[i + 1] = x[i] + 1.0L * s[i + 1] / a[i];
        y[i + 1] = y[i] + 1.0L / a[i];
    }

    cerr << (x[1] - x[0] - s[0] * (y[1] - y[0])) << "\n";
    cerr << (x[4] - x[1] - s[1] * (y[4] - y[1])) << "\n";

    ld dp[n + 1];
    ld tmp[n + 1];
    forn(i, n) dp[i + 1] = inf;
    dp[0] = 0;

    forn(i, k) {
        Hull h;
        forn(j, n + 1) {
            tmp[j] = x[j] - h.eval(y[j]);
            if (dp[j] < inf / 2) h.add(Line{1.0L * s[j], -(dp[j] - x[j] + s[j] * y[j])});
        }
        memcpy(dp, tmp, sizeof(dp));
    }
    cout << setprecision(15) << fixed;
    cout << dp[n] << "\n";
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
    //ios_base::sync_with_stdio(false);
//    pre();
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