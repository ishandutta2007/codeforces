#include <cstdio>

const int MAXN = 1E5 + 10;

int a[MAXN];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int i = 1;
	for (; i < k; k -= i, ++i);
	printf("%d\n", a[k]);
	return 0;
}