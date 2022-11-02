#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
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

template<typename T = int>
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

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}
struct node {
    map <int, long long> *data;
    long long addValue;
    int addKey;

    node() {
        data = new map<int, ll>();
        data->insert(mp(0, 0));
        addValue = 0;
        addKey = 0;
    }

    size_t size() {
        return data->size();
    }

    ll minValue() {
        return data->begin()->y + addValue;
    }
    ll minKey() {
        return data->begin()->x + addKey;
    }

    void pop() {
        data->erase(data->begin());
    }

    void insert(int key, ll value) {
        assert(!data->empty());
        auto insertKey = key - addKey;
        auto insertValue = value - addValue ;
        auto pos = data->lower_bound(insertKey);
        if (pos != data->end()) {
            if (pos->y <= insertValue) {
                goto l1;
            }
            if (pos->x == insertKey) {
                pos = data->erase(pos);
            }
        }
        if (pos == data->begin()) {
            data->insert(mp(insertKey, insertValue));
            goto l1;
        }
        --pos;
        while (pos != data->begin() && pos->y >= insertValue) {
            data->erase(pos--);
        }
        data->insert(mp(insertKey, insertValue));
        l1:;
    }
};

node merge(node a, node b) {
    if (a.size() > b.size()) {
        swap(a, b);
    }

    ll add = b.minValue();
    b.addValue += a.minValue();

    for (auto it : *a.data) {
        auto realValue = it.y + a.addValue + add;
        auto realKey = it.x + a.addKey;

        b.insert(realKey, realValue);
    }
    a.data->clear();
    return b;
}

vector <int> g[1 << 20];

vector <PII> c[1 << 20];

int h[1 << 20];

void NO() {
    cout << "-1\n";
    exit(0);
}

node dfs(int v, int p) {
    node cur = node();

    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        auto z = dfs(to, v);

        while (z.size() && z.minKey() < 1) {
            z.pop();
        }
        if (!z.size()) {
            NO();
        }
        z.addKey -= 1;
        cur = merge(cur, z);
    }

    for (auto x : c[v]) {
        int H = h[v] - h[x.x];
        ll cost = x.y + cur.minValue();
        cur.insert(H, cost);
    }

    return cur;
}

void solve(int test) {
    int n = nxt();
    int m = nxt();
    forn (i, n - 1) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }

    forn(i, m) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        int C = nxt();
        c[u].pb(mp(v, C));
    }
    h[0] = 0;
    cout << dfs(0, 0).minValue() << "\n";
}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
//    pre();
//    exit(0);
    int t = 1;

#ifdef LOCAL
#else
#endif
    int c = 0;

    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}