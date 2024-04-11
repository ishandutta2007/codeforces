/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 548B
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500 + 10;

int n, m, q;
bool a[MAXN][MAXN];
int len[MAXN];

int consec(bool (&a)[MAXN]){
	int ret = 0, cnt = 0;
	for (int i=1;i<=m;++i)
		if (a[i]){
			++cnt;
			ret = max(ret, cnt);
		}
		else
			cnt = 0;
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			scanf("%d", &a[i][j]);
		len[i] = consec(a[i]);
	}

	while (q--){
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] ^= 1;
		len[x] = consec(a[x]);

		int ans = 0;
		for (int i=1;i<=n;++i)
			ans = max(ans, len[i]);
		printf("%d\n", ans);
	}

	return 0;
}