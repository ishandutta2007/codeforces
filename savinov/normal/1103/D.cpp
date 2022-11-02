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


void solve(int test) {
    int n = nxt();
    ll k = nxt();


    vll a(n);
    forn(i, n) a[i] = nxt();

    vll e(n);
    forn(i, n) e[i] = nxt();

    ll g = 0;

    forn(i, n) g = gcd(g, a[i]);

    vector<ll> primes;

    for (ll i = 2; i * i <= g; ++i) {
        if (g % i == 0) {
            primes.push_back(i);
            while (g % i == 0) g /= i;
        }
    }
    if (g > 1) primes.push_back(g);

    vector<vi> ids(1 << primes.size());
    for (auto &i : ids) i.reserve(10000 + 1);


    size_t MAGIC = primes.size();

    map<ll, vector<int> > v;
    map <ll, int> cc;


    auto get_divs = [&](ll x) {
        vector<ll> d;
        d.reserve(primes.size());
        ll u = 1;
        for (ll p : primes) {
            ll cur = 1;
            while (x % p == 0) {
                cur *= p;
                x /= p;
            }
            u *= cur;
            d.push_back(cur);
        }
        return mp(u, d);
    };


    auto gen_masks = [&](pair <int, vector <ll>> x) {
        int u;
        vector <long long> d;
        std::tie(u, d) = x;

        if (v.count(u)) {
            return v[u];
        }
        vector<int> &masks = v[u];
        vector<char> used(1 << primes.size());

        for (int mask = (1 << primes.size()) - 1; mask > 0; --mask) {
            ll z = 1;
            for (int j = 0; j < primes.size(); ++j) {
                if (mask & (1 << j)) {
                    z = z * d[j];
                }
            }
            if (z <= k) {
                masks.push_back(mask);
            }
        }
        return masks;
    };

    vector<int> o(n);
    iota(all(o), 0);

    sort(all(o), [&](int a, int b) { return e[a] < e[b]; });

    set<int> I;


    for (int i : o) {
        auto d = get_divs(a[i]);
        if (cc[d.x] >= MAGIC) continue;
        cc[d.x]++;
        auto masks = gen_masks(d);
        for (auto mask : masks) {
            if (ids[mask].size() < MAGIC) {
                I.insert(i);
                ids[mask].push_back(i);
            }
        }
    }

    vector<vector<ll>> dp(1 << primes.size(), vector<ll>(primes.size() + 1, 1e15));
    dp.back()[0] = 0;

    for (int i : I) {
        auto tmp = dp;
        auto d = get_divs(a[i]);
        auto masks = gen_masks(d);
        for (int mask : masks) {
            for (int m = mask; m < (1 << primes.size()); m += 1, m |= mask) {
                forn(j, (int) primes.size()) {
                    tmp[m ^ mask][j + 1] = min(tmp[m ^ mask][j + 1], dp[m][j] + e[i]);
                }
            }
        }

        tmp.swap(dp);
    }


    ll ans = 1e18;

    for (int i = 0; i <= primes.size(); ++i) {
        if (dp[0][i] < 1e14) {
            ans = min(ans, dp[0][i] * i);
        }
    }

    if (ans > 1e14)
        ans = -1;

    cout << ans << "\n";
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

template<typename T>
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