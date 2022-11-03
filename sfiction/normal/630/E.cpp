#include <cstdio>

int main(){
	long long x1, y1, x2, y2;
	scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
	printf("%I64d\n", (x2 - x1 + 1) * (y2 - y1 + 1) + 1 >> 1);
	return 0;
}