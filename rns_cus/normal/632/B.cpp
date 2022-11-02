#include <bits/stdc++.h>
using namespace std;
#define N 500500

char s[N];
int n, a[N];
long long ans, sum, x;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) {
        if (s[i] == 'B') sum += a[i];
        else sum -= a[i];
	}
	ans = sum;
	x = 0;
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'B') x += a[i];
		else x -= a[i];
		ans = max(ans, sum - 2 * x);
	}
	x = 0;
	for (int i = n; i >= 1; i --) {
		if (s[i] == 'B') x += a[i];
		else x -= a[i];
		ans = max(ans, sum - 2 * x);
	}
	for (int i = 1; i <= n; i ++) ans += a[i];
	ans /= 2;
	printf("%I64d\n", ans);
	return 0;
}