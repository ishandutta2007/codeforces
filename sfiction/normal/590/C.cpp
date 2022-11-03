#include <cctype>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E3 + 10, MAXC = 4;
const int INF = 1 << 24;
const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;
char s[MAXN][MAXN];
int dis[3][MAXN][MAXN];
int E[MAXC][MAXC];

inline bool inRange(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void BFS(char start, int (&dis)[MAXN][MAXN], int (&E)[MAXC]){
	queue<PII> Q;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == start){
				dis[i][j] = -1;
				Q.push(PII(i, j));
			}
			else
				dis[i][j] = INF;

	for (int i = 0; i < MAXC; ++i)
		E[i] = INF;
	E[start - '1'] = 0;

	int x, y, x0, y0;
	while (!Q.empty()){
		int x0 = Q.front().first, y0 = Q.front().second;
		Q.pop();
//		printf("(%d,%d,%d)\n", x0, y0, dis[x0][y0]);
		for (int i = 0; i < 4; ++i){
			x = x0 + d[i][0], y = y0 + d[i][1];
			if (inRange(x, y) && s[x][y] != '#' && dis[x][y] == INF){
//				printf("-------(%d,%d)\n", x, y);
				dis[x][y] = dis[x0][y0] + 1;
				Q.push(PII(x, y));
				if (isdigit(s[x][y]))
					E[s[x][y] - '1'] = min(E[s[x][y] - '1'], dis[x][y]);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);

	BFS('1', dis[0], E[0]);
	BFS('2', dis[1], E[1]);
	BFS('3', dis[2], E[2]);
/*
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j)
			printf("%3d", dis[0][i][j]);
		puts("");
	}
	*/

	int ans = INF;
	if (E[0][1] == INF && E[0][2] == INF
		|| E[1][0] == INF && E[1][2] == INF
		|| E[2][0] == INF && E[2][1] == INF)
		puts("-1");
	else{
		ans = min(ans, E[0][1] + E[0][2]);
		ans = min(ans, E[1][0] + E[1][2]);
		ans = min(ans, E[2][0] + E[2][1]);

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (s[i][j] == '.')
					ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] + 1);
		printf("%d\n", ans);
	}

	return 0;
}