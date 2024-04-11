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

struct vertex {
    int l, r;
    int delta;
    int pos;
} data[1 << 20];

const int ss = 22222;

int sz = ss;

int NEW(int l, int r, int delta, int pos) {
    data[sz].l = l;
    data[sz].r = r;
    data[sz].delta = delta;
    data[sz].pos = pos;
    return sz++;
}

int NEW(int pos) {
    data[sz].l = data[sz].r = 0;
    data[sz].delta = 0;
    data[sz].pos = pos;
    return sz++;
}

int build(int tl, int tr) {
    if (tr - tl == 1)
        return NEW(tl);
    int tm = (tl + tr) / 2;
    return NEW(build(tl, tm), build(tm, tr), 0, 0);
}

int update(int t, int tl, int tr, int l, int r, int delta) {
    if (l >= r) return t;

    if (tl == l && tr == r) {
        return NEW(data[t].l, data[t].r, data[t].delta + delta, data[t].pos);
    }
    int tm = (tl + tr) / 2;
    return NEW(update(data[t].l, tl, tm, l, min(r, tm), delta),
               update(data[t].r, tm, tr, max(l, tm), r, delta), data[t].delta, data[t].pos);
}

struct Dinic {
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

    static const int INF = 0x7fffffff;
    static const int MAXN = 1 << 20, MAXE = 1 << 22;

    int src, snk, nNode, nEdge;
    int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
    int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

    inline void init(int _src, int _snk, int _n) {
        src = _src, snk = _snk, nNode = _n, nEdge = 0;
        SET(fin);
    }

    inline void add(int u, int v, int c) {
        assert(nEdge < MAXE);
        to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
        to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
    }

    bool bfs() {
        int st, en, i, u, v;
        SET(dist);
        dist[src] = st = en = 0;
        Q[en++] = src;
        while (st < en) {
            u = Q[st++];
            for (i = fin[u]; i >= 0; i = next[i]) {
                v = to[i];
                if (flow[i] < cap[i] && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    Q[en++] = v;
                }
            }
        }
        return dist[snk] != -1;
    }

    int dfs(int u, int fl) {
        if (u == snk) return fl;
        for (int &e = pro[u], v, df; e >= 0; e = next[e]) {
            v = to[e];
            if (flow[e] < cap[e] && dist[v] == dist[u] + 1) {
                df = dfs(v, min(cap[e] - flow[e], fl));
                if (df > 0) {
                    flow[e] += df;
                    flow[e ^ 1] -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    i64 dinitz() {
        i64 ret = 0;
        int df;
        while (bfs()) {
            memcpy(pro, fin, nNode * sizeof(fin[0]));
            while (true) {
                df = dfs(src, INF);
                if (df) ret += df;
                else break;
            }
        }
        return ret;
    }

#undef CLR
#undef SET
#undef i64
} d;

void solve(int test) {
    int n = nxt();
    int q = nxt();

    int N = n;
//    while (N < n) N <<= 1;

    vector<pii> add[n + 1];
    vector<pii> remove[n + 1];

    forn(i, q) {
        int x1 = nxt() - 1;
        int y1 = nxt() - 1;

        int x2 = nxt();
        int y2 = nxt();

        add[x1].push_back({y1, y2});
        remove[x2].push_back({y1, y2});
    }

    int nodes[n + 1];
    nodes[0] = build(0, N);

    forn(i, n) {
        int x = nodes[i];
        for (auto p : add[i]) {
            x = update(x, 0, N, p.x, p.y, 1);
        }
        for (auto p : remove[i]) {
            x = update(x, 0, N, p.x, p.y, -1);
        }
        nodes[i + 1] = x;
    }

    int s = n + n;
    int t = n + n + 1;


    d.init(s, t, sz);

    forn(i, n) {
        d.add(s, i, 1);
        d.add(n + i, t, 1);
        d.add(i, nodes[i + 1], n);
    }

    for (int i = ss; i < sz; ++i) {
        if (data[i].l) {
            if (data[i].delta == 0) {
                d.add(i, data[i].l, n);
                d.add(i, data[i].r, n);
            }
        } else {
            if (data[i].delta == 0 && data[i].pos < n) {
                d.add(i, n + data[i].pos, n);
            }
        }
    }
    cerr << d.nEdge << endl;
    int ans = d.dinitz();
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