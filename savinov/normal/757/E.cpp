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
//typedef pair<int, int> pii;
typedef pair<long long, long long> pii;
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

mt19937 gen;

int TTT;

ll mod = 1000000007;


void pre() {

}

int G(int x) {
    if (x == 1) {
        return 1;
    }
    return 0;
    int res = 0;
    for (int v = 1; v <= x; ++v) {
        if (x % v == 0 && gcd(v, x / v) == 1) {
            ++res;
        }
    }
    return res;
}

int f(int n, int x) {
    if (n == 0) {
        return G(x);
    }
    int res = 0;
    for (int v = 1; v <= x; ++v) {
        if (x % v == 0) {
            res += f(n - 1, x);
        }
    }
    return res;
}


map <vector <int>, int> d;
vector <int> k[300];

vector <pii> divs[300];

ll value[300];

void norm(vector <int> &x) {
    sort(all(x), greater <int>());
    while (!x.empty() && x.back() == 0) x.pop_back();
}

void iterate(vector<int> x, vector <int> y, int pos, int id) {
    if (pos == x.size()) {
        norm(x), norm(y);
        assert(d.count(x));
        assert(d.count(y));
        divs[id].push_back(mp(d[x], d[y]));
        return;
    }
    int r = x[pos];
    for (int u = 0; u <= r; ++u) {
        x[pos] = u;
        y[pos] = r - u;
        iterate(x, y, pos + 1, id);
    }
}

ll dp[30][300];

int ww[1 << 20];

void solve(int test) {

    vector <int> lp(1 << 20);

    for (int i = 2; i < (1 << 20); ++i) {
        if (!lp[i]) {
            for (int j = i; j < (1 << 20); j += i) {
                lp[j] = i;
            }
        }
    }

    int sz = 0;
    for (int i = 1; i <= 1000000; ++i) {
        int x = i;
        vector <int> e;
        while (x > 1) {
            int l = lp[x];
            int w = 0;
            while (lp[x] == l) {
                x /= l;
                ++w;
            }
            e.push_back(w);
        }
        sort(all(e), greater <int>());
        if (!d.count(e)) {
            k[sz] = e;
            value[sz] = 1ll << e.size();
            ww[i] = sz;
            d[e] = sz++;
        } else {
            ww[i] = d[e];
        }
    }

    for (int i = 0; i < sz; ++i) {
        iterate(k[i], k[i], 0, i);
    }

    for (int i = 0; i < sz; ++i) {
        dp[0][i] = value[i];
    }

    for (int K = 0; K < 22; ++K) {
        for (int i = 0; i < sz; ++i) {
            for (auto r : divs[i]) {
                if (r.x == i) continue;
                dp[K + 1][i] += dp[K][r.x];
                dp[K + 1][i] %= mod;
            }
        }
    }


    ll inv[23];

    for (int i = 1; i < 23; ++i) {
        inv[i] = pw(1ll * i, mod - 2, mod);
    }

    int q = nxt();

    while (q--) {
        int r = nxt();
        int n = ww[nxt()];

        ll bin = 1;

        ll ans = 0;

        for (int i = 0; i <= 20 && i <= r; ++i) {
            ans += bin * dp[i][n] % mod;
            bin = bin * (r - i) % mod;
            bin = bin * inv[i + 1] % mod;
        }
        ans %= mod;
        cout << ans << "\n";
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