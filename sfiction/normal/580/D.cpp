#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 18;

int n, m, k;
int a[MAXN];
int c[MAXN][MAXN];
long long f[1 << MAXN][MAXN];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		f[1 << i][i] = a[i];
	}
	for (int u, v, i = 0; i < k; ++i){
		scanf("%d%d", &u, &v);
		--u, --v;
		scanf("%d", &c[u][v]);
	}

	int limit = 1 << n;
	long long ans = 0;
	for (int i = 1; i < limit; ++i)
		for (int j = 0; j < n; ++j){
			if (i >> j & 1){
				for (int k = 0; k < n; ++k)
					if (!(i >> k & 1))
						f[i | 1 << k][k] = max(f[i | 1 << k][k], f[i][j] + c[j][k] + a[k]);
				if (__builtin_popcount(i) == m)
					ans = max(ans, f[i][j]);
			}
		}
	printf("%I64d\n", ans);
	return 0;
}