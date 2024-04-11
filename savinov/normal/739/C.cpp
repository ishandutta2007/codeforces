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

struct data {
    int lNegative;
    int rPositive;
    int rNegative;
    int lPositive;

    int lAns;
    int rAns;
    int ans;
    int length;

    data operator+(const data &r) const {
        data res;
        res.length = length + r.length;

        if (r.rPositive == r.length) {
            res.rPositive = r.rPositive + rPositive;
        } else {
            res.rPositive = r.rPositive;
        }
        if (r.rNegative == r.length) {
            res.rNegative = r.rNegative + rNegative;
        } else {
            res.rNegative = r.rNegative;
        }

        if (lNegative == length) {
            res.lNegative = lNegative + r.lNegative;
        } else {
            res.lNegative = lNegative;
        }

        if (lPositive == length) {
            res.lPositive = lPositive + r.lPositive;
        } else {
            res.lPositive = lPositive;
        }

        if (lAns == length) {
            res.lAns = lAns + r.lNegative;
        } else {
            res.lAns = lAns;
        }

        if (r.rAns == r.length) {
            res.rAns = r.rAns + rPositive;
        } else {
            res.rAns = r.rAns;
        }

        if (rPositive == length) {
            res.lAns = max(res.lAns, length + r.lAns);
        }
        if (r.lNegative == r.length) {
            res.rAns = max(res.rAns, r.length + rAns);
        }

        res.lAns = max(res.lAns, res.lPositive);
        res.lAns = max(res.lAns, res.lNegative);

        res.rAns = max(res.rAns, res.rPositive);
        res.rAns = max(res.rAns, res.rNegative);

        res.ans = max(ans, r.ans);
        res.ans = max(res.ans, res.lAns);
        res.ans = max(res.ans, res.rAns);

        res.ans = max(res.ans, rAns + r.lNegative);
        res.ans = max(res.ans, rPositive + r.lAns);

        res.ans = max(res.ans, rPositive + r.lPositive);
        res.ans = max(res.ans, rNegative + r.lNegative);

        assert(res.rAns >= res.rPositive);
        assert(res.rAns >= res.rNegative);
        assert(res.lAns >= res.lNegative);
        assert(res.lAns >= res.lPositive);

        return res;
    }

    data() {
        lNegative = 0;
        rNegative = 0;
        rPositive = 0;
        lPositive = 0;
        lAns = 0;
        rAns = 0;
        ans = 0;
        length = 0;
    }

    data(ll x) {
        if (x < 0) {
            lNegative = 1;
            rNegative = 1;
            rPositive = 0;
            lPositive = 0;

            lAns = 1;
            rAns = 1;
            ans = 1;

            length = 1;
        }
        if (x == 0) {
            lNegative = 0;
            rNegative = 0;
            lPositive = 0;
            rPositive = 0;

            lAns = 0;
            rAns = 0;
            ans = 0;

            length = 1;
        }
        if (x > 0) {
            lNegative = 0;
            rNegative = 0;
            lPositive = 1;
            rPositive = 1;

            lAns = 1;
            rAns = 1;
            ans = 1;

            length = 1;
        }
    }
};

void solve(int test) {
    int n = nxt();
    vi a(n);
    forn(i, n) a[i] = nxt();

    if (n == 1) {
//        assert(false);
        int m = nxt();
        while (m--) {
            cout << "1\n";
        }
        return;
    }
    vll b(n - 1);
    forn(i, n - 1) {
        b[i] = a[i + 1] - a[i];
    }

    int m = nxt();

    int N = 1;
    while (N < n - 1) {
        N *= 2;
    }

    vector <data> st(N + N);
    forn(i, n - 1) {
        st[i + N] = b[i];
    }
    for (int i = N - 1; i > 0; --i) {
        st[i] = st[i + i] + st[i + i + 1];
    }

    auto update = [&](int pos, ll value) {
        pos += N;
        st[pos] = value;
        for (pos >>= 1; pos; pos >>= 1) {
            st[pos] = st[pos + pos] + st[pos + pos + 1];
        }
    };

    while (m--) {
        int l = nxt() - 2;
        int r = nxt() - 1;

        int d = nxt();

        if (l >= 0) {
            b[l] += d;
            update(l, b[l]);
        }
        if (r < n - 1) {
            b[r] -= d;
            update(r, b[r]);
        }
#ifdef LOCAL
        int res = 0;
        auto sign = [](ll x) {
            if (x < 0) {
                return -1;
            }
            if (x > 0) {
                return 1;
            }
            return 0;
        };
        int prevSign = 0;
        int prevLen = 0;

        forn(i, n - 1) {
            int j = i;
            while (j < n - 1 && sign(b[i]) == sign(b[j])) {
                ++j;
            }
//            cerr << i << " " << j << " " << sign(i) << "\n";
            if (sign(b[i]) == -1) {
                res = max(res, j - i);
                if (prevSign == 1) {
                    res = max(res, j - i + prevLen);
                }
            }
            if (sign(b[i]) == 1) {
                res = max(res, j - i);
            }
            prevLen = j - i;
            prevSign = sign(b[i]);
            i = j - 1;
        }



        if (res != st[1].ans) {
            forn(i, n - 1) {
                cerr << sign(b[i]) << " ";
            }
            cerr << "\n";
            cerr << res << " " << st[1].ans << endl;
            assert(res == st[1].ans);
        }

#endif
        cout << st[1].ans + 1 << "\n";
    }
}


int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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