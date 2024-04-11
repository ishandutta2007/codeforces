#include <cstdio>

long long cnt[11], ans;

int main(){
	int n, t;
	for (scanf("%d%*d", &n); n--; ans += cnt[0]++ - cnt[t]++)
		scanf("%d", &t);
	printf("%I64d\n", ans);
	return 0;
}