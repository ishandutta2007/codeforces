#include <bits/stdc++.h>

using namespace std;

int n;
long long d[100005];

int lowbit(int x) {
	return x & -x;
}

void upd(int x, long long k) {
	for (int i = x; i <= n; i += lowbit(i)) {
		d[i] += k;
	}
}

long long sum(int x) {
	long long r = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		r += d[i];
	}
	return r;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int q;
	scanf("%d%d", &n, &q);
	getchar();
	for (int i = 1; i <= n; ++i) {
		int p = getchar() - 'a' + 1;
		upd(i, p);
	}
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", sum(r) - sum(l - 1));
	}
	return 0;
}