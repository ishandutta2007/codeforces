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

int lp[1 << 20];

void solve(int test) {
    int n = nxt();
    int k = nxt();

//    for (int i = 2; i < (1 << 20); ++i) {
//        if (lp[i] == 0) {
//            for (int j = i; j < (1 << 20); j += i) {
//                lp[j] = i;
//            }
//        }
//    }


    vector <PII> f;

    for (int i = 2; i <= 1000000; ++i) {
        if (k % i == 0) {
            f.pb(mp(i, 0));
            while (k % i == 0) {
                k /= i;
                f.back().y += 1;
            }
        }
    }

    vector <int> ok(f.size());

    forn(i, n) {
        int x = nxt();
        int j = 0;
        for (auto v : f) {
            int d = 0;
            while (x % v.x == 0) {
                x /= v.x;
                ++d;
            }
            if (d >= v.y) {
                ok[j] = 1;
            }
            ++j;
        }
    }

    if (accumulate(all(ok), 0) == ok.size()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

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
//    pre();

    int t = 1;
    while (t--) {
        solve(c++);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}