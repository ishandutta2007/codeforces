#include <cstdio>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 2 * n; ++i){
		if (2 * n + i <= m)
			printf("%d ", 2 * n + i);
		if (i <= m)
			printf("%d ", i);
	}
	return 0;
}