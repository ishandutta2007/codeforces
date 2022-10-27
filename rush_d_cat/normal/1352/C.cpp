#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL n, k;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld", &n, &k);
		LL cnt = n - 1;
		LL x = k / cnt, ans;
		if (k % cnt == 0) {
			ans = x * n - 1;
		} else {
			ans = x * n + k % cnt;
		}
		printf("%lld\n", ans);
	}
}