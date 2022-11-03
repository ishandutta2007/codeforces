#include <cstdio>

const int MAXN = 1E5 + 10;

int b[MAXN];
int g[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		g[t] = g[t] ? -1 : i;
	}
	bool flag = true, only = true;
	for (int t, i = 1; i <= m; ++i){
		scanf("%d", &t);
		flag &= !!(b[i] = g[t]);
		only &= b[i] > 0;
	}
	if (only){
		puts("Possible");
		for (int i = 1; i <= m; ++i)
			printf("%d%c", b[i], "\n "[i < m]);
	}
	else
		puts(flag ? "Ambiguity" : "Impossible");
	return 0;
}