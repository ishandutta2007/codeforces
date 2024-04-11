//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll T, n, a[N], cntNega, cnt0;

int main() {
	scanf("%lld", &T);
	while(T--) {
		cntNega = 0;
		scanf("%lld", &n);
		for(ll i=1;i<=n;i++) {
			scanf("%lld", &a[i]);
			if(a[i] < 0) ++cntNega;
			else if(!a[i]) ++cnt0;
		}
		if(n == 5) {
			ll ans = 1;
			for(ll i=1;i<=n;i++) ans *= a[i];
			printf("%lld\n", ans);
			continue;
		}
		sort(a+1, a+1+n);
		ll ans = max(max(max(max(max(a[n-4]*a[n-3]*a[n-2]*a[n-1]*a[n], a[n-3]*a[n-2]*a[n-1]*a[n]*a[1]), a[n-2]*a[n-1]*a[n]*a[1]*a[2]), a[n-1]*a[n]*a[1]*a[2]*a[3]), a[n]*a[1]*a[2]*a[3]*a[4]), a[1]*a[2]*a[3]*a[4]*a[5]);
		printf("%lld\n", ans);
	}
	return 0;
}