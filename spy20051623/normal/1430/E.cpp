#include <bits/stdc++.h>

using namespace std;

char s[200005];
int d[200005];
int n;

int lowbit(int x) { return x & -x; }

void upd(int x, int k) { for (; x <= n; x += lowbit(x)) d[x] += k; }

int sum(int x) {
	int r = 0;
	for (; x > 0; x -= lowbit(x)) r += d[x];
	return r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	scanf("%s", s + 1);
	queue<int> q[26];
	for (int i = 1; i <= n; ++i) {
		q[s[i] - 'a'].push(i);
		upd(i, 1);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		int p = q[s[n + 1 - i] - 'a'].front();
		q[s[n + 1 - i] - 'a'].pop();
		ans += sum(p) - 1;
		upd(p, -1);
	}
	printf("%lld\n", ans);
	return 0;
}