#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, d, x;

long long sa[N], sb[N];
int a[N], b[N];

int main() {
	scanf("%d %d %d", &n, &d, &x);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) b[n+1-i] = a[i];
	for (int i = 1; i <= n; i ++) sa[i] = sa[i-1] + a[i];
	for (int i = 1; i <= n; i ++) sb[i] = sb[i-1] + b[i];
	long long sum = 0;
	int j = 1;
	int ans1 = 0;
	for (int i = 1; i <= (n + 1) / 2; i ++) {
		sum += x;
		int j = lower_bound(sa + 1, sa + n + 1, sum) - sa;
		if (j - i > 1ll * d * i) ans1 ++, sum -= x;
	}

	int ans2 = 0;
	sum = 0;

	for (int i = 1; i <= (n + 1) / 2; i ++) {
		sum += x;
		int j = lower_bound(sb + 1, sb + n + 1, sum) - sb;
		if (j - i > 1ll * d * i) ans2 ++, sum -= x;
	}

	printf("%d\n", max(ans1, ans2));
	return 0;
}