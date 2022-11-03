#include <cstdio>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if (k < 2 || 3 < k || n <= 3 || n == 4 && k == 2)
		puts("-1");
	else{
		printf("%d\n", n - 1);
		for (int i = 1; i < n; ++i)
			printf("%d %d\n", k == 2 || i < 3 ? i : 3, i + 1);
	}
	return 0;
}