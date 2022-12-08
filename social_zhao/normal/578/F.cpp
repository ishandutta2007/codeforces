#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 405;
int n, m, P;
char s[N][N];
int fa[N * N], col[N * N];
int a[N][N];

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }
int id(int x, int y) { return (x - 1) * (m + 1) + y; }

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

int det(int n) {
	int ans = 1, tmp = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) if(a[j][i]) { tmp *= -1; swap(a[j], a[i]); break; }
		if(!a[i][i]) return 0;
		int t = qpow(a[i][i], P - 2);
		ans = (ans * a[i][i]) % P;
		for(int j = i; j <= n; j++) a[i][j] = a[i][j] * t % P;
		for(int j = i + 1; j <= n; j++) {
			t = -a[j][i];
			for(int k = i; k <= n; k++) a[j][k] = (a[j][k] + t * a[i][k] % P) % P;
		}
	}
	ans = ans * tmp % P;
	return (ans + P) % P;
}

signed main() {
//	freopen("data.out", "w", stdout);
	n = get(), m = get(), P = get();
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= (n + 1) * (m + 1); i++) fa[i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			int u, v;
			if(s[i][j] == '/') u = id(i, j + 1), v = id(i + 1, j);
			else if(s[i][j] == '\\') u = id(i, j), v = id(i + 1, j + 1);
			else continue;
			if(find(u) == find(v)) { printf("0\n"); return 0; }
			fa[find(u)] = find(v);
		}
	int tot, ans = 0;
	memset(a, 0, sizeof(a)), tot = 0;
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= m + 1; j++)
			if((((i + j) & 1) == 0) && fa[id(i, j)] == id(i, j))
				col[id(i, j)] = ++tot;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(s[i][j] != '*') continue;
			int u, v;
			if(((i + j) & 1) == 0) u = id(i, j), v = id(i + 1, j + 1);
			else u = id(i, j + 1), v = id(i + 1, j);
			u = col[find(u)], v = col[find(v)];
			a[u][u]++, a[v][v]++, a[u][v]--, a[v][u]--;
		}
//	for(int i = 1; i <= tot; i++, printf("\n"))
//		for(int j = 1; j <= tot; j++)
//			printf("%lld ", a[i][j]);
	ans = (ans + det(tot)) % P;
//	printf("%lld\n", tot);
	memset(a, 0, sizeof(a)), tot = 0;
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= m + 1; j++)
			if((((i + j) & 1) == 1) && fa[id(i, j)] == id(i, j))
				col[id(i, j)] = ++tot;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(s[i][j] != '*') continue;
			int u, v;
			if(((i + j) & 1) == 1) u = id(i, j), v = id(i + 1, j + 1);
			else u = id(i, j + 1), v = id(i + 1, j);
			u = col[find(u)], v = col[find(v)];
			a[u][u]++, a[v][v]++, a[u][v]--, a[v][u]--;
		}
	ans = (ans + det(tot)) % P;
	printf("%lld\n", ans);
	return 0;
}