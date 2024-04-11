#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

struct Edge {
	int to, nxt;
	Edge() {
		nxt = -1;
	}
};
Edge e[400005];
int hd[200005], pnt, n, k, siz[200005], mrk[200005], dep[200005];
long long ans, tmp[200005];

inline void AddEdge(int u, int v) {
	e[++pnt].to = v;
	e[pnt].nxt = hd[u];
	hd[u] = pnt;
}

inline void Read() {
	n = qread();
	k = qread();
	for (register int i = 1;i < n;i++) {
		register int u = qread(), v = qread();
		AddEdge(u, v);
		AddEdge(v, u);
	}
}

inline void Dfs(int u, int fa) {
	siz[u] = 1;
	for (register int i = hd[u];~i;i = e[i].nxt) {
		if (e[i].to != fa) {
			dep[e[i].to] = dep[u] + 1;
			Dfs(e[i].to, u);
			siz[u] += siz[e[i].to];
		}
	}
}

inline void Dfs2(int u, int fa, long long cnt) {
	if (mrk[u]) ans += cnt;
	for (register int i = hd[u];~i;i = e[i].nxt) {
		if (e[i].to != fa) Dfs2(e[i].to, u, cnt + (!mrk[u]));
	}
}

inline void Solve() {
	for (register int i = 1;i <= n;i++) tmp[i] = dep[i] - siz[i] + 1;
	sort(tmp + 1, tmp + n + 1, greater <int>());
	for (register int i = 1;i <= k;i++) ans += tmp[i];
	printf("%lld", ans);
}

int main() {
	memset(hd, -1, sizeof(hd));
	Read();
	Dfs(1, -1);
	Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}