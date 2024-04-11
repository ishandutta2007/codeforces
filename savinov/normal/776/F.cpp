//
//
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


//ll f[(1 << 18) + 1];

void pre() {
//    f[0] = 1;
//    forn(i, (1 << 18)) {
//        f[i + 1] = f[i] * (i + 1) % mod;
//    }
}

set <pair <int, int> > edges;

vector <int> ord[1 << 20];

struct graph {
    vector <vector <int> > g;
    vector <int> size;
    vector <int> par;
    vector <int> id;

    graph(int n) {
        g.resize(n);
        size.resize(n);
        par.assign(n, -1);
        id.resize(n);
    }

    void addEdge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(int v, int p) {
        size[v] = 1;
        for (int to : g[v]) {
            if (to == p) continue;
            if (par[to] != -1) continue;
            dfs(to, v);
            size[v] += size[to];
        }
    }

    void centroid(int v, int p, int n, int prev, int x) {
        for (int to : g[v]) {
            if (to == p) continue;
            if (par[to] != -1) continue;
            if (2 * size[to] > n) {
                centroid(to, v, n, prev, x);
                return;
            }
        }

        par[v] = prev;
        id[v] = x;

        //I'm center =)

        for (int to : g[v]) {
            if (par[to] == -1) {
                dfs(to, to);
                centroid(to, v, size[to], v, x + 1);
            }
        }
    }

    void init() {
        dfs(0, 0);
        centroid(0, 0, g.size(), -2, 1);
    }

};

void solve(int test) {
    int n = nxt();
    int m = nxt();

    forn(i, n) {
        ord[i].push_back((i + 1) % n);
        ord[(i + 1) % n].push_back(i);
        edges.insert({i, (i + 1) % n});
    }

    forn(i, m) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        ord[a].push_back(b);
        ord[b].push_back(a);

        edges.insert({a, b});
        edges.insert({b, a});
    }
    forn(i, n) {
        sort(all(ord[i]));
    }

    vector <pii> path;

    vector <vector <pii> > faces;


    path.push_back(*edges.begin());
    edges.erase(edges.begin());

    while (!edges.empty()) {

        int cur = path.back().y;
        int prev = path.back().x;

        int pos = lower_bound(all(ord[cur]), prev) - ord[cur].begin();
        pos = (pos + ord[cur].size() - 1) % ord[cur].size();

        int nex = ord[cur][pos];

        assert(edges.count({cur, nex}));
        edges.erase({cur, nex});

        path.push_back({cur, nex});

        if (nex == path[0].x) {
            faces.push_back(path);
            path.clear();

            if (!edges.empty()) {
                path.push_back(*edges.begin());
                edges.erase(edges.begin());
            }
        }
    }

    vector <vector <int> > q;

    for (auto face : faces) {
        vector <int> v;
        for (auto t : face) {
            v.push_back(t.x);
        }
        sort(all(v), greater <int>());
        v.erase(unique(all(v)), v.end());
        q.push_back(v);
    }

//    for (auto e : faces) {
//        for (auto t : e) {
//            cerr << "{" << t.x << ", " << t.y << "} ";
//        }
//        cerr << endl;
//    }

    vector <int> order(q.size());

    iota(all(order), 0);

    sort(all(order), [&](int a, int b) {
        return q[a] < q[b];
    });

    map <pii, int> G;

    for (int i = 0; i < q.size(); ++i) {
        int o = order[i];
        for (auto e : faces[o]) {
            G[{e.y, e.x}] = i;
        }
    }

    graph GG(q.size());

    for (int i = 0; i < q.size(); ++i) {
        int o = order[i];
        for (auto e : faces[o]) {
            if (G.count({e.x, e.y}) && i < G[{e.x, e.y}]) {
                GG.addEdge(i, G[{e.x, e.y}]);
            }
        }
    }

//    forn(i, q.size()) {
//        for (int x : q[i]) {
//            cerr << x << " ";
//        }
//        cerr << endl;
//    }
    GG.init();

    forn(i, q.size()) {
        cout << GG.id[i] << " ";
    }

    cout << "\n";

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