#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

void pre() {

}

struct data {
    ll sl;
    ll sr;
    ll s;
    ll sa;
    data operator+(const data &r) const {
        data res;
        res.sa = max(sa, r.sa);
        res.sa = max(res.sa, sr + r.sl);
        res.sl = max(sl, s + r.sl);
        res.sr = max(r.sr, r.s + sr);
        res.s = s + r.s;
        return res;
    }
    data() {
        sa = s = sl = sr =  0;
    }
    data(ll x) {
        sa = sl = sr = max(x, 0ll);
        s = x;
    }
};



void solve(int test) {
    int n = nxt();

    vi a(n);
    forn(i, n) {
        a[i] = nxt();
    }


    map <int, vector <int> > ids;

    vi b = a;

    forn(i, n) {
        while (b[i]) {
            ids[b[i]].push_back(i);
            b[i] /= 2;
        }
    }
    vector <pair <int, vector <int> > > R;
    for (auto t : ids) {
        R.push_back(t);
    }
    int l = 0, r = (int)R.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;

        vi used(n);

        vi z;

        auto it = R.begin() + m + 1;
        while (it != R.begin()) {
            --it;
            for (auto t : it->y) {
                if (!used[t]) {
                    used[t] = 1;
                    z.push_back(it->x);
                    goto l1;
                }
            }
            l1:;
        }

        if (z.size() == n) {
            r = m;
        } else {
            l = m + 1;
        }

        cerr << l << " " << r << endl;
    }

    vi used(n);

    vi z;

    auto it = R.begin() + l + 1;
    while (it != R.begin()) {
        --it;
        for (auto t : it->y) {
            if (!used[t]) {
                used[t] = 1;
                z.push_back(it->x);
                goto l2;
            }
        }
        l2:;
    }

    assert(z.size() == n);
    forn(i, n) {
        cout << z[i] << " ";
    }
    cout << "\n";
}


int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    int t = 1;
#ifdef LOCAL
#else
#endif
    for (int test = 1; test <= t; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}


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


template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
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

template<typename T = long long>
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

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
T pw(T a, T n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template<typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}


template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}