#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n, a[N], b[N];

long long s[N];

int t[N];

void add(int i, int j) {
	t[i-1] ++;
	t[j] --;
}

long long ans[N];

void solve() {
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += t[i-1];
		ans[i] += 1ll * sum * b[i];
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + b[i];
	for (int i = 1; i <= n; i ++) {
		if (!a[i]) continue;
		int j = lower_bound(s + 1, s + n + 1, s[i-1] + a[i]) - s;
		j --;
		add(i, j);
		ans[j+1] += s[i-1] + a[i] - s[j];
	}
	solve();
	for (int i = 1; i <= n; i ++) printf("%I64d ", ans[i]);
	puts("");

	return 0;
}