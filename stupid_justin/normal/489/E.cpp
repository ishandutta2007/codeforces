#include<bits/stdc++.h>
using namespace std;
#define N 1010
 
int n, len;
int x[N], b[N];
int pre[N], out[N];
double dp[N];
 
bool yes(double ans) {
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e30;
		for (int j = 0; j < i; j++) {
			double tmp = dp[j] + sqrt(1e-8 + abs(x[i] - x[j] - len))
					- ans * b[i];
			if (dp[i] > tmp) {
				dp[i] = tmp;
				pre[i] = j;
			}
		}
	}
	return dp[n] < 0;
}
 
int main() {
	scanf("%d%d", &n, &len);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &b[i]);
	double l = 0, r = 1e10, mid;
	while (r - l > 1e-8) {
		mid = (l + r) / 2;
		if (yes(mid)) {
			r = mid;
		} else
			l = mid;
	}
	yes(l);
	len = 0;
	out[0] = n;
	while (pre[out[len]]) {
		out[len + 1] = pre[out[len]];
		len++;
	}
	for (int i = len; i >= 0; i--)
		printf("%d%s", out[i], (i == 0) ? "\n" : " ");
	return 0;
}