//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll x, ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &x);
		ans = 0;
		for(ll i=1;i<=63;i++) {
			ll len = ((1ll << i) - 1);
			ll s = (1 + len) * len / 2;
			if(x >= s) {
				x -= s;
				++ans;
			}
			else break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}