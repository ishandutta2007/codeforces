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

long long mulmod(const long long &a, const long long &b) {
    long long ratio = (long double)a * b / mod;

    long long res = a * b - ratio * mod;

    while (res < 0) {
        res += mod;
    }
    while (res >= mod) {
        res -= mod;
    }
    return res;
}

long long addmod(const long long &a, const long long &b) {
    long long res = a + b;
    while (res >= mod) {
        res -= mod;
    }
    return res;
}

long long submod(const long long &a, const long long &b) {
    long long res = a - b;
    while (res < mod) {
        res += mod;
    }
    return res;
}

void fib(long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y = addmod(x, y);
    } else {
        long long a, b;
        fib(n / 2, a, b);
        long long u = mulmod(a, a);
        long long v = mulmod(a, b);
        long long w = mulmod(b, b);
        x = addmod(u, w);
        y = addmod(2 * v, w);
    }
}

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = mulmod(res, a);
        }
        a = mulmod(a, a);
        n >>= 1;
    }
    return res;
}

long long pw(long long a, long long n, long long m) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int alpha;

int isVowel[26];

string x;

int n;

vector <int> G[1000];

struct sat2 {
    int n;

    vector <vector <int> > g;
    vector <vector <int> > gr;
    vector <int> order;
    vector <int> comp;
    vector <int> used;

    sat2(int nn) {
        n = nn;
    }

    sat2(){

    }

    inline void init() {
        g.assign(n + n, vector <int>());
        gr.assign(n + n, vector <int>());
        used.assign(n + n, 0);
        comp.assign(n + n, -1);
        order.reserve(2 * n);
    }

    inline void add(int u, int v) {
        //cout << "E " << u << " " << v << "\n";
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    inline void dfs1(int v) {

        used[v] = 1;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs1(to);
            }
        }
        order.push_back(v);
    }

    inline void dfs2(int v, int c) {

        comp[v] = c;
        for (int to : gr[v]) {
            if (comp[to] == -1) {
                dfs2(to, c);
            }
        }
    }

    inline bool check() {
        order.clear();
        used.assign(2 * n, 0);
        for (int i = 0; i < 2 * n; ++i) {
            if (!used[i]) {
                dfs1(i);
            }
        }
        comp.assign(2 * n, -1);
        reverse(all(order));

        int c = 0;

        for (int x : order) {
            if (comp[x] == -1) {
                dfs2(x, c++);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (comp[i + i] == comp[i + i + 1]) {
                return false;
            }
        }
        return true;
    }
};

sat2 sat;

void init() {
    sat = sat2(n);
    sat.init();
    for (int i = 0; i < 2 * n; ++i) {
        for (int to : G[i]) {
            sat.add(i, to);
            sat.add(to ^ 1, i ^ 1);
        }
    }
}

bool checkPref(int len) {
    for (int i = 0; i < len; ++i) {
        sat.add(2 * i + !isVowel[x[i] - 'a'], 2 * i + isVowel[x[i] - 'a']);
    }
    bool res = sat.check();
    for (int i = 0; i < len; ++i) {
        sat.g[2 * i + !isVowel[x[i] - 'a']].pop_back();
        sat.gr[2 * i + isVowel[x[i] - 'a']].pop_back();
    }
    return res;
}

void rec(int pos) {
    if (pos == n) {
        cout << x << "\n";
        exit(0);
    }
    char used[2];
    clr(used);
    for (int j = 0; j < alpha; ++j) {
        if (used[isVowel[j]]) continue;
        x[pos] = 'a' + j;
        used[isVowel[j]] = 1;
        if (checkPref(pos + 1)) {
            rec(pos + 1);
        }
    }
    
    
}

void solve() {
    if (checkPref(n)) {
        cout << x << "\n";
        //cout << "OK" << "\n";
        return;
    }
    for (int len = n - 1; len >= 0; --len) {
        char t = x[len];
        char used[2];
        clr(used);
        for (int j = t - 'a' + 1; j < alpha; ++j) {
            if (used[isVowel[j]]) continue;
            x[len] = 'a' + j;
            used[isVowel[j]] = 1;
            if (checkPref(len + 1)) {
                rec(len + 1);
            }
        }
        x[len] = t;
    }
    cout << "-1\n";
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "carpet"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    string s;
    cin >> s;

    alpha = s.length();

    for (int i = 0; i < alpha; ++i) {
        isVowel[i] = s[i] == 'V';
    }

    n = nxt();
    int m = nxt();


    for (int i = 0; i < m; ++i) {
        int p1 = nxt() - 1;
        string s1;
        cin >> s1;
        int p2 = nxt() - 1;
        string s2;
        cin >> s2;
        p1 *= 2;
        p2 *= 2;

        if (s1 == "V") {
            p1++;
        }
        if (s2 == "V") {
            p2++;
        }
        G[p1].push_back(p2);
    }

    cin >> x;
    init();

    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}