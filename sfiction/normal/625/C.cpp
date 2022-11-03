#include <cstdio>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	--m;
	printf("%d\n", (n * m + 1 + n * n - (n - m) + 1) * n / 2);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			printf("%d%c", j < m ? i * m + j + 1 : n * m + i * (n - m) + (j - m) + 1, "\n "[j < n - 1]);
	return 0;
}