#include <bits/stdc++.h>
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

const int N = 200005;
struct Edge {
	int to, nxt;
	Edge() {
		nxt = -1;
	}
};
int n, hd[N], pnt;
long long l[N], r[N];
pair <int, long long> dp[N];
Edge e[N << 1];

inline void AddEdge(int u, int v) {
	e[++pnt].to = v;
	e[pnt].nxt = hd[u];
	hd[u] = pnt;
}

inline void Read() {
	n = qread();
	pnt = 0;
	for (int i = 1;i <= n;i++) hd[i] = -1;
	for (int i = 2;i <= n;i++) AddEdge(qread(), i);
	for (int i = 1;i <= n;i++) {
		l[i] = qread(); r[i] = qread();
	}
}

inline void Dfs(int u) {
	int sum1 = 0;
	long long mxv = 0;
	long long sum2 = 0;
	for (int i = hd[u];~i;i = e[i].nxt) {
		Dfs(e[i].to);
		sum1 += dp[e[i].to].first;
		mxv = max(mxv, dp[e[i].to].second);
		sum2 += dp[e[i].to].second;
	}
	if (sum2 >= l[u]) dp[u] = make_pair(sum1, min(sum2, r[u]));
	else dp[u] = make_pair(sum1 + 1, r[u]);
}

int main() {
	int t = qread();
	while (t--) {
		Read();
		Dfs(1);
		cout << dp[1].first << endl;
	}
	return 0;
}