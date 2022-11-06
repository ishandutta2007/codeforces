#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, n, a[55], b[55];

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		ll A = 0x3f3f3f3f, B = 0x3f3f3f3f, ans = 0;
		for(ll i=1;i<=n;i++) {
			scanf("%lld", &a[i]);
			A = min(A, a[i]);
		}
		for(ll i=1;i<=n;i++) {
			scanf("%lld", &b[i]);
			B = min(B, b[i]);
		}
		for(ll i=1;i<=n;i++) {
			ans += max(a[i]-A, b[i]-B);
		}
		printf("%lld\n", ans);
	}
	return 0;
}