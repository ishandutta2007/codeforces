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

void pre() {}

struct Node {
    int ch[2]{};
    int parent{};
    bool is_right_child{};
};

vector <Node> nodes;

int sz = 0;
inline int newNode(int parent, bool is_right_child) {
    int v = sz++;
    nodes.resize(v + 1);
    nodes[v].ch[0] = nodes[v].ch[1] = -1;
    nodes[v].parent = parent;
    nodes[v].is_right_child = is_right_child;

    return v;
}

void update(int v, ll tl, ll tr, ll l, ll r, vector <int> &res) {
    if (tl == l && tr == r) {
        res.push_back(v);
        return;
    }

    ll tm = (tl + tr) / 2;

    if (nodes[v].ch[0] == -1) {
        nodes[v].ch[0] = newNode(v, false);
    }
    if (nodes[v].ch[1] == -1) {
        nodes[v].ch[1] = newNode(v, true);
    }

    if (l < tm) {
        update(nodes[v].ch[0], tl, tm, l, min(r, tm), res);
    }

    if (r > tm) {
        update(nodes[v].ch[1], tm, tr, max(l, tm), r, res);
    }
}

int is_dead[1 << 23];

inline void traverse_leaves(int v, vector <int> &res) {
    if (nodes[v].ch[0] == -1) {
        if (!is_dead[v]) res.push_back(v);
        return;
    }

    traverse_leaves(nodes[v].ch[0], res);
    traverse_leaves(nodes[v].ch[1], res);
}

inline int find_path(int v, vector <int> &path) {
    int cur = v;
    if (path.empty()) return v;

    path.back() ^= 1;

    for (int i = (int)path.size() - 1; i >= 0; --i) {
        if (nodes[cur].ch[path[i]] == -1) break;
        cur = nodes[cur].ch[path[i]];
    }

    path.back() ^= 1;

    return cur;
}

inline void gen_edges(int v, vector<int> &to) {
    to.clear();
    static vector <int> path;
    path.clear();

    while (v != -1) {
        auto x = find_path(v, path);
        traverse_leaves(x, to);

        path.push_back(nodes[v].is_right_child);
        v = nodes[v].parent;
    }
}


int p[1 << 23];
int s[1 << 23];

inline int get(int v) {
    if (p[v] != v) {
        return p[v] = get(p[v]);
    }

    return v;
}

inline int unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return a;
    if (s[a] < s[b]) swap(a, b);

    p[b] = a;
    s[a] += s[b];
    return a;
}

int find(int v, ll tl, ll tr, ll pos) {
    if (nodes[v].ch[0] == -1 && nodes[v].ch[1] == -1) return v;

    ll tm = (tl + tr) / 2;
    if (pos < tm) {
        return find(nodes[v].ch[0], tl, tm, pos);
    } else {
        return find(nodes[v].ch[1], tm, tr, pos);
    }
}

void solve(int test_number) {
    int n = nxt();
    int m = nxt();

    int root = newNode(-1, false);

    vector <vector <int> > node_ids(m);
    vector <pair <ll, ll> > ab(m);
    forn(i, m) {
        string q;
        cin >> q;
        if (q == "ask") {
            ab[i].x = nxt();
            ab[i].y = nxt();
        } else {
            ll l = nxt();
            ll r = nxt() + 1;
            update(root, 0, 1ll << n, l, r, node_ids[i]);
            for (int x : node_ids[i]) is_dead[x] = 1;
        }
    }

    for (int i = 0; i < sz; ++i) {
        s[i] = 1;
        p[i] = i;
    }

    vector <int> z;

    for (int i = 0; i < sz; ++i) {
        if (nodes[i].ch[0] == -1 && nodes[i].ch[1] == -1 && !is_dead[i]) {
            gen_edges(i, z);

            for (int r : z) {
                unite(i, r);
            }
        }
    }

    vector <int> answers;

    for (int q = m - 1; q >= 0; --q) {
        if (node_ids[q].empty()) {
            auto [a, b] = ab[q];
            a = find(root, 0, 1ll << n, a);
            b = find(root, 0, 1ll << n, b);
            answers.push_back((get(a) == get(b)));
        } else {
            for (int i : node_ids[q]) {
                gen_edges(i, z);

                for (int r : z) {
                    unite(i, r);
                }

                is_dead[i] = 0;
            }
        }
    }

    reverse(all(answers));
    for (int x : answers) cout << x << "\n";

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
    const size_t MAX_HEAP = 256 * 1000 * 1000;
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