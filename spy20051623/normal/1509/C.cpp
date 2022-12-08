#include <bits/stdc++.h>

using namespace std;

int a[2005];
long long int res[2005][2005];

long long int dp(int l, int r) {
	if (res[l][r] != -1)
		return res[l][r];
	if (l == r)
		return 0;
	res[l][r] = min(dp(l + 1, r), dp(l, r - 1)) + a[r] - a[l];
	return res[l][r];
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	memset(res, -1, sizeof res);
	printf("%lld\n", dp(0, n - 1));
	return 0;
}