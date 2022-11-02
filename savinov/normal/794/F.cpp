//
// Created by Evgeny Savinov on 09/01/2017.
//

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
typedef vector<vi> vvi;
typedef pair<int, int> pii;
//typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
typedef unsigned int uint;

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

class range {
    using type = long long;
public:
    class iterator {
        friend class range;

    public:
        using difference_type = range::type;
        using value_type = range::type;
        using pointer = const range::type *;
        using reference = const range::type &;
        using iterator_category = std::random_access_iterator_tag;

        value_type operator*() const { return i_; }

        const iterator &operator++() {
            ++i_;
            return *this;
        }

        iterator operator++(int) {
            iterator copy(*this);
            ++i_;
            return copy;
        }

        const iterator &operator--() {
            --i_;
            return *this;
        }

        iterator operator--(int) {
            iterator copy(*this);
            --i_;
            return copy;
        }

        difference_type operator-(const iterator &other) const { return i_ - other.i_; }

        iterator operator+(const difference_type &delta) const { return iterator(i_ + delta); }

        iterator &operator+=(const difference_type &delta) {
            i_ += delta;
            return *this;
        }

        iterator operator-(const difference_type &delta) const { return iterator(i_ - delta); }

        iterator &operator-=(const difference_type &delta) {
            i_ -= delta;
            return *this;
        }

        bool operator==(const iterator &other) const { return i_ == other.i_; }

        bool operator!=(const iterator &other) const { return i_ != other.i_; }

    protected:
        iterator(const value_type &start) : i_(start) {}

    private:
        value_type i_;
    };

    iterator begin() const { return begin_; }

    iterator end() const { return end_; }

    range(const type &begin, const type &end) : begin_(begin), end_(end) {}

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

template<class _T>
_T sqr(const _T &x);

class range;

mt19937_64 gen;

int TTT;

ll mod = 1000000007;


void pre() {

}
struct m {
    int b[10];

    m() {
        forn(i, 10) {
            b[i] = i;
        }
    }

    m operator*(const m &r) const {
        m res;
        clr(res.b);
        forn(i, 10) res.b[i] = b[r.b[i]];
        return res;
    }
};

m add[1 << 18];
long long k[1 << 18][10];


void update(int v, ll *t) {
    forn(i, 10) {
        t[add[v].b[i]] += k[v][i];
    }
}

void push(int v) {
    add[v + v] = add[v] * add[v + v];
    add[v + v + 1] = add[v] * add[v + v + 1];
    add[v] = m();
}

void update(int v, int tl, int tr, int l, int r, m mul) {
    if (l >= r) return;
    if (tl == l && tr == r) {
        add[v] = mul * add[v];
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v + v, tl, tm, l, min(tm, r), mul);
    update(v + v + 1, tm, tr, max(l, tm), r, mul);

    clr(k[v]);
    update(v + v, k[v]);
    update(v + v + 1, k[v]);
}

void init(int v, int tl, int tr, int *x) {
    if (tr - tl == 1) {
        int z = x[tl];
        int e = 1;
        while (z) {
            k[v][z % 10] += e;
            e *= 10;
            z /= 10;
        }
        return;
    }
    int tm = (tl + tr) / 2;

    init(v + v, tl, tm, x);
    init(v + v + 1, tm, tr, x);
    clr(k[v]);

    update(v + v, k[v]);
    update(v + v + 1, k[v]);
}

long long get(int v, int tl, int tr, int l, int r) {
    if (l >= r) return 0;
    if (tl == l && tr == r) {
        ll res = 0;
        forn(i, 10) {
            res += add[v].b[i] * k[v][i];
        }
        return res;
    }
    push(v);

    int tm = (tl + tr) / 2;

    ll res = get(v + v, tl, tm, l, min(r, tm)) + get(v + v + 1, tm, tr, max(l, tm), r);

    clr(k[v]);
    update(v + v, k[v]);
    update(v + v + 1, k[v]);

    return res;
}

int data[1 << 20];

void solve(int test) {
    int n = nxt();
    int q = nxt();


    forn(i, n) {
        data[i] = nxt();
    }

    init(1, 0, n, data);

//    cerr << get(1, 0, n, 0, 1) << "\n";
//    return;

    while (q--) {
        int t = nxt();
        if (t == 1) {
            int l = nxt() - 1;
            int r = nxt();
            int x = nxt();
            int y = nxt();
            m e{};
            e.b[x] = y;

            update(1, 0, n, l, r, e);
        } else {
            int l = nxt() - 1;
            int r = nxt();

            cout << get(1, 0, n, l, r) << "\n";
        }

//        forn(i, n) {
//            cerr << get(1, 0, n, i, i + 1) << " ";
//        }
//        cerr << "\n";
    }
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
    ::TTT = 1;
#ifdef LOCAL
#else
#endif

    for (int test = 1; test <= ::TTT; ++test) {
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