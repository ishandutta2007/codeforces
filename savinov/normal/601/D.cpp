#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
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

string s;
int a[1 << 20];

long long m1 = 1000000007;
long long m2 = 1000000009;

long long H[1 << 20];

vector <int> g[1 << 20];

void dfs(int v, int p, long long h1, long long h2) {
    h1 = h1 * 31 + s[v] - 'a' + 1;
    h2 = h2 * 29 + s[v] - 'a' + 1;
    h1 %= m1;
    h2 %= m2;

    H[v] = (h1 << 30) | h2;

    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v, h1, h2);
    }
}

set <long long > * merge(set <long long > * a, set <long long > * b) {
    if (a->size() > b->size()) {
        swap(a, b);
    }
    for (auto v : *a) {
        b->insert(v);
    }
    delete a;
    return b;
}

int best = 0;
int cnt = 0;

set <long long> * dfs(int v, int p) {
    set <long long> * res = new set <long long>();

    res->insert(H[v]);

    for (int to : g[v]) {
        if (to == p) continue;
        auto q = dfs(to, v);
        res = merge(q, res);
    }

    if (res->size() + a[v] > best) {
        best = res->size() + a[v];
        cnt = 1;
    }  else if (res->size() + a[v] == best) {
        ++cnt;
    }
    return res;
}

void solve(int test) {
    int n = nxt();
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }
    cin >> s;
    for (int i = 1; i < n; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0, 0, 0);
    dfs(0, 0);

    cout << best << "\n" << cnt << "\n";
}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    //test();
#ifdef LOCAL
    int t = 1;
#else
    int t = 1;
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