#include <bits/stdc++.h>
using namespace std;
#define N 200200

typedef long long LL;

int n, m, a[N], b[N], d[N], e[N], mod, co[N];
map <int, int> vis;
LL f[N], g[N];
pair <int, int> c[N];

void prepare() {
	f[0] = 1;
	for (int i = 1; i < N; i ++) f[i] = f[i-1] * i % mod;
	g[1] = 1;
	for (int i = 3; i < N; i += 2) g[i] = g[i-2] * i % mod;
	for (int i = 2; i < N; i += 2) g[i] = g[i-1];
}

LL expmod(LL a, LL b) {
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

LL calc(int y, int x) {
	LL rlt = g[y] * f[y/2] % mod;
	return rlt * expmod(2, y / 2 - x) % mod;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), c[m++] = make_pair(a[i], i);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), c[m++] = make_pair(b[i], i);
	scanf("%d", &mod);
	prepare();
	sort(c, c + m);
	for (int i = 0; i < m; i ++) d[i] = c[i].first;
	m = unique(d, d + m) - d;
	int x = 0, T = 0;
	for (int i = 0; i < m; i ++) {
		T ++;
		for (int j = x; j < 2 * n; j ++) {
			if (c[j].first == d[i]) {
				e[i] ++;
				if (vis[c[j].second] == T) co[i] ++;
				vis[c[j].second] = T;
			}
			else {x = j; break;}
		}
	}
	long long ans = 1;
	for (int i = 0; i < m; i ++) {
		ans = ans * calc(e[i], co[i]) % mod;
	}
	cout << ans << endl;
	return 0;
}