#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E3 + 10, MAXM = 1E3 + 10, MAXNN = MAXN * MAXM;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int n, m;
ll K;
int a[MAXN][MAXM];

int fa[MAXNN];

int find(int x){
	return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

void merge(int u, int v){
	u = find(u), v = find(v);
	if (u != v){
		fa[u] += fa[v];
		fa[v] = u;
	}
}

bool inRange(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int sx, int sy, int tot){
	int as = a[sx][sy];
	a[sx][sy] = -as;
	--tot;
	if (!tot)
		return;

	queue<PII> Q;
	Q.push(PII(sx, sy));
	while (!Q.empty()){
		int x0 = Q.front().st, y0 = Q.front().nd;
		Q.pop();
		for (int i = 0; i < 4; ++i){
			int x = x0 + d[i][0], y = y0 + d[i][1];
			if (inRange(x, y) && a[x][y] >= as){
				a[x][y] = -as;
				--tot;
				if (!tot)
					return;
				Q.push(PII(x, y));
			}
		}
	}
}

int main(){
	scanf("%d%d%I64d", &n, &m, &K);
	vector<pair<int, PII> > lst(1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
			lst.push_back(make_pair(a[i][j], PII(i, j)));
		}
	sort(lst.begin() + 1, lst.end());

	int sx = -1, sy = -1;
	for (int i = n * m; i > 0; --i){
		int x0 = lst[i].nd.st, y0 = lst[i].nd.nd;

		fa[x0 * m + y0 + 1] = -1;
		for (int j = 0; j < 4; ++j){
			int x = x0 + d[j][0], y = y0 + d[j][1];
			if (inRange(x, y) && fa[x * m + y + 1])
				merge(x0 * m + y0 + 1, x * m + y + 1);
		}
		if (K % lst[i].st == 0 && K / lst[i].st <= -fa[find(x0 * m + y0 + 1)]){
			sx = x0, sy = y0;
			break;
		}
	}

	if (sx < 0)
		puts("NO");
	else{
		BFS(sx, sy, K / a[sx][sy]);
		puts("YES");
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				printf("%d%c", a[i][j] < 0 ? -a[i][j] : 0, "\n "[j < m - 1]);
	}
	
	return 0;
}