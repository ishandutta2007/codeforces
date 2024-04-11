#include <bits/stdc++.h>
using namespace std;
#define N 500500

typedef long long LL;
LL a[N], k, s[N], bs[N], mx, mn;
int n;

bool ok1(LL mid) {
	int m = lower_bound(a + 1, a + n + 1, mid) - a;
	LL sum = bs[m] - mid * (n - m + 1);
	if (sum > k) return 0;
	LL sum1 = mid * (m - 1) - s[m-1];
	return sum1 >= sum;
}

bool ok2(LL mid) {
	int m = lower_bound(a + 1, a + n + 1, mid + 1) - a - 1;
	LL sum = mid * m - s[m];
	if (sum > k) return 0;
	LL sum1 = bs[m+1] - mid * (n - m);
	return sum1 >= sum;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %I64d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
	for (int i = n; i >= 1; i --) bs[i] = bs[i+1] + a[i];
	LL st = a[1] - 1, en = a[n];
	while (en - st > 1) {
		int mid = en + st >> 1;
		if (ok1(mid)) en = mid;
		else st = mid;
	}
	mx = en;

	st = a[1], en = a[n] + 1;
	while (en - st > 1) {
		int mid = en + st >> 1;
		if (ok2(mid)) st = mid;
		else en = mid;
	}
	mn = st;

	printf("%I64d\n", mx - mn);
	return 0;
}