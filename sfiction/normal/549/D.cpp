/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 549D
 */
#include <cstdio>

const int MAXN = 1E2 + 10;

int n, m;
char s[MAXN][MAXN];
int a[MAXN][MAXN];

int main(){
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;++i)
		scanf("%s" , s[i]);

	int ans = 0;
	for (int i=n-1;i>=0;--i)
		for (int j=m-1;j>=0;--j){
			int c = s[i][j] == 'W' ? 1 : -1;
			a[i][j] = a[i + 1][j] + a[i][j + 1] - a[i + 1][j + 1];
			if (a[i][j] != c)
				++ans;
			a[i][j] = c;
		}
	printf("%d", ans);

	return 0;
}