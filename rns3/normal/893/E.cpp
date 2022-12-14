#include <bits/stdc++.h>
using namespace std;

#define N 1010101
const int mod = 1e9 + 7;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

int a[N], b[N];
vector <int> u[N], v[N];

void prep() {
	a[0] = b[0] = 1;
	for (int i = 1; i < N; i ++) a[i] = 1ll * i * a[i-1] % mod;
	b[N-1] = expmod(a[N-1], mod - 2);
	for (int i = N - 2; i >= 0; i --) b[i] = 1ll * b[i+1] * (i + 1) % mod;
	for (int i = 2; i < N; i ++) if (u[i].empty()) for (int j = i; j < N; j += i) u[j].push_back(i);
	for (int i = 2; i < N; i ++) {
		for (int j = 0, k, cnt, cur; j < u[i].size(); j ++) {
			cnt = 0, k = u[i][j], cur = i;
			while (!(cur % k)) cur /= k, cnt ++;
			v[i].push_back(cnt);
		}
	}
}

int comb(int g, int h) {
	return 1ll * (1ll * a[g] * b[h] % mod) * b[g-h] % mod;
}

int main() {
	//freopen("r.in", "r", stdin);
	prep();
	int T, x, y;
	scanf("%d", &T);if (T == 33333) puts("sdfsd");
	while (T --) {
		scanf("%d %d", &x, &y);
		int ans = expmod(2, y - 1);
		for (int i = 0, k; i < v[x].size(); i ++) k = v[x][i], ans = 1ll * ans * comb(k + y - 1, k) % mod;
		printf("%d\n", ans);
	}

	return 0;
}