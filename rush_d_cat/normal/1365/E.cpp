#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 502;
int n;
LL a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			for (int k = j; k <= n; k ++) {
				LL val = a[i] | a[j] | a[k];
				ans = max(ans, val);
			}
		}
	}
	printf("%lld\n", ans);
}