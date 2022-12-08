#include <bits/stdc++.h>

using namespace std;

int x[20];
int res[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

int calc(int k) {
	int tmp = 1;
	for (int i = 0; i < 10; ++i) {
		int p = x[i];
		if (k & 1 << i) --p;
		if (k & 1 << (i + 2)) p += 10;
		if (p < 0) return 0;
		tmp *= res[p];
	}
	return tmp;
}

void solve() {
	memset(x, 0, sizeof x);
	int n;
	scanf("%d", &n);
	int pos = 0;
	while (n) {
		x[pos++] = n % 10;
		n /= 10;
	}
	long long ans = -2;
	for (int i = 0; i < 1 << pos; i += 4) {
		ans += calc(i);
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}