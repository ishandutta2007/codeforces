#include <cstdio>
#include <iostream>
using namespace std;

int t, n, l1, r1, l2, r2, d, f;
long long k, ans;

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%lld%d%d%d%d", &n, &k, &l1, &r1, &l2, &r2);
		if(l1 > l2) swap(l1, l2), swap(r1, r2);
		if(r1 <= l2){
			d = l2 - r1;
			f = r1 - l1 + r2 - l2;
		}else if(r1 <= r2){
			d = 0, f = l2 - l1 + r2 - r1;
			k -= 1ll * n * (r1 - l2);
		}else{
			d = 0, f = l2 - l1 + r1 - r2;
			k -= 1ll * n * (r2 - l2);
		}
		if(k <= 0){
			puts("0");
			continue;
		}
		if(k < d){
			printf("%lld\n", k + d);
			continue;
		}
		while(n && k >= d){
			n--;
			k -= d;
			ans += 2 * d;
			int x = min(k, (long long) f);
			ans += x, k -= x;
		}
		printf("%lld\n", ans + 2ll * k);
	}
	return 0;
}