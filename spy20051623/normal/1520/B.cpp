#include <bits/stdc++.h>

using namespace std;

long long mpow(int x) {
	long long r = 1;
	while (x--)
		r *= 10;
	return (r - 1) / 9;
}

void solve() {
	long long n;
	scanf("%lld", &n);
	int cnt = 0;
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			if (mpow(i) * j <= n)
				++cnt;
		}
	}
	printf("%d\n", cnt);
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