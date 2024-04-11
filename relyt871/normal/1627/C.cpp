#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 55;
const int MAXN = 100005;

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

int n, deg[MAXN], ans[MAXN];
vector< pair<int, int> > tree[MAXN];

void DFS(int u, int fa, int d) {
    for (auto e : tree[u]) {
        if (e.first == fa) continue;
        ans[e.second] = 2 + d;
        DFS(e.first, u, d ^ 1);
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n ;++i) {
        deg[i] = 0;
        tree[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(make_pair(v, i));
        tree[v].push_back(make_pair(u, i));
        ++deg[u]; ++deg[v];
    }
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 2) {
            flag = 0;
            break;
        }
    }
    if (!flag) {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            DFS(i, 0, 0);
            for (int j = 1; j < n; ++j) {
                printf("%d ", ans[j]);
            }
            printf("\n");
            return;
        }
    }
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}