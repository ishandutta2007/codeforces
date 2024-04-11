#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	printf("%I64d\n", 24ll + 9ll * (n - 3) << 2 * n - 6);
	return 0;
}