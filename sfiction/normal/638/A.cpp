#include <cstdio>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", (m & 1 ? m + 1 : n - m + 2) >> 1);
	return 0;
}