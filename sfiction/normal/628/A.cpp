#include <cstdio>

int main(){
	int n, b, p;
	scanf("%d%d%d", &n, &b, &p);
	int tot = 0, tn = n;
	for (; n > 1; ){
		int t = 1 << 30 - __builtin_clz(n);
		tot += b * t * 2 + t;
		n -= t;
	}
	printf("%d %d\n", tot, tn * p);
	return 0;
}