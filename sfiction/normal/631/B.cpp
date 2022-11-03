#include <cstdio>

const int MAXN = 5E3 + 10;

int row[MAXN], col[MAXN];
int rt[MAXN], ct[MAXN];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int com, x, c, i = 1; i <= k; ++i){
		scanf("%d%d%d", &com, &x, &c);
		if (com == 1)
			row[x] = c, rt[x] = i;
		else
			col[x] = c, ct[x] = i;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			printf("%d%c", rt[i] < ct[j] ? col[j] : row[i], "\n "[j < m]);
	return 0;
}