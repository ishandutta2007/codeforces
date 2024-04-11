#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;

int main() {
	scanf("%d", &t);
	while (t--){
		LL a,b,x,y,n; 
		scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&n);
		LL ans = 2e18;
		if (n >= (a - x) + (b - y)) {
			ans = x * y;
			printf("%lld\n", ans); continue;
		}
		// printf("ok\n");
		if (a - n >= x) {
			ans = min(ans, (a - n) * b);
		} else {
			ans = min(ans, x * (b - (n - (a - x))));
		}
 
		swap(a, b); swap(x, y);
		if (a - n >= x) {
			// printf("!\n");
			ans = min(ans, (a - n) * b);
		} else {
			ans = min(ans, x * (b - (n - (a - x))));
		}
		printf("%lld\n", ans);
	}
}