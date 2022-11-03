#include <cstdio>

const int MAXN = 1E2 + 10;

int n, m;
int a[MAXN], b[MAXN];
int out[MAXN];

int main(){
	scanf("%d", &n);
	m = n * n;
	int r = 0, x, y;
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &x, &y);
		if (!a[x] & !b[y]){
			out[r++] = i + 1;
			a[x] = b[y] = 1;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", out[i], "\n "[i < n - 1]);
	return 0;
}