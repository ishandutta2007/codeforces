#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int t, n, a[N];
long long k, ans, sum;

int main(){
	scanf("%d", &t);
	while(t--){
		sum = 0;
		ans = 0x7fffffffffffffff;
		scanf("%d%lld", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum += a[i];
		if(sum <= k){
			puts("0");
			continue;
		}
		if(n == 1){
			printf("%lld\n", sum - k);
			continue;
		}
		if(sum == k + 1){
			puts("1");
			continue;
		}
		sort(a + 1, a + 1 + n);
		for(int i = 1; i < n; i++){
			sum -= a[n - i + 1] - a[1];
			long long time = sum <= k ? 0 : (sum - k - 1) / (i + 1) + 1;
			ans = min(ans, time + i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}