/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 570B
 */
#include <cstdio>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", n == 1 ? 1 : m - 1 >= n - m ? m - 1 : m + 1);
	return 0;
}