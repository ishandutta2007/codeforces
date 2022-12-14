#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pc putchar

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void wt(int x) {
	if (x >= 10) wt(x / 10);
	pc(x % 10 + 48);
}

const int N = 2e5 + 10;

int n, m, f[N], p[N], a[N], v[N], tot;
vector <int> e[N];

void exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, x, y);
	int t = x;
	x = y, y = t - a / b * y;
}

int dfs(int u) {
	if (f[u]) return f[u];
	int W = e[u].size(); f[u] = W;
	for (int i = u + u; i <= m; i += u) {
		if (!e[i].size()) continue;
		int t = dfs(i);
		if (f[u] < t + W) f[u] = t + W, p[u] = i;
	}
	return f[u];
}

int main() {
	n = rd(), m = rd();
	for (int i = 1; i <= n; i ++) v[rd()] = 1;
	for (int i = 0; i < m; i ++) if(!v[i]) e[__gcd(i, m)].pb(i);
	dfs(1);
	wt(f[1]), pc(10);
	int u = 1;
	while (u) {
		int t = e[u].size();
		for (int i = 0; i < t; i ++) a[++tot] = e[u][i];
		u = p[u];
	}
	wt(a[1]), pc(32);
	for (int i = 2, x, y, A, B, g; i <= tot; i ++) {
		A = a[i - 1], B = a[i];
		g = __gcd(A, m);
		exgcd(A / g, m / g, x, y);
		x = (x % m + m) % m;
		wt(1ll * B / g * x % m), pc(32);
	}
	return 0;
}