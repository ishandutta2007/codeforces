#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = (1 << 18) + 5;
const int MOD = 998244353;

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

int n, a[MAXN], b[MAXN];
bool vis[MAXN], instk[MAXN], ans;
vector<int> g[MAXN];

void DFS(int u) {
    vis[u] = 1;
    instk[u] = 1;
    for (auto v : g[u]) {
        if (instk[v]) {
            ans = 0;
        }
        if (!vis[v]) {
            DFS(v);
        }
    }
    instk[u] = 0;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        g[a[i]].push_back(b[i]);
    }
    int mxp = 1;
    for (int i = 2; i <= n; ++i) {
        if(g[i].size() > g[mxp].size()) {
            mxp = i;
        }
    }
    vis[mxp] = 1;
    ans = 1;
    for (int i = 1; i <= n && ans; ++i) {
        if (!vis[i]) {
            DFS(i);
        }
    }
    puts(ans? "AC" : "WA");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}