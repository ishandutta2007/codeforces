///	Choe Kwang C

#include <bits/stdc++.h>
using namespace std;
#define N 5050

int n, k, a[N], b[N];
long long f[N], g[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1);
	k = unique(b + 1, b + n + 1) - b - 1;
	for (int j = 0; j <= k; j ++) f[j] = 1ll << 60;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) {
			f[j] = min(f[j-1], g[j] + abs(a[i] - b[j]));
		}
		for (int j = 1; j <= k; j ++) g[j] = f[j];
	}
	long long ans = 1ll << 60;
	for (int j = 1; j <= k; j ++) ans = min(ans, f[j]);
	cout << ans << endl;
	return 0;
}