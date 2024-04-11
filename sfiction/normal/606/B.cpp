#include <cstdio>

const int MAXN = 5E2 + 10, MAXL = 1E5 + 10;

char s[MAXL];
int ans[MAXL];

bool vis[MAXN][MAXN];

int main(){
	int x, y, x0, y0;
	int k = 0;
	scanf("%d%d%d%d", &x, &y, &x0, &y0);
	scanf("%s", s);

	ans[0] = 1;
	int x1 = x0, y1 = y0, x2, y2;
	int cnt = 1;
	for (; s[k]; ++k){
		vis[x1][y1] = true;
		x2 = x1 + (s[k] == 'U' ? -1 : s[k] == 'D' ? 1 : 0);
		y2 = y1 + (s[k] == 'L' ? -1 : s[k] == 'R' ? 1 : 0);
		if (1 <= x2 && x2 <= x && 1 <= y2 && y2 <= y)
			x1 = x2, y1 = y2;
		cnt += ans[k + 1] = !vis[x1][y1];
	}
	ans[k] += x * y - cnt;
	for (int i = 0; i <= k; ++i)
		printf("%d%c", ans[i], "\n "[i < k]);
	return 0;
}