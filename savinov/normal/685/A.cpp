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

struct F {
    vector <int> a;

    F(int n) {
        a.resize(n);
    }

    int get(int r) {
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) {
            res += a[r];
        }
        return res;
    }

    void inc(int r) {
        for (; r < a.size(); r |= r + 1)
            a[r] += 1;
    }
};

bool uax(int &x, int y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

bool uin(int &x, int y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

map <pair <int, int>, int> ans;

int P[30];

int get(int r, int mask) {
//    cerr << r << " " << mask << endl;
    if (ans.count(mp(r, mask))) {
        return ans[mp(r, mask)];
    }
    if (r == 0) {
        return mask == 1;
    }
    int & res = ans[mp(r, mask)];
    vector <int> digits;

    while (r) {
        digits.pb(r % 7);
        r /= 7;
    }
//    cerr << digits.size() << "\n";
    ford(i, digits.size()) {
        int c = digits[i];
        for (int d = 0; d < c; ++d) {
            if (mask & (1 << d)) {
                if (i == 0) {
                    res += (mask ^ (1 << d)) == 0;
                } else {
                    res += get(P[i] - 1, mask ^ (1 << d));
                }
            }
        }
        if (!(mask & (1 << c))) {
            return res;
        }
        mask ^= 1 << c;
    }
    if (mask == 0) res += 1;
    return res;
}

void pre() {
    P[0] = 1;
    for (int i = 1; i < 30; ++i) {
        P[i] = P[i - 1] * 7;
    }
}

void solve(int test) {
    int n = nxt();
    int m = nxt();

//    cerr << get(1, 1) << endl;
//    cerr << get(2, 2) << endl;
    ll ans = 0;
    for (int i = 0; i < (1 << 7); ++i) {
        for (int j = 0; j < (1 << 7); ++j) {
            if ((i & j) == 0) {
                ans += 1ll * get(n - 1, i) * get(m - 1, j);
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
//    init();
//    test();
//    exit(0);
//    int t = nxt();

#ifdef LOCAL
#else
#endif
    int c = 0;
//    gl = clock() + CLOCKS_PER_SEC * 0.9;

//    read();
    pre();

    int t = 1;
    while (t--) {
        solve(c++);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}