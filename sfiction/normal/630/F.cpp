#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long t = 1, ans = 0;
	t = t * n / 1;
	t = t * (n - 1) / 2;
	t = t * (n - 2) / 3;
	t = t * (n - 3) / 4;
	t = t * (n - 4) / 5, ans += t;
	t = t * (n - 5) / 6, ans += t;
	t = t * (n - 6) / 7, ans += t;
	printf("%I64d\n", ans);
	return 0;
}