#include <bits/stdc++.h>
using namespace std;
#define mod 1073741824
#define N 111

bool vis[N];
int a, b, c, p[N], runs, cnt, x[N], y[N];

void get_prime() {
	for (int i = 2; i <= 100; i ++) {
		if (vis[i]) continue;
		p[++runs] = i;
		for (int j = i * i; j <= 100; j += i) vis[j] = 1;
	}
}

void bunhae(int n) {
	cnt = 0;
	for (int i = 1; i <= runs && p[i] * p[i] <= n; i ++) {
		if (n % p[i] == 0) {
			x[++cnt] = p[i], y[cnt] = 0;
			while (n % x[cnt] == 0) n /= x[cnt], y[cnt] ++;
		}
	}
	if (n > 1) x[++cnt] = n, y[cnt] = 1;
}

long long calc(int n) {
	bunhae(n);
	long long rlt = 1;
	for (int i = 1; i <= cnt; i ++) rlt = rlt * (y[i] + 1) % mod;
	return rlt;
}

int main() {
//	freopen("b.in", "r", stdin);
	get_prime();
	scanf("%d %d %d", &a, &b, &c);
	long long ans = 0;
	for (int i = 1; i <= a; i ++) {
		for (int j = 1; j <= b; j ++) {
			for (int k = 1; k <= c; k ++) ans = (ans + calc(i * j * k)) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}