/*
 * ID: Sfiction
 * OJ: CF
 * RPOB: 570A
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E2 + 10, MAXM = 1E2 + 10;

int n, m;
int a[MAXN], b[MAXM];

int choose(int a[], int n){
	int ret = 0;
	for (int i = 0; i < n; ++i){
		if (a[i] > a[ret])
			ret = i;
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	memset(b, 0, sizeof(b));
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[j]);
		++b[choose(a, n)];
	}
	printf("%d\n", choose(b, n) + 1);
	return 0;
}