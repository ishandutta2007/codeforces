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

void solve() {
    int n = nxt();
    long long v[n];
    long long t[n];

    for (int i = 0; i < n; ++i) {
        int r = nxt();
        int h = nxt();
        v[i] = 1ll * r * r * h;
        t[i] = v[i];
    }

    sort(t, t + n);
    int sz = unique(t, t + n) - t;

    for (int i = 0; i < n; ++i) {
        v[i] = lower_bound(t, t + sz, v[i]) - t;
    }

    long long best[sz + sz];
    clr(best);

    auto get = [&](int l, int r) {
        long long res = 0;
        for (l += sz, r += sz; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                res = max(res, best[l]);
            }
            if (!(r & 1)) {
                res = max(res, best[r]);
            }
        }
        return res;
    };

    auto put = [&](int pos, long long value) {
        for (pos += sz; pos > 0; pos >>= 1) {
            best[pos] = max(best[pos], value);
        }
    };

    for (int i = 0; i < n; ++i) {
        long long x = get(0, v[i] - 1);
        x += t[v[i]];
        put(v[i], x);
    }
    cout << setprecision(10) << fixed;
    cout << PI * get(0, sz - 1) << endl;
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
    int t = 1;
//    pre();
#ifdef LOCAL
#endif


    int c = 0;
    while (t--) {
        solve();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}