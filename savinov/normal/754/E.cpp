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

typedef double D;
constexpr int N = 1 << 10;

struct C {
    D x, y;

    C() {}

    C(D x, D y) : x(x), y(y) {}

    C operator+(const C &r) const {
        return C(x + r.x, y + r.y);
    }

    C operator-(const C &r) const {
        return C(x - r.x, y - r.y);
    }

    C operator*(const C &r) const {
        return C(x * r.x - y * r.y, y * r.x + x * r.y);
    }

    C &operator/=(const D &r) {
        x /= r;
        y /= r;
        return *this;
    }
};

C PW[N];
C IPW[N];
C CPW[N];


void initFFT() {
    for (int i = 0; i < N; ++i) {
        D ang = i * 2 * PI / N;
        D co = cosl(ang);
        D si = sinl(ang);
        PW[i] = C(co, si);
        IPW[i] = C(co, -si);
    }
}

void fft(C *a, bool inv) {
    int n = N;
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2, shift = N >> 1; len <= n; len <<= 1, shift >>= 1) {
        int len2 = len >> 1;
        for (int j = 0; j < len2; ++j) {
            CPW[j] = inv ? IPW[j * shift] : PW[j * shift];
        }
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len2; ++j) {
                const C u = a[i + j];
                const C v = a[i + j + len2] * CPW[j];
                a[i + j] = u + v;
                a[i + j + len2] = u - v;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
    }
}

C A[N];

constexpr int K = 1024;

struct poly2d {
    int s[K][K];

    poly2d() {
        clr(s);
    }

    int * operator[](int x) {
        return s[x];
    }
};

C U[K][K];
C V[K][K];

void fft2(C x[][K], bool inv) {
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            A[j] = x[i][j];
        }
        fft(A, inv);
        for (int j = 0; j < K; ++j) {
            x[i][j] = A[j];
        }
    }
    for (int j = 0; j < K; ++j) {
        for (int i = 0; i < K; ++i) {
            A[i] = x[i][j];
        }
        fft(A, inv);
        for (int i = 0; i < K; ++i) {
            x[i][j] = A[i];
        }
    }
}

void polysq(poly2d& x, poly2d &y) {
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            if (x[i][j]) {
                U[i][j].x = cosl(2 * PI * x[i][j] / 27.0), U[i][j].y = sinl(2 * PI * x[i][j] / 27.0);
            }
            if (y[i][j]) {
                V[i][j].x = cosl(2 * PI * -y[i][j] / 27.0), V[i][j].y = sinl(2 * PI * -y[i][j] / 27.0);
            }
        }
    }
    fft2(U, false);
    fft2(V, false);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            U[i][j] = U[i][j] * V[i][j];
        }
    }
    fft2(U, true);

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            if (abs(U[i][j].y) < 1e-6 && abs(U[i][j].x - llround(U[i][j].x)) < 1e-6) {
                x[i][j] = llround(U[i][j].x);
            } else {
                x[i][j] = -1;
            }
        }
    }
}

poly2d Q, W;

void solve(int test) {
    initFFT();
    int n = nxt();
    int m = nxt();

    string s[n];
    forn(i, n) cin >> s[i];

    int r = nxt();
    int c = nxt();

    string t[r];
    forn(i, r) cin >> t[i];

    char ans[n][m];
    memset(ans, 1, sizeof(ans));


    forn(i, n+r) forn(j, m+c) {
            if (isalpha(s[i % n][j % m])) Q[i][j] = s[i % n][j % m] - 'a' + 1;
        }
    int cnt = 0;
    forn(i, r) forn(j, c) {
            if (isalpha(t[i][j])) {
                W[r - i][c - j] = t[i][j] - 'a' + 1, ++cnt;
            }
        }
    polysq(Q, W);


    forn(i, n) {
        forn(j, m) {
            if (Q[i + r][j + c] != cnt) ans[i][j] = 0;
        }
        //cerr << "\n";
    }


    forn(i, n) {
        forn(j, m) putchar('0' + ans[i][j]);
        putchar('\n');
    }


}


int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.Ntxt", "w", stdout);
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