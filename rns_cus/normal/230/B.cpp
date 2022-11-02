#include <bits/stdc++.h>
using namespace std;
#define N 1001001

int p[N], vis[N], t, runs;
long long n;

void get_prime() {
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		p[++runs] = i;
		if (1ll * i * i >= N) continue;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

bool ok(long long n) {
	if (n == 1) return 0;
    int m = sqrt(1.0 * n);
    if (!vis[m] && 1ll * m * m == n) return 1;
    m ++;
    if (!vis[m] && 1ll * m * m == n) return 1;
    return 0;
}

int main() {
//	freopen("b.in", "r", stdin);
	get_prime();
	scanf("%d", &t);
	while (t --) {
		cin >> n;
		if (ok(n)) puts("YES");
		else puts("NO");
	}
}