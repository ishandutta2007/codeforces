#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[300100];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	long long ans = 0, res = 0;
	for(int i = 1; i <= n; ++i){
		long long t = min(res, a[i] / 2);
		ans += t;
		res -= t;
		a[i] -= 2 * t;
		ans += a[i] / 3;
		res += a[i] % 3;
	}
	printf("%lld\n", ans);
	return 0;
}