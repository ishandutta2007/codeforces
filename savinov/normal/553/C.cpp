#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
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
const long double PI = 3.1415926535897932384626433832795L;

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

mt19937 generator;

long long mod = 1000000007;

void fib(unsigned long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y += x;
        y %= mod;
    } else {
        long long a, b;
        fib(n / 2, a, b);
        x = (a * a + b * b) % mod;
        y = (2 * a + b) * b % mod;
    }
}

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int N = 100000;

int p[N];
int s[N];

void init() {
    for (int i = 0; i < N; ++i) {
        p[i] = i;
        s[i] = 1;
    }
}

int get(int v) {
    if (p[v] != v) {
        p[v] = get(p[v]);
    }
    return p[v];
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);

    if (a == b) {
        return;
    }

    if (s[a] > s[b]) {
        swap(a, b);
    }
    s[b] += s[a];
    p[a] = b;
}


vector <int> g[N];
int color[N];

void dfs(int v, int c) {
    color[v] = c;
    for (int to : g[v]) {
        if (color[to] == -1) {
            dfs(to, c ^ 1);
        } else {
            if (color[to] != (c ^ 1)) {
                cout << "0\n";
                exit(0);
            }
        }
    }
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    init();
    int n = nxt(), m = nxt();

    int f[m], t[m], c[m];
    for (int i = 0; i < m; ++i) {
        f[i] = nxt() - 1;
        t[i] = nxt() - 1;
        c[i] = nxt();
        if (c[i]) unite(f[i], t[i]);
    }

    vector <int> z;

    for (int i = 0; i < m; ++i) {
        if (!c[i]) {
            int u = get(f[i]);
            int v = get(t[i]);
            if (u == v) {
                cout << "0\n";
                return 0;
            }
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    for (int i = 0; i < n; ++i) {
        z.push_back(get(i));
    }

    sort(all(z));

    z.erase(unique(all(z)), z.end());
    memset(color, 255, sizeof(color));

    long long ans = (mod + 1) / 2;

    for (int x : z) {
        if (color[x] == -1) {
            ans = ans * 2 % mod;
            dfs(x, 0);
        }
    }

    cout << ans << "\n";




#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}