#include <bits/stdc++.h>
using namespace std;

#define N 200010

int a[N], T, tot;
int gas[N], n;

int main() {
	///freopen("in.txt", "r", stdin);

	cin >> n >> T;

	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		a[i] -= i;
	}

	int ans = 0;

	for (int i = 1; i <= n && i < T; i ++) {
		int tmp = T - i;
		if (a[i] < tmp) tot ++;
		tot -= gas[i];
		if (a[i] < T && a[i] >= T - n) {
			gas[T - a[i]] ++;
		}
		if (ans < tot) ans = tot;
	}

	printf("%d\n", ans);
}