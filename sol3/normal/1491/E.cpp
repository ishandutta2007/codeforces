#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
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
int n, hd[200005], pnt, idx[200005], fib[35], siz[200005];
bool book[400005];

inline void AddEdge(int u, int v) {
	e[pnt].to = v;
	e[pnt].nxt = hd[u];
	hd[u] = pnt;
	pnt++;
}

inline void Read() {
	n = qread();
	for (int i = 1;i < n;i++) {
		int u = qread(), v = qread();
		AddEdge(u, v);
		AddEdge(v, u);
	}
}

inline void Prefix() {
	int x = 1, y = 2, z;
	idx[1] = 1;
	idx[2] = 2;
	fib[1] = 1;
	fib[0] = 1;
	fib[2] = 2;
	for (int i = 3;;i++) {
		z = x + y;
		if (z > 200000) break;
		idx[z] = i;
		fib[i] = z;
		x = y;
		y = z;
	}
}

inline void Dfs1(int u, int fa) {
	siz[u] = 1;
	for (int i = hd[u];~i;i = e[i].nxt) {
		if (book[i]) continue;
		if (e[i].to != fa) {
			Dfs1(e[i].to, u);
			siz[u] += siz[e[i].to];
		}
	}
}

inline void Link(int u, int v) {
	siz[u] += siz[v];
}

inline void Cut(int u, int v) {
	siz[u] -= siz[v];
}

inline pair <int, pair <int, int> > Dfs2(int u, int fa) {
	for (int i = hd[u];~i;i = e[i].nxt) {
		if (book[i]) continue;
		if (e[i].to == fa) continue;
		if (idx[siz[e[i].to]] == idx[siz[u]] - 1 || idx[siz[e[i].to]] == idx[siz[u]] - 2) {
			return make_pair(i, make_pair(u, e[i].to));
		}
	}
	for (int i = hd[u];~i;i = e[i].nxt) {
		if (book[i]) continue;
		if (e[i].to == fa) continue;
		Cut(u, e[i].to);
		Link(e[i].to, u);
		pair <int, pair <int, int> > ans = Dfs2(e[i].to, u);
		if (ans.first != -1) return ans;
		Cut(e[i].to, u);
		Link(u, e[i].to);
	}
	return make_pair(-1, make_pair(-1, -1));
}

inline bool Solve(int rt) {
	Dfs1(rt, -1);
	if (siz[rt] == 1) return 1;
	if (!idx[siz[rt]]) return 0;
	pair <int, pair <int, int> > ans = Dfs2(rt, -1);
	if (ans.first == -1) return 0;
	book[ans.first] = book[ans.first ^ 1] = 1;
	return Solve(ans.second.first) && Solve(ans.second.second);
}

int main() {
	memset(hd, -1, sizeof(hd));
	Read();
	Prefix();
	if (Solve(1)) puts("YES");
	else puts("NO");
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}