#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (; n > 0; n /= 8)
		ans += n % 8 == 1;
	printf("%d\n", ans);
	return 0;
}