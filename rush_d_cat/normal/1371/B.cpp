#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL n, r;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld", &n, &r);
		LL ans = 0;
		if (r >= n) ans = 1;
		r = min(n - 1, r);
		ans += r * (r + 1) / 2; 
		printf("%lld\n", ans);
	}
}
/*
  c1
c2

c2=n-c1
*/