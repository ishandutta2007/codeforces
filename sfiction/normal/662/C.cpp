#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 20, MAXNN = 1 << 20, MAXM = 1E5 + 10;

int a[MAXM];
char s[MAXM];
int f[MAXN + 1][MAXNN], g[MAXN + 1][MAXNN];
int cnt[MAXNN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		for (int j = 0; j < m; ++j)
			a[j] = a[j] << 1 | s[j] - '0';
	}
	for (int i = 0; i < m; ++i)
		++f[0][a[i]], ++g[0][a[i]];
	int n0 = 1 << n;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < n0; ++j){
			g[i][j] = i == 1 ? 0 : g[i - 2][j];
			f[i][j] -= g[i][j] * n;
			for (int k = 1; k < n0; k <<= 1)
				f[i][j] += g[i - 1][j ^ k];
			g[i][j] += f[i][j] /= i;
			cnt[j] += min(i, n - i) * f[i][j];
		}
	}
	int ans = cnt[0];
	for (int i = 1; i < n0; ++i)
		ans = min(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}