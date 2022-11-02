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

void solve(int test) {
//    typedef bitset <100> bset;
//
//    for (int i = 2; i <= 10; ++i) {
//        bset res[i + 1];
//        for (int s = 0; s < 2; ++s) {
//            bset dp[i][i + 1][2];
//            dp[0][!s][s].set(0);
//            for (int j = 0; j + 1 < i; ++j) {
//                for (int c = 0; c <= j + 1; ++c) {
//                    for (int k = 0; k < 2; ++k) {
//                        for (int t = 0; t < 2; ++t) {
//                            if (k == 1 && t == 1) {
//                                dp[j + 1][c + (t == 0)][t] |= dp[j][c][k];
//                            } else {
//                                dp[j + 1][c + (t == 0)][t] |= dp[j][c][k] << 1;
//                            }
//                        }
//                    }
//                }
//
//            }
//            for (int j = 0; j <= i; ++j) {
//                for (int p = 0; p < 2; ++p) {
//                    if (p == 1 && s == 1) {
//                        res[j] |= dp[i - 1][j][p];
//                    } else {
//                        res[j] |= dp[i - 1][j][p] << 1;
//                    }
//                }
//            }
//        }
//
//        cerr << "# " << i << endl;
//        for (int j = 0; j <= i; ++j) {
//            int mi = INT_MAX;
//            int ma = INT_MIN;
//            for (int k = i; k >= 0; --k) {
//                if (res[j][k]) {
//                    ma = k;
//                    break;
//                }
//            }
//
//            for (int k = 0; k <= i; ++k) {
//                if (res[j][k]) {
//                    mi = k;
//                    break;
//                }
//            }
//            cerr << j << " " << mi << " " << ma << "\n";
//        }
//    }


    int n = nxt();
    int k = nxt();

    vi p(n);
    forn(i, n) {
        p[i] = nxt() - 1;
    }

    vi u(n);

    vi l;

    forn(i, n) {
        if (!u[i]) {
            int x = 0;
            while (!u[i]) {
                u[i] = 1;
                i = p[i];
                ++x;
            }
            l.push_back(x);
        }
    }
    sort(all(l), greater <int>());
    int mi = k;

    map <int, int> cnt;

    for (int x : l) cnt[x]++;

    bitset <1 << 20> dp;

    dp[0] = 1;

    for (auto t : cnt) {
        int two = 1;
        int r = t.y;
        while (r >= two) {
            dp |= dp << (t.x * two);
            r -= two;
            two *= 2;
        }
        if (r) {
            dp |= dp << (t.x * r);
        }
    }
//
//    for (int i = 0; i <= n; ++i) {
//        cerr << dp[i] << " ";
//    }
//    cerr << "\n";

    if (!dp[k]) mi += 1;

    int ma = 0;


    vi cur(l.size());

    auto cost = [&](int a, int b) {
        return min(2 * a, b);
    };

    auto getDelta = [&](int i) {
        return cost(cur[i] + 1, l[i]) - cost(cur[i], l[i]);
    };

    auto cmp = [&](int a, int b) {
        int d1 = getDelta(a);
        int d2 = getDelta(b);
        if (d1 != d2) {
            return d1 > d2;
        }
        return a < b;
    };

    set <int, decltype(cmp)> q(cmp);

    forn(i, l.size()) q.insert(i);

    while (k && !q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());

        ma += getDelta(v);
        cur[v] += 1;
        k--;

        if (cur[v] < l[v]) {
            q.insert(v);
        }
    }

    cout << mi << " " << ma << "\n";
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