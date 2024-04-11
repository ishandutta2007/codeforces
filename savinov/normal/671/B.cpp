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

int stupid(vector <int> x, int k) {
    cerr << "N: " << x.size() << "\n";
    cerr << "K: " << k << "\n";
    forn (i, x.size()) cerr << x[i] << " ";
    cerr << "\n";
    while (k--) {
        auto p1 = max_element(all(x));
        --(*p1);
        auto p2 = min_element(all(x));
        ++(*p2);
    }
    sort(all(x));
    forn (i, x.size()) cerr << x[i] << " ";
    cerr << "\n";
    cerr << "ANSWER: " << *max_element(all(x)) - *min_element(all(x)) << "\n";
    return *max_element(all(x)) - *min_element(all(x));
}

void solve(int test) {
    int n = nxt();
    int k = nxt();

    if (n == 1) {
        cout << "0\n";
        return;
    }
    int a[n];
    forn (i, n) a[i] = nxt();

    if (k == 0) {
        cout << *max_element(a, a + n) - *min_element(a, a + n) << "\n";
        return;
    }

    sort(a, a + n);

    ll s1 = 0;

    int l = 1;

    ll r1 = k;

    for (int i = 1; i < n; ++i) {
        s1 += i * 1ll * (a[i] - a[i - 1]);
        if (s1 > k) {
            break;
        }
        r1 = k - s1;
        ++l;
    }

    ll s2 = 0;
    ll r2 = k;
    int r = 1;
    for (int i = n - 2; i >= 0; --i) {
        s2 += r * 1ll * (a[i + 1] - a[i]);
        if (s2 > k) {
            break;
        }
        r2 = k - s2;
        ++r;
    }

    if (l + r > n) {
        long long s = accumulate(a, a + n, 0ll);
        if (s % n == 0) {
            //assert(stupid(vector <int>(a, a + n), k) == 0);
            cout << "0\n";
        } else {
            //assert(stupid(vector <int>(a, a + n), k) == 1);
            cout << "1\n";
        }
        return;
    }

    ll u = a[l - 1] + r1 / l;
    ll v = a[n - r] - r2 / r;

    if (l + r == n && u >= v) {
        long long s = accumulate(a, a + n, 0ll);
        if (s % n == 0) {
            //assert(stupid(vector <int>(a, a + n), k) == 0);
            cout << "0\n";
        } else {
            //assert(stupid(vector <int>(a, a + n), k) == 1);
            cout << "1\n";
        }
        return;
    }

//    cerr << "U: " << u << "\n";
//    cerr << "V: " << v << "\n";
//    cerr << "MY " << v - u << "\n";
//    assert(stupid(vector <int>(a, a + n), k) == v - u);
    cout << v - u << "\n";
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
//    pre();
//    exit(0);
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