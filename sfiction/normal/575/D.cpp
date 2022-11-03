#include <cstdio>

int main(){
	int n = 1000;
	printf("%d\n", n << 1);
	for (int i = 1; i <= n; ++i)
		printf("%d 1 %d 2\n", i, i);
	for (int i = n; i >= 1; --i)
		printf("%d 1 %d 2\n", i, i);
	return 0;
}