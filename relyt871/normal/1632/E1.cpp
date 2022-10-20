#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 3005;
 
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
 
int n, fa[MAXN], dep[MAXN], dep2[MAXN], mxd;
int s[MAXN], t;
vector<int> tree[MAXN];
 
struct Data {
    struct Node {
        int d, od;
        Node() {}
        Node(int _d, int _od): d(_d), od(_od) {}
        bool operator < (const Node &rhs) const {
            return d < rhs.d;
        }
    } a[MAXN];
 
    int len, ptr, suf[MAXN], mxdep;
 
    void build() {
        len = 0; ptr = 1;
        mxdep = 0;
        for (int i = 1; i <= n; ++i) {
            if (dep2[i] < dep[i]) {
                a[++len] = Node(dep[i] - dep2[i], dep[i]);
            } else {
                mxdep = max(mxdep, dep[i]);
            }
        }
        sort(a + 1, a + len + 1);
        suf[len + 1] = 0;
        for (int i = len; i >= 1; --i) {
            suf[i] = max(suf[i + 1], a[i].od - a[i].d);
        }
    }
 
    void update(int x) {
        while (ptr <= len && a[ptr].d <= x) {
            mxdep = max(mxdep, a[ptr].od);
            ++ptr;
        }
    }
 
    int getAns(int x) {
        return max(mxdep, x + suf[ptr]);
    }
} p[MAXN];
 
void DFS(int u) {
    mxd = max(mxd, dep[u]);
    for (auto v : tree[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        DFS(v);
    }
}
 
void DFS2(int u, int ff) {
    for (auto v : tree[u]) {
        if (v == ff) continue;
        dep2[v] = dep2[u] + 1;
        DFS2(v, u);
    }
}
 
void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
        fa[i] = dep[i] = 0;
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    mxd = 0;
    DFS(1);
    int leaf = 0;
    for (int i = 1; i <= n; ++i) {
        if (mxd == dep[i]) {
            leaf = i;
            break;
        }
    }
    t = 0;
    for (int u = leaf; u; u = fa[u]) {
        s[++t] = u;
    }
    for (int i = 1; i <= t; ++i) {
        dep2[s[i]] = 0;
        DFS2(s[i], 0);
        p[i].build();
    }
    for (int x = 1; x <= n; ++x) {
        int ans = mxd;
        for (int j = 1; j <= t; ++j) {
            p[j].update(x);
            ans = min(ans, p[j].getAns(x));
        }
        printf("%d ", ans);
    }
}
 
int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}