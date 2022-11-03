#include <cstdio>

const int MAXN = 10 + 2;

int r, c, n, K;
int a[MAXN][MAXN];

int main(){
	scanf("%d%d%d%d", &r, &c, &n, &K);
	for (int x, y, i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			for (int k = i; k <= r; ++k)
				for (int l = j; l <= c; ++l){
					int cnt = 0;
					for (int x = i; x <= k; ++x)
						for (int y = j; y <= l; ++y)
							cnt += a[x][y];
					ans += cnt >= K;
				}
	printf("%d\n", ans);
	return 0;
}