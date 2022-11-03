#include <cstdio>

const int MAXN = 5E2 + 10;

int n, m;
int E[MAXN][MAXN];
int deg[MAXN];
char s[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u][v] = E[v][u] = true;
		++deg[u], ++deg[v];
	}
	for (int i = 1; i <= n; ++i)
		if (deg[i] == n - 1)
			s[i] = 'b';
	int sa = n + 1;
	for (int i = 1; i <= n; ++i)
		if (!s[i]){
			s[sa = i] = 'a';
			break;
		}
	for (int i = sa + 1; i <= n; ++i)
		if (!s[i])
			s[i] = E[sa][i] ? 'a' : 'c';
	s[n + 1] = '\0';
	bool flag = true;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			flag &= E[i][j] ^ ((s[i] ^ s[j]) == 2);
	if (flag)
		printf("Yes\n%s\n", s + 1);
	else
		puts("No");
	return 0;
}