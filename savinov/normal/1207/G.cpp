#ifdef LOCAL
#include <stdint.h>
#include <inttypes.h>
#include <sys/resource.h>
struct ___ { ___(){ rlimit R{}; getrlimit(RLIMIT_STACK, &R); R.rlim_cur = R.rlim_max; setrlimit(RLIMIT_STACK, &R); }} ___;
#endif

#include <bits/stdc++.h>
#pragma GCC target ("avx")

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

#ifdef AUTO_MALLOC
namespace MALLOC { const size_t MAX_HEAP = 256 * 1000 * 1000; char buf[MAX_HEAP]; size_t ptr; }
void* operator new(size_t size) { void *result = MALLOC::buf + MALLOC::ptr; MALLOC::ptr += size; return result; }
void operator delete(void *ptr) noexcept { /* DO NOTHING */ }
#endif //AUTO_MALLOC


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

template<typename T>
T pw(T a, T n, T m);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);


void pre() {}

int TTT;

struct Node {
    Node *to[26];
    vector <int> v;
};

Node *nodes[1 << 19];

void add(int id, int p, char c) {
    Node *x = nodes[p];

    if (!x->to[c - 'a']) {
        x->to[c - 'a'] = new Node();
    }

    Node *y = x->to[c - 'a'];

    nodes[id] = y;
    y->v.push_back(id);
}

struct vertex {
    int next[26];
    int p;
    char pch;
    int link;
    int go[26];
};

vertex t[1u << 19];
int sz;

void init() {
    t[0].p = t[0].link = -1;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}

int add_string (const string & s) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = s[i]-'a';
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            memset (t[sz].go, 255, sizeof t[sz].go);
            t[sz].link = -1;
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    return v;
}

int go (int v, char c);

int get_link (int v) {
    if (t[v].link == -1)
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go (get_link (t[v].p), t[v].pch);
    return t[v].link;
}

int go (int v, char c) {
    if (t[v].go[c] == -1)
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
    return t[v].go[c];
}

struct query {
    int id;
    int pos;
    int vid;
};

struct TreeAdd {
    vector <vector <int>> g;
    vector <int> tin;
    vector <int> tout;
    vector <int> st;
    int timer;
    int n;
    TreeAdd(int n) : n(n) {
        g.resize(n);
        tin.resize(n);
        tout.resize(n);
        st.resize(n + n);
        timer = 0;
    }

    void add_edge(int p, int v) {
        g[p].push_back(v);
    }

    void dfs(int v) {
        tin[v] = timer++;
        for (int to : g[v]) {
            dfs(to);
        }
        tout[v] = timer - 1;
    }

    void add(int v, int delta) {
        v = tin[v];
        for (v += n; v; v >>= 1) {
            st[v] += delta;
        }
    }

    int get(int v) {
        int res = 0;
        for (int l = tin[v] + n, r = tout[v] + n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) res += st[l];
            if (!(r & 1)) res += st[r];
        }
        return res;
    }

    void build() {
        dfs(0);
    }
};

void solve(int) {
    int n = nxt();
    nodes[0] = new Node();

    forn(i, n) {
        int t = nxt();
        int r = 0;
        if (t == 2) {
            r = nxt();
        }

        string c;
        cin >> c;

        add(i + 1, r, c[0]);
    }

    int m = nxt();

    vector <query> q(m);

    init();
    forn(i, m) {
        q[i].id = i;
        q[i].pos = nxt();
        string p;
        cin >> p;
        q[i].vid = add_string(p);
    }

    TreeAdd ta(sz);

    for (int i = 1; i < sz; ++i) {
        ta.add_edge(get_link(i), i);
    }
    ta.build();

    vector <vector <int> > qbypos(n + 1);
    for (auto qq : q) {
        qbypos[qq.pos].push_back(qq.id);
    }

    vector <int> answer(m);


    function<void(Node *, int)> dfs = [&](const Node *x, int cur) {
        ta.add(cur, 1);
        for (auto v : x->v) {
            for (auto qq : qbypos[v]) {
                answer[qq] = ta.get(q[qq].vid);
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (x->to[i]) {
                dfs(x->to[i], go(cur, i));
            }
        }
        ta.add(cur, -1);
    };

    dfs(nodes[0], 0);

    for (auto a : answer) {
        cout << a << "\n";
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
    ::TTT = 1;

    pre();

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