#include <bits/stdc++.h>

using namespace std;

int a[200005];
int b[200005];
map<int, int> c;

void solve() {
	int n;
	scanf("%d", &n);
	c.clear();
	int minm = 0x3f3f3f3f;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		minm = min(minm, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		b[i] = a[i] - minm - i;
		++c[b[i]];
	}
	long long sum = 0;
	for (auto &i : c) {
		sum += 1LL * i.second * (i.second - 1) / 2;
	}
	printf("%lld\n", sum);
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