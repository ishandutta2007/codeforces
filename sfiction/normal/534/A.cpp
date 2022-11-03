#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if (n <= 2)
		puts("1\n1");
	else if (n == 3)
		puts("2\n1 3");
	else if (n == 4)
		puts("4\n2 4 1 3");
	else{
		printf("%d\n", n);
		int m = n >> 1;
		for (int i = 1; i <= n; ++i)
			printf("%d%c", i & 1 ? i + 1 >> 1 : n + i + 1 >> 1, "\n "[i < n]);
	}
	return 0;
}