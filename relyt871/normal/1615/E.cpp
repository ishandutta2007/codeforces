#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

int n, k, dep[MAXN], mxd[MAXN], son[MAXN];
int chain[MAXN], tot;
vector<int> tree[MAXN];

void DFS1(int u, int fa) {
    mxd[u] = dep[u];
    for (auto v : tree[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        DFS1(v, u);
        if (mxd[u] < mxd[v]) {
            mxd[u] = mxd[v];
            son[u] = v;
        }
    }
}

void DFS2(int u, int fa, bool flag) {
    if (flag) chain[++tot] = mxd[u] - dep[u] + 1;
    if (son[u]) DFS2(son[u], u, 0);
    for (auto v : tree[u]) {
        if (v == fa || v == son[u]) continue;
        DFS2(v, u, 1);
    }
}

void solve() {
    read(n); read(k);
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS1(1, 0);
    DFS2(1, 0, 1);
    if (k >= tot) {
        LL ans = -INF;
        for (int i = tot; i <= k; ++i) {
            ans = max(ans, 1LL * i * (n - i));
        }
        printf("%lld\n", ans);
        return;
    }
    sort(chain + 1, chain + tot + 1);
    int blue = 0;
    for (int i = 1; i <= tot - k; ++i) {
        blue += chain[i];
    }
    LL ans = INF;
    for (int i = 0; i <= blue; ++i) {
        ans = min(ans, 1LL * (n - i - k) * (k - i));
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}