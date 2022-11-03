#include <cstdio>

const int MAXN = 5E2 + 10;

int n, K;
bool f[MAXN][MAXN];

int main(){
	scanf("%d%d", &n, &K);
	f[0][0] = 1;
	for (int w, iter = 0; iter < n; ++iter){
		scanf("%d", &w);
		for (int i = K - w; i >= 0; --i)
			for (int j = K - w; j >= 0; --j){
				f[i + w][j] |= f[i][j];
				f[i][j + w] |= f[i][j];
			}
	}
	int ans = 0;
	for (int i = 0; i <= K; ++i)
		ans += f[i][K - i];
	printf("%d\n", ans);
	for (int i = 0; i <= K; ++i)
		if (f[i][K - i])
			printf("%d ", i);
	return 0;
}