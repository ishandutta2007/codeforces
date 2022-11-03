#include <cstdio>

const int MAXN = 1E3 + 10;
const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char s[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m;

int K;
int num[MAXN * MAXN];

void BFS(int sx, int sy){
	static int que[MAXN * MAXN][2];
	int x0, y0, x, y;
	int cnt = 0;
	que[0][0] = sx;
	que[0][1] = sy;
	s[sx][sy] = '#';
	a[sx][sy] = K;
	for (int l = 0, r = 1; l < r; ++l){
		int x0 = que[l][0], y0 = que[l][1];
		for (int i = 0; i < 4; ++i){
			x = x0 + d[i][0], y = y0 + d[i][1];
			if (s[x][y] == '.'){
				que[r][0] = x;
				que[r][1] = y;
				++r;
				s[x][y] = '#';
				a[x][y] = K;
			}
			else if (s[x][y] == '*')
				++cnt;
		}
	}
	num[K++] = cnt;
}

int main(){
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	K = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '.')
				BFS(i, j);
	for (int x, y, i = 0; i < q; ++i){
		scanf("%d%d", &x, &y);
		printf("%d\n", num[a[x - 1][y - 1]]);
	}
	return 0;
}