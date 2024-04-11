#include <bits/stdc++.h>
using namespace std;

long long sum[5010][5010];
long long pre[5010], suc[5010];
int a[5010], b[5010];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + 1ll * a[i] * b[i];
	for (int i = n; i >= 1; i--) suc[i] = suc[i + 1] + 1ll * a[i] * b[i];
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			sum[i][j] = sum[i + 1][j - 1] + (i == j ? 1ll * a[i] * b[j] : 1ll * a[i] * b[j] + 1ll * b[i] * a[j]);
		}
	}
	long long ans = pre[n];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = max(ans, pre[i - 1] + suc[j + 1] + sum[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}