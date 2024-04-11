#include "bits/stdc++.h"

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

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

mt19937 generator;

const int N = 200000;

vector <int> g[N];

vector <long long> p1[N];

vector <long long> p2[N];

long long dp1[N];
long long dp2[N];

const long long mod = 1000000007;

void dfs(int v) {
    dp1[v] = 1;

    p1[v].resize(g[v].size() + 1);
    p2[v].resize(g[v].size() + 1);

    p1[v][0] = 1;
    p2[v][g[v].size()] = 1;

    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];

        dfs(to);

        dp1[v] *= (1 + dp1[to]);
        dp1[v] %= mod;
        p1[v][i + 1] = 1 + dp1[to];
        p2[v][i] = 1 + dp1[to];
    }

    for (int i = 0; i < (int)g[v].size(); ++i) {
        p1[v][i + 1] *= p1[v][i];
        p1[v][i + 1] %= mod;
    }
    for (int i = (int)g[v].size() - 1; i >= 0; --i) {
        p2[v][i] *= p2[v][i + 1];
        p2[v][i] %= mod;
    }
}

long long ans[N];

void dfs2(int v, long long up) {
    ans[v] = up * dp1[v] % mod;

    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        dfs2(to, 1 + up * p1[v][i] % mod * p2[v][i + 1] % mod);
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

    int n = nxt();

    for (int i = 1; i < n; ++i) {
        g[nxt() - 1].push_back(i);
    }

    dfs(0);
    dfs2(0, 1);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }

    cout << "\n";


    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}