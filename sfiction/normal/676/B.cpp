#include <cstdio>

const int MAXN = 10 + 1;

int f[MAXN][MAXN];

int main(){
	int n, t, ans = 0;
	scanf("%d%d", &n, &t);
	f[0][0] = t << MAXN;
	int N = 1 << MAXN;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j){
			if (f[i][j] < N)
				continue;
			else{
				++ans;
				int t = f[i][j] - N >> 1;
				f[i + 1][j] += t;
				f[i + 1][j + 1] += t;
			}
		}
	printf("%d\n", ans);
	return 0;
}