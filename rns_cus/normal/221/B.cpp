#include <bits/stdc++.h>
using namespace std;
#define N 40040

bool vis[N], flag[N];
int p[N], runs, cnt, a[N], b[N], x, ans;
vector <int> v;

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
			while (m % p[i] == 0) b[cnt] ++, m /= a[cnt];
		}
	}
	if (m > 1) a[++cnt] = m, b[cnt] = 1;
}

void prepare(int x) {
	while (x) flag[x%10] = 1, x /= 10;
}

bool ok(int x) {
	while (x) {
		if (flag[x%10]) return 1;
		x /= 10;
	}
	return 0;
}

int main() {
//	freopen("b.in", "r", stdin);
	get_prime();
	scanf("%d", &x);
	prepare(x);
	bunhae(x);
	v.push_back(1);
	for (int i = 1; i <= cnt; i ++) {
		int step = v.size();
        x = 1;
		for (int k = 1; k <= b[i]; k ++) {
			x *= a[i];
			for (int j = 0; j < step; j ++) v.push_back(v[j] * x);
		}
	}
	for (int i = 0; i < v.size(); i ++) if (ok(v[i])) ans ++;
	printf("%d\n", ans);
	return 0;
}