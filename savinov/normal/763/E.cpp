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

vector <int> g[1 << 20];

int L[1 << 20];
int R[1 << 20];

int ans[1 << 20];

struct Dsu {
    vector <int *> ptrs;
    vector <int> vals;
    vector <int> p;
    vector <int> sz;
    int components;

    void init(int n) {
        p.resize(n);
        sz.resize(n);
        ptrs.reserve(n);
        vals.reserve(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i, sz[i] = 1;
        }
    }

    void set(int *x, int y) {
        ptrs.push_back(x);
        vals.push_back(*x);
        *x = y;
    }

    void revert(int version) {
        while (ptrs.size() > version) {
            *ptrs.back() = vals.back();
            ptrs.pop_back();
            vals.pop_back();
        }
    }

    inline int get(int v) {
        if (p[v] != v) {
            return get(p[v]);
            //set(p + v, get(p[v])); //compressed path heuristic
        }
        return p[v];
    }

    inline void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return;
        }
        components -= 1;
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        set(&p[a], b);
        set(&sz[b], sz[a] + sz[b]);
    }
    inline int getVersion() {
        return vals.size();
    }
};

Dsu dsu;

struct data {
    int p[5];
    int comps;

    void prepare() {
        vi x(5);
        forn(i, 5) x[i] = find(p, p + 5, p[i]) - p;
        forn(i, 5) p[i] = x[i];
    }
};

struct DD {
    int p[10];
    int comps;

    inline int get(int v) {
        if (p[v] != v) {
            return p[v] = get(p[v]);
        }
        return p[v];
    }

    inline void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return;
        }
        comps -= 1;

        p[a] = b;
    }
};

void solve(int l, int r, vector <int> &queries) {
    if (r - l < 10) {
        for (auto q : queries) {
            int v = dsu.getVersion();
            dsu.components = R[q] - L[q];
            for (int i = L[q]; i < R[q]; ++i) {
                for (auto to : g[i]) {
                    if (to >= L[q] && to < R[q]) {
                        dsu.unite(i, to);
                    }
                }
            }
            ans[q] = dsu.components;
            dsu.revert(v);
        }
        return;
    }
    int m = (l + r) / 2;
    vector <int> EL, ER, cur;
    for (int x : queries) {
        if (R[x] <= m) EL.push_back(x);
        else if (L[x] >= m) ER.push_back(x);
        else cur.push_back(x);
    }
    solve(l, m, EL);
    solve(m, r, ER);

    vector <data> D(r - l);

    dsu.components = 0;
    int v = dsu.getVersion();
    for (int i = m; i < r; ++i) {
        dsu.components += 1;
        for (int to : g[i]) {
            if (to < i && to >= m) {
                dsu.unite(i, to);
            }
        }
        for (int j = 0; j < 5 && m + j <= i; ++j) {
            D[i - l].p[j] = dsu.get(m + j);
        }

        D[i - l].comps = dsu.components;
        D[i - l].prepare();
    }

    dsu.revert(v);

    dsu.components = 0;
    v = dsu.getVersion();
    for (int i = m - 1; i >= l; --i) {
        dsu.components += 1;
        for (int to : g[i]) {
            if (to > i && to < m) {
                dsu.unite(i, to);
            }
        }
        for (int j = 0; j < 5 && m - 1 - j >= i; ++j) {
            D[i - l].p[j] = dsu.get(m - 1 - j);
        }
        D[i - l].comps = dsu.components;
        D[i - l].prepare();
    }

    dsu.revert(v);

    for (auto q : cur) {
        DD d;
        d.comps = 0;
        for (int j = 0; j < 5 && m - 1 - j >= L[q]; ++j) {
            d.p[j] = D[L[q] - l].p[j];

        }
        d.comps += D[L[q] - l].comps;

        for (int j = 0; j < 5 && m + j < R[q]; ++j) {
            d.p[j + 5] = D[R[q] - 1 - l].p[j] + 5;
        }
        d.comps += D[R[q] - 1 - l].comps;

        for (int j = 0; j < 5 && m - 1 - j >= L[q]; ++j) {
            for (int to : g[m - 1 - j]) {
                if (to >= m && to < R[q]) {
                    d.unite(j, to - m + 5);
                }
            }
        }
        ans[q] = d.comps;
    }

}


void solve(int test) {
    int n = nxt();
    int k = nxt();
    dsu.init(n);

    int m = nxt();
    forn(i, m) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }

    int q = nxt();

    vi Q;

    forn(i, q) {
        int l = nxt() - 1;
        int r = nxt();
        L[i] = l;
        R[i] = r;
        Q.pb(i);
    }

    solve(0, n, Q);

    forn(i, q) {
        cout << ans[i] << "\n";
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