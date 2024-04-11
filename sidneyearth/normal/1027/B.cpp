#include <stdio.h>
int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for(int k = 1; k <= q; k++){
		int x, y; scanf("%d%d", &x, &y);
		long long ans;
		if((x % 2) ^ (y % 2)){
			ans = ((long long)n * n + 1) / 2;
			ans += (x - 1ll) / 2 * n;
			ans += (y + 1) / 2;
			ans += (n / 2) * (x % 2 == 0);
		}
		else{
			ans = (x - 1ll) / 2 * n;
			ans += (y + 1) / 2;
			ans += ((n + 1) / 2) * (x % 2 == 0);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}