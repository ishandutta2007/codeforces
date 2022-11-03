#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5E2 + 10;

int n, a[MAXN];
int f[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i)
		f[i][i] = 1, f[i][i + 1] = 1 + (a[i] != a[i + 1]);
	f[n][n] = 1;
	for (int k = 3; k <= n; ++k)
		for (int i = 1, j = k; j <= n; ++i, ++j){
			f[i][j] = f[i + 1][j - 1] + (a[i] == a[j] ? 0 : 2);
			for (int l = i; l < j; ++l)
				f[i][j] = min(f[i][j], f[i][l] + f[l + 1][j]);
		}
	printf("%d\n", f[1][n]);
	return 0;
}