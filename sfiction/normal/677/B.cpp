#include <cstdio>

int main(){
	int n, K, h;
	scanf("%d%d%d", &n, &h, &K);
	int c = 0;
	long long ans = 0;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		if (c + t <= h)
			c += t;
		else if (c % K + t > h){
			ans += (c - 1) / K + 1;
			c = t;
		}
		else{
			int ts = (c + t - h - 1) / K + 1;
			ans += ts;
			c += t - ts * K;
		}
	}
	ans += (c - 1) / K + 1;
	printf("%I64d\n", ans);
	return 0;
}