#include <cstdio>

const int MAXN = 2E5 + 10;

int n, m;
int a[MAXN], pre[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		pre[i] = a[i] == a[i - 1] ? pre[i - 1] : i - 1;
	}
	for (int l, r, x, i = 0; i < m; ++i){
		scanf("%d%d%d", &l, &r, &x);
		printf("%d\n", a[r] != x ? r : l <= pre[r] ? pre[r] : -1);
	}
	return 0;
}