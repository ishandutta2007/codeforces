#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	scanf("%d", &t);
	while (t --) {
		LL n; scanf("%lld", &n);
		LL x = 1, s = 0, ans = 0, len = 1;

		while (s + x <= n) {
			s += x;
			ans ++;
			x = x * 2 + (len + 1) * (len + 1);
			len = len * 2 + 1;
		}
		printf("%lld\n", ans);
	}
}