#include <bits/stdc++.h>
using namespace std;
#define N 500100
#define inf 1000000000
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int n, x, y, k, p[N], hz[N];
vector <int> adj[2][N];
vector <pii> vec[2];

inline char nc() {
    static char buf[100000],*p1=buf,*p2=buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline void read(int &x) {
    char c = nc(), b = 1;
    for (; !(c >= '0' && c <= '9'); c = nc()) if (c == '-') b = -b;
    for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc()); x *= b;
}

inline void putint(int n) {
    int i = 16, a[i];
    do {
        a[-- i] = 48 + n % 10;
        n /= 10;
    } while (n);
    while (i < 16) pc(a[i++]);
}

inline void pput(int m, int n) {
    putint(m), pc(' ');
    putint(n), pc(' ');
}

void dfs(int u, int pa, int fg = 1) {
    int i, v, sz = adj[fg][u].size();
    for (i = 0; i < sz; i ++) {
        v = adj[fg][u][i];
        if (v == pa) continue;
        dfs(v, u, fg);
    }
    if (fg) p[u] = pa;
    else {
        if (p[u] != pa && p[pa] != u) {
            vec[0].pb(pii(u, pa));
            vec[1].pb(pii(hz[u], p[hz[u]]));
        }
        if (p[pa] == u) hz[pa] = hz[u];
    }
}

void put(int k) {
    for (int i = 0; i < 2; i ++)
        pput(vec[i][k].first, vec[i][k].second);
    puts("");
}

int main() {
    //freopen("1.in", "r", stdin);
    read(n);
    for (int i = 1; i <= n; i ++) hz[i] = i;
    for (int i = 1; i < n; i ++)
        read(x), read(y), adj[0][x].pb(y), adj[0][y].pb(x);
    for (int i = 1; i < n; i ++)
        read(x), read(y), adj[1][x].pb(y), adj[1][y].pb(x);
    dfs(1, 0);
    dfs(1, 0, 0);
    k = vec[0].size(); putint(k), pc('\n');
    for (int i = 0; i < k; i ++) put(i);

    return 0;
}