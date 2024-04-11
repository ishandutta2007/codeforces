#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = (1 << 20) + 5;
const int INF = 0x3f3f3f3f;

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

int n, len, k, a[MAXN], bit[MAXN], tot, id[MAXN], ID;

struct Data {
    int u, v, w;
    bool operator < (const Data &rhs) const {
        return w > rhs.w;
    }
} b[MAXN * 10];

int S, T, dis[MAXN], pre[MAXN], inq[MAXN];
queue<int> q;

struct Edge{
    int v, w, c, nxt;
} e[MAXN];
int first[MAXN], eCnt;

inline void AddEdge(int u, int v, int w, int c) {
    e[++eCnt].v = v;
    e[eCnt].w = w;
    e[eCnt].c = c;
    e[eCnt].nxt = first[u];
    first[u] = eCnt;
}

inline void Add(int u, int v, int w, int c) {
    AddEdge(u, v, w, c);
    AddEdge(v, u, 0, -c);
}

int Augment() {
    for (int i = 1; i <= T; ++i) {
        dis[i] = -INF;
        pre[i] = 0;
    }
    dis[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop(); inq[u] = 0;
        for (int i = first[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (e[i].w && dis[v] < dis[u] + e[i].c) {
                dis[v] = dis[u] + e[i].c;
                pre[v] = i;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    if (dis[T] <= -INF) return 0;
    for (int i = pre[T]; i; i = pre[e[i ^ 1].v]) {
        e[i].w -= 1;
        e[i ^ 1].w += 1;
    }
    return dis[T];
}

void solve() {
    read(n); read(k);
    len = (1 << n);
    for (int i = 0; i < len; ++i) {
        read(a[i]);
    }
    tot = 0;
    for (int i = 0; i < len; ++i) {
        bit[i] = bit[i >> 1] + (i & 1);
        if (bit[i] & 1) {
            for (int j = 0; j < n; ++j) {
                b[++tot] = (Data){i, i ^ (1 << j), a[i] + a[i ^ (1 << j)]};
            }
        }
    }
    int need = min((1 << n) * n / 2, (2 * n - 1) * (k - 1) + 1);
    nth_element(b + 1, b + need, b + tot + 1);
    for (int i = 1; i <= need; ++i) {
        if (!id[b[i].u]) id[b[i].u] = ++ID;
        if (!id[b[i].v]) id[b[i].v] = ++ID;
    }
    S = ++ID; T = ++ID;
    eCnt = 1;
    for (int i = 0; i < len; ++i) {
        if (!id[i]) continue;
        if (bit[i] & 1) {
            Add(S, id[i], 1, 0);
        } else {
            Add(id[i], T, 1, 0);
        }
    }
    for (int i = 1; i <= need; ++i) {
        Add(id[b[i].u], id[b[i].v], 1, b[i].w);
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += Augment();
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}