#include <cstdio>

const int MAXN = 1E3 + 10;

int x[MAXN], y[MAXN];

int main(){
	int n, s = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	x[n + 1] = x[0], y[n + 1] = y[0];
	for (int i = 1; i <= n; ++i)
		s += (x[i + 1] - x[i]) * (y[i] - y[i - 1]) - (x[i] - x[i - 1]) * (y[i + 1] - y[i]) < 0;
	printf("%d\n", s);
	return 0;
}