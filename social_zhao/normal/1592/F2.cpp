#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505;
int n, m, a[N][N], bel[N], mat, vis[N], tim;
char s[N];
struct Edge { int v, nxt; } edge[N * N];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

int dfs(int u) {
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(vis[v] == tim) continue;
		vis[v] = tim;
		if(!bel[v] || dfs(bel[v])) { bel[v] = u; return 1; }
	}
	return 0;
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++) a[i][j] = s[j] == 'W'? 0 : 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = a[i][j] ^ a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
	int cnt = 0, ans = n * m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(i != n || j != m) cnt += a[i][j];
			if(i < n && j < m && a[n][j] && a[i][m] && a[i][j]) add(i, j);
		}
	for(int i = 1; i <= n; i++) tim = i, mat += dfs(i);
	for(int i = 0; i <= mat; i++) ans = min(ans, cnt - 3 * i + i * 2 + (a[n][m] ^ (i & 1)));
//	cout << ans;
	cout << cnt - mat + (a[n][m] ^ (mat & 1));
	return 0;
}