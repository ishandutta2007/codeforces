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



void pre() {
}


vector <int> g[1 << 20];

int ans;

int dfs(int v, int p) {
    vector <int> c;
    for (int to : g[v]) {
        if (to == p) continue;
        int res = 0;
        res = dfs(to, v);
        if (res) {
            c.push_back(res);
        }
    }
    if (c.size() == 0) {
        return 1;
    }
    if (c.size() == 1) {
        if (v == p) {
            ans += c[0];
        }
        return c[0] + 1;

    } else {
        int s = 0;
        for (int i = 0; i < c.size(); ++i) {
            s += c[i];
        }
        s -= c.size() - 2;
        ans += s;
        return 0;
    }
}

void read() {
    int n = nxt();
    int x = nxt();
    int y = nxt();
    for (int i = 1; i < n; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (x < y) {
        ans = 0;
        dfs(0, 0);
        cout << 1ll * (n - 1 - ans) * y + 1ll * ans * x << "\n";
    } else {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == n - 1) {
                ok = false;
            }
        }
        if (ok) {
            cout << 1ll * (n - 1) * y << endl;
        } else {
            cout << 1ll * (n - 2) * y + x << endl;
        }
    }
}

void solve2() { }


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "d"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
    pre();
#ifdef LOCAL
#endif
    int c = 0;
    while (t--) {
        read();
//        gen();
//        gen2();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}