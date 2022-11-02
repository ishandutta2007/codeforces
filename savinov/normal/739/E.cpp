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

class range  {
    using type = long long;
public:
    class iterator {
        friend class range;
    public:
        using difference_type = range::type;
        using value_type = range::type;
        using pointer = const range::type*;
        using reference = const range::type&;
        using iterator_category = std::random_access_iterator_tag;

        value_type operator*() const { return i_; }
        const iterator &operator++() { ++i_ ;return *this; }
        iterator operator++(int) { iterator copy(*this); ++i_; return copy; }
        const iterator &operator--() { --i_; return *this; }
        iterator operator--(int) { iterator copy(*this); --i_; return copy; }
        difference_type operator-(const iterator &other) const { return i_ - other.i_; }
        iterator operator+(const difference_type &delta) const { return iterator(i_ + delta); }
        iterator &operator+=(const difference_type &delta) { i_ += delta; return *this; }
        iterator operator-(const difference_type &delta) const { return iterator(i_ - delta); }
        iterator &operator-=(const difference_type &delta) { i_ -= delta; return *this; }
        bool operator==(const iterator &other) const { return i_ == other.i_; }
        bool operator!=(const iterator &other) const { return i_ != other.i_; }
    protected:
        iterator(const value_type &start) : i_(start) {}
    private:
        value_type i_;
    };

    iterator begin() const { return begin_; }
    iterator end() const { return end_; }
    range(const type &begin, const type &end) : begin_(begin), end_(end) {
        assert(begin <= end);
    }
    range(const type &end) : begin_(0), end_(end) {}

private:
    iterator begin_;
    iterator end_;
};

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

class range;

mt19937 gen;

void pre() {

}


void solve(int test) {
    int n = nxt();
    int a = nxt();
    int b = nxt();

    double p[n];
    forn(i, n) cin >> p[i];

    double q[n];
    forn(i, n) cin >> q[i];

    double l = -1, r = 0;

    int it = 30;

    double B = -1;

    const double eps = 1e-9;

    auto solve = [&](double m) {
        vector <pair <double, int> > d(n);
        int s = 0;
        double ans = 0;
        forn(i, n) {
            int da1 = 0, db1 = 0;
            double m1 = DBL_MIN;
            if (q[i] >  p[i] + m + q[i] - p[i] * q[i]) {
                da1 = 0, db1 = 1;
                m1 = q[i];
            } else {
                da1 = 1, db1 = 1;
                m1 = p[i] + m + q[i] - p[i] * q[i];
            }

            int da2 = 0, db2 = 0;
            double m2 = DBL_MIN;
            if (m + p[i] > 0) {
                da2 = 1, db2 = 0, m2 = m + p[i];
            } else {
                da2 = 0, db2 = 0, m2 = 0;
            }
            //M + m1 > m2
            //M > m2 - m1

            double m3 = m2 - m1;
            s += da2;
            ans += m2;
            d[i] = mp(m3, da1 - da2);
        }
        sort(all(d));
        forn(i, b) {
            s += d[i].y;
            ans -= d[i].x;
        }
        return mp(s, ans);
    };


    while (it--) {
        double m = (l + r) / 2;
        auto e = solve(m);
        if (e.x < a) {
            l = m;
        } else {
            r = m;
        }
    }
    double m = (l + r) / 2;
    auto e = solve(m).y - m * a;
    cout << setprecision(10) << fixed;
    cout << e << "\n";
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