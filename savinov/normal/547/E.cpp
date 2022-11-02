#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")  //Enable AVX

#include <memory>
#include <random>
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

#ifndef LOCAL
#define cerr while(0) cerr
#endif

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

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T, typename N>
T pw(T a, N n, T m);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);

template<class T, class... Args>
inline auto make_vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, make_vec<T>(args...));
}

template<class... Args>
inline auto make_vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, make_vec(args...));
}


int TTT;

mt19937 gen;


void pre() {

}

struct SuffixArray {
    int *str;
    int *sa;
    int *ra;
    int *lcp;
    int *lgt;
    int **rmq;
    int n;
    SuffixArray() : str(0), sa(0), ra(0), lcp(0), lgt(0), rmq(0), n(0) {}

    int get(int pos) const {

        assert(pos < n);

        return str[pos];
    }

    void init(const vector<int> &s) {
        n = (int)s.size();
        str = new int[n];
        for (int i = 0; i < n; ++i) str[i] = s[i];
        __init();
    }
    void init(const string &s) {
        n = (int)s.length();
        str = new int[n];
        for (int i = 0; i < n; ++i) str[i] = s[i];
        __init();
    }
    void __init() {
        initSa();
        initLcp();
    }
    void initSa() {
        sa = new int[n];
        ra = new int[n];
        int *s = new int[n];
        int *c = new int[n];
        int *cl = new int[n];
        int *cnt = new int[n];
        for (int i = 0; i < n; ++i) {
            cl[i] = str[i];
            sa[i] = n - i - 1;
        }
        stable_sort(sa, sa + n, [&](int l, int r){ return str[l] < str[r]; });
        for (int len = 1; len < n; len <<= 1) {
            memcpy(c, cl, n * sizeof(int));
            memcpy(s, sa, n * sizeof(int));
            for (int i = 0; i < n; ++i) cnt[i] = i;
            int len2 = len >> 1;
            for (int i = 0; i < n; ++i) {
                //classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;

                if (i > 0 && c[sa[i]] == c[sa[i - 1]] && sa[i - 1] + len < n && c[sa[i] + len2] == c[sa[i - 1] + len2]) {
                    cl[sa[i]] = cl[sa[i - 1]];
                } else {
                    cl[sa[i]] = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                int s1 = s[i] - len;
                if (s1 >= 0) {
                    sa[cnt[cl[s1]]++] = s1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            ra[sa[i]] = i;
        }
        delete [] s;delete [] c;delete [] cl;delete [] cnt;
    }

    void initLcp() {
        lcp = new int[n];
        for (int i = 0, h = 0; i < n; ++i) {
            if (ra[i] < n - 1) {
                for (int j = sa[ra[i] + 1]; max(i, j) + h < n && str[i + h] == str[j + h]; ++h);
                lcp[ra[i]] = h;
                h = max(0, h - 1);
            } else {
                lcp[ra[i]] = 0;
            }
        }
        lgt = new int[n + 1];
        lgt[0] = lgt[1] = 0;
        for (int i = 2; i <= n; ++i) lgt[i] = lgt[i >> 1] + 1;
        rmq = new int*[lgt[n] + 1];
        for (int i = 0; i <= lgt[n]; ++i) {
            rmq[i] = new int[n];
        }
        for (int i = 0; i + 1 < n; ++i) {
            rmq[0][i] = lcp[i];
        }
        for (int l = 1; (1 << l) < n; ++l) {
            for (int i = 0; i + (1 << l) <= n; ++i) {
                rmq[l][i] = min(rmq[l - 1][i], rmq[l - 1][i + (1 << (l - 1))]);
            }
        }
    }
    int getLcpForSuffixes(int l, int r) {
        --r;
        int j = lgt[r - l];
        return min(rmq[j][l], rmq[j][r - (1 << j) + 1]);
    }

    ~SuffixArray() {
        if (str) delete [] str;
        if (sa) delete [] sa;
        if (ra) delete [] ra;
        if (lgt) {
            for (int i = 0; i <= lgt[n]; ++i) {
                delete [] rmq[i];
            }
            delete [] lgt;
            delete [] rmq;
        }
    }
} sa;

struct vertex {
    vertex * l, * r;
    int sum;

    vertex (int val)
            : l(NULL), r(NULL), sum(val)
    { }

    vertex (vertex * l, vertex * r)
            : l(l), r(r), sum(0)
    {
        if (l)  sum += l->sum;
        if (r)  sum += r->sum;
    }
};

vertex * build (int tl, int tr) {
    if (tl == tr)
        return new vertex (0);
    int tm = (tl + tr) / 2;
    return new vertex (
            build (tl, tm),
            build (tm+1, tr)
    );
}

int get_sum (vertex * t, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return t->sum;
    int tm = (tl + tr) / 2;
    return get_sum (t->l, tl, tm, l, min(r,tm))
           + get_sum (t->r, tm+1, tr, max(l,tm+1), r);
}

vertex * update (vertex * t, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new vertex (t->sum + new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new vertex (
                update (t->l, tl, tm, pos, new_val),
                t->r
        );
    else
        return new vertex (
                t->l,
                update (t->r, tm+1, tr, pos, new_val)
        );
}

void solve(int) {
    int n = nxt();
    int q = nxt();

    vector <string> s(n);
    forn(i, n) {
        cin >> s[i];
    }

    vector <int> z;
    int r = 26;
    forn(i, n) {
        for (char c : s[i]) {
            z.push_back(c - 'a');
        }
        z.push_back(r++);
    }

    sa.init(z);



    vector <vertex *> st(z.size() + 1);
    st[0] = build(0, n - 1);

    vector <int> bp(z.size(), -1);
    vector <int> start(n);
    int pos = 0;
    forn(i, n) {
        start[i] = sa.ra[pos];
        forn(j, s[i].length()) {
            int p = sa.ra[pos++];
            bp[p] = i;
        }
        pos++;
    }

    forn(i, z.size()) {
        if (bp[i] != -1) {
            st[i + 1] = update(st[i], 0, n - 1, bp[i], 1);
        } else {
            st[i + 1] = st[i];
        }
    }

    vector <int> left_bound(n), right_bound(n);

    forn(k, n) {

        // left bound
        {
            int L = 0, R = start[k];
            while (L < R) {
                int mid = (L + R) / 2;

                if (sa.getLcpForSuffixes(mid, start[k]) >= s[k].length()) {
                    R = mid;
                } else {
                    L = mid + 1;
                }
            }

            left_bound[k] = L;
        }

        // right bound
        {
            int L = start[k], R = z.size() - 1;
            while (L < R) {
                int mid = (L + R + 1) / 2;

                if (sa.getLcpForSuffixes(start[k], mid) >= s[k].length()) {
                    L = mid;
                } else {
                    R = mid - 1;
                }
            }

            right_bound[k] = L;
        }
    }


    while (q--) {
        int l = nxt() - 1;
        int r = nxt() - 1;
        int k = nxt() - 1;


        int ans = get_sum(st[right_bound[k] + 1], 0, n - 1, l, r) - get_sum(st[left_bound[k]], 0, n - 1, l, r);
        cout << ans << "\n";
    }

}


int main(int argc, char **argv) {
//    freopen("input", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ::TTT = 1;
//    nxt();
    pre();

    for (int test = 1; test <= ::TTT; ++test) {
//        cout << "Case #" << test << ": ";
        solve(test);
    }

    return 0;
}

#ifdef LOCAL

struct timer {
    clock_t init;

    timer() {
        init = clock();
    }

    clock_t time() const {
        return clock() - init;
    }

    ~timer() {
        cerr << "Time elapsed: " << (double) (time()) / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    }
};

#include <sys/resource.h>

struct init_str {
    timer t{};

    init_str() {
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    }

} init_global_;

#endif // LOCAL

//#define AUTO_MALLOC
#ifdef AUTO_MALLOC
namespace MALLOC {
    const size_t MAX_HEAP = 8 * 1000L * 1000 * 1000;
    char buf[MAX_HEAP];
    size_t ptr;
}

void *operator new(size_t size) {
    void *result = MALLOC::buf + MALLOC::ptr;
    MALLOC::ptr += size;
    return result;
}

void operator delete(void *ptr) noexcept { /* DO NOTHING */ }

#endif //AUTO_MALLOC

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

template<>
inline void input(string &a) {
    a.clear();
    static int ed;
    while (isspace(ed = getchar())) {}
    while (!isspace(ed) && ed != EOF) {
        a += (char) ed;
        ed = getchar();
    }
}

template<typename T>
inline T nxt() {
    T res;
    input(res);
    return res;
}


bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T, typename N>
T pw(T a, N n, T m) {
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