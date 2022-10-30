#include <bits/stdc++.h>
using namespace std;
#define N 1010

int runs, p[N], vis[N], cnt, a[N], b[N], c[N*N], n, k;

void get_prime() {
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		p[++runs] = i;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

void bunhae(int m) {
	cnt = 0;
	for (int i = 1; i <= runs && p[i] * p[i] <= m; i ++) {
		if (m % p[i] == 0) {
			a[++cnt] = p[i], b[cnt] = 0;
			while (m % p[i] == 0) m /= p[i], b[cnt] ++;
		}
	}
	if (m > 1) a[++cnt] = m, b[cnt] = 1;
}

int ord(int m, int p) {
	int rlt = 0;
	while (m % p == 0) m /= p, rlt ++;
	return rlt;
}

bool win() {
	bunhae(k);
	for (int i = 1; i <= cnt; i ++) {
		bool ok = 0;
		for (int j = 1; j <= n; j ++) {
			if (ord(c[j], a[i]) >= b[i]) {
				ok = 1; break;
			}
		}
		if (!ok) return 0;
	}
	return 1;
}

int main() {
//	freopen("b.in", "r", stdin);
	get_prime();
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	if (win()) puts("Yes");
	else puts("No");
	return 0;
}