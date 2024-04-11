/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 519C
 */
#include <cstdio>

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", (a << 1) < b ? a : (b << 1) < a ? b : (a + b) / 3);
	return 0;
}