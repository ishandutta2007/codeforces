#include <bits/stdc++.h>
using namespace std;

#define N 4040

int n, sum[N], aa;

int vis[N*10];
char s[N];

int main() {
	scanf("%d\n", &aa);
	gets(s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i-1] + s[i] - '0';
	}
	int e = 0;
	for (int i = 0; i < n; i ++) for (int j = i + 1; j <= n; j ++) vis[sum[j]-sum[i]] ++, e ++;
	long long ans = 0;
	if (!aa) {
        printf("%I64d\n", 1ll * vis[0] * e * 2 - 1ll * vis[0] * vis[0]);
		return 0;
	}
    for (int k = 1; k * k <= aa; k ++) {
		if (aa % k == 0 && k <= sum[n] && aa / k <= sum[n]) {
			if (k * k == aa) ans += 1ll * vis[k] * vis[aa/k];
			else ans += 1ll * vis[k] * vis[aa/k] * 2;
		}
    }
    printf("%I64d\n", ans);
	return 0;
}