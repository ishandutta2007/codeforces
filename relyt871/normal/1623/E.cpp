#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

char s[MAXN], t[MAXN];
int n, k, lc[MAXN], rc[MAXN], fa[MAXN], dep[MAXN], top[MAXN];
int dfn[MAXN], clk, can[MAXN], tag[MAXN];

void DFS(int u) {
    if (lc[u]) {
        fa[lc[u]] = u;
        dep[lc[u]] = dep[u] + 1;
        top[lc[u]] = top[u];
        DFS(lc[u]);
    }
    dfn[++clk] = u;
    t[clk] = s[u];
    if (rc[u]) {
        fa[rc[u]] = u;
        dep[rc[u]] = dep[u] + 1;
        top[rc[u]] = u;
        DFS(rc[u]);
    }
}

void solve() {
    read(n); read(k);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        read(lc[i]); read(rc[i]);
    }
    dep[1] = 1;
    DFS(1);
    for (int i = n - 1; i >= 1; --i) {
        if (t[i] < t[i + 1] || (t[i] == t[i + 1] && can[i + 1])) {
            can[i] = 1;
        }
    }
    for (int i = 1; i <= n && k; ++i) {
        if (!can[i]) continue;
        int u = dfn[i];
        if (!tag[u] && (top[u] == 0 || tag[top[u]])) {
            int need = dep[u] - dep[top[u]];
            if (need <= k) {
                k -= need;
                for (int v = u; v != top[u]; v = fa[v]) {
                    tag[v] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        putchar(t[i]);
        if (tag[dfn[i]]) putchar(t[i]);
    }
    puts("");
}

int main() {
    solve();
    return 0;
}