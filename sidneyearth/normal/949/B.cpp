#include <stdio.h>
typedef long long ll;
int main(){
	ll n; int q;
	scanf("%I64d%d", &n, &q);
	for(int i = 1; i <= q; i++){
		ll x; scanf("%I64d", &x);
		ll p = x - 1, m = n, ans = 0, f = 0;		
		while(m && p % 2 != f){
			
			ans += (m + (f == 0)) / 2;
			int g = m % 2;
			m -= (m + (f == 0)) / 2;
			if(g) f ^= 1;
//			printf("p:%I64d, m:%I64d ans:%I64d f:%I64d\n", p, m, ans, f);
			p >>= 1;
		}
		ans += p / 2 + 1;
		printf("%I64d\n", ans);
	}
	return 0;
}