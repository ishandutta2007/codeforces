#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, m, p[MAXN], vis[MAXN], rnk[MAXN], stk[MAXN], len;
vector<pii> e[MAXN];
vector<int> g[MAXN];
int deg[MAXN], q[MAXN], head, tail;

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(p[i]);
    }
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        e[u].push_back(make_pair(v, i));
        e[v].push_back(make_pair(u, i));
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (p[i] == i) continue;
        len = 0;
        for (int j = i; !vis[j]; j = p[j]) {
            stk[rnk[j] = ++len] = j;
            vis[j] = 1;
        }
        for (int j = 1; j <= len; ++j) {
            int x = stk[j];
            sort(e[x].begin(), e[x].end(), [&](pii &a, pii &b) {
                int da = (rnk[a.fi] - j + len) % len;
                int db = (rnk[b.fi] - j + len) % len;
                return da < db;
            });
            for (int k = 0; k < e[x].size() - 1; ++k) {
                int u = e[x][k].se, v = e[x][k + 1].se;
                g[u].push_back(v);
                ++deg[v];
            }
        }
    }
    head = 1, tail = 0;
    for (int i = 1; i <= m; ++i) {
        if (deg[i] == 0) {
            q[++tail] = i;
        }
    }
    while (head <= tail) {
        int u = q[head++];
        printf("%d ", u);
        for (auto v : g[u]) {
            if (--deg[v] == 0) {
                q[++tail] = v;
            }
        }
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}