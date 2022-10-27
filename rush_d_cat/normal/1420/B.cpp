#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int c[35] = {0};
		LL ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			int high = 0;
			for (int j = 30; j >= 0; j --) if (a[i] >> j & 1) {
				high = j; ans += c[high] ;c[high] ++; break; 
			}
		}
		printf("%lld\n", ans);
	}
}