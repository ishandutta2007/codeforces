#include <cstdio>

int main(){
	int a = -1, b = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			printf("%d%c", i == n / 2 + 1 || i < j && j < n + 1 - i || n + 1 - i < j && j < i ? (a += 2) : (b += 2), "\n "[j < n]);
	return 0;
}