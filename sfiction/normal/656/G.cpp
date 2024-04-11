#include <cstdio>

int c[11], s;

int main(){
	int n, m, T, kitten, i, j;
	scanf("%d%d%d", &n, &m, &T);
	for (i = 0; i < n; ++i)
		for (j = 0; j <= m; ++j)
			c[j] += getchar() == 'Y';
	for (j = 1; j <= m; ++j)
		s += c[j] >= T;
	printf("%d\n", s);
}