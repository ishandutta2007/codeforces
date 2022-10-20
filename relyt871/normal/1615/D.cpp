#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
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

inline int Count(int x) {
    int ret = 0;
    while (x) {
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}

int n, m, col[MAXN], flag;
vector<pii> tree[MAXN], g[MAXN];
vector< pair<pii, int> > ans;

void DFS(int u, int c) {
    col[u] = c;
    for (auto e : g[u]) {
        int v = e.fi, r = e.se;
        if (col[v] == -1) {
            DFS(v, c ^ r);
        } else if (r == (col[u] == col[v])) {
            flag = 0;
        }
    }
}

void GetAns(int u, int fa) {
    for (auto e : tree[u]) {
        int v = e.fi, num = e.se;
        if (v == fa) continue;
        if (num == -1) {
            num = (col[u] != col[v]);
        }
        ans.push_back(MP(MP(u, v), num));
        GetAns(v, u);
    }
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        col[i] = -1;
        tree[i].clear();
        g[i].clear();
    }
    for (int i = 1, x, y, v; i < n; ++i) {
        read(x); read(y); read(v);
        tree[x].push_back(MP(y, v));
        tree[y].push_back(MP(x, v));
        if (v != -1) {
            int cnt = Count(v);
            g[x].push_back(MP(y, cnt & 1));
            g[y].push_back(MP(x, cnt & 1));
        }
    }
    for (int i = 1, x, y, p; i <= m; ++i) {
        read(x); read(y); read(p);
        g[x].push_back(MP(y, p));
        g[y].push_back(MP(x, p));
    }
    flag = 1;
    for (int i = 1; i <= n; ++i) {
        if (col[i] == -1) {
            DFS(i, 0);
            if (!flag) {
                puts("NO");
                return;
            }
        }
    }
    ans.clear();
    GetAns(1, 0);
    puts("YES");
    for (auto e : ans) {
        printf("%d %d %d\n", e.fi.fi, e.fi.se, e.se);
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}