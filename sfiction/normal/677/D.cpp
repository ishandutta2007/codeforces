#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 3E2 + 10;

int n, m, P;
int a[MAXN][MAXN];
vector<PII> b[MAXN * MAXN];

int dis[MAXN][MAXN];
int tdis[MAXN][MAXN];

bool inRange(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void BFS(vector<PII> &a){
	static const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
	static const int INF = 1 << 30;
	for (int i = 1; i <= n; ++i)
		fill_n(tdis[i] + 1, m, INF);
	queue<PII> S, Q;
	sort(a.begin(), a.end(), [](const PII &l, const PII &r)->bool{return dis[l.st][l.nd] < dis[r.st][r.nd];});
	for (int i = 0; i < a.size(); ++i)
		S.push(a[i]);

	for (; !Q.empty() || !S.empty(); ){
		int x0, y0;
		if (Q.empty() || !S.empty() && ::dis[S.front().st][S.front().nd] <= tdis[Q.front().st][Q.front().nd]){
			x0 = S.front().st, y0 = S.front().nd;
			S.pop();
			if (tdis[x0][y0] == INF){
				tdis[x0][y0] = ::dis[x0][y0];
				Q.push(PII(x0, y0));
			}
		}
		else{
			x0 = Q.front().st, y0 = Q.front().nd;
			Q.pop();
			for (int i = 0; i < 4; ++i){
				int x = x0 + d[i][0], y = y0 + d[i][1];
				if (inRange(x, y) && tdis[x][y] == INF){
					tdis[x][y] = tdis[x0][y0] + 1;
					Q.push(PII(x, y));
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &P);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
			b[a[i][j]].push_back(PII(i, j));
			if (a[i][j] == 1)
				dis[i][j] = i + j - 2;
		}
	for (int i = 1; i < P; ++i){
		if (b[i].size() <= n){
			for (int j = 0; j < b[i + 1].size(); ++j){
				int t = (n + m) * P;
				for (int k = 0; k < b[i].size(); ++k)
					t = min(t, dis[b[i][k].st][b[i][k].nd] + abs(b[i + 1][j].st - b[i][k].st) + abs(b[i + 1][j].nd - b[i][k].nd));
				dis[b[i + 1][j].st][b[i + 1][j].nd] = t;
			}
		}
		else{
			BFS(b[i]);
/*			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= m; ++k)
					printf("%d%c", tdis[j][k], "\n "[k < m]);*/
			for (int j = 0; j < b[i + 1].size(); ++j)
				dis[b[i + 1][j].st][b[i + 1][j].nd] = tdis[b[i + 1][j].st][b[i + 1][j].nd];
		}
	}
	int ans = (n + m) * P;
	for (int i = 0; i < b[P].size(); ++i)
		ans = min(ans, dis[b[P][i].st][b[P][i].nd]);
	printf("%d\n", ans);
	return 0;
}