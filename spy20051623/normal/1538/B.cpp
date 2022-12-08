#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int ave = sum / n;
	if (ave * n != sum) {
		printf("-1\n");
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > ave)
			++cnt;
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