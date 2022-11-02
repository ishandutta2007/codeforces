#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> Pair;
const int maxn = 1010;
const int d[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
char mmap[maxn][maxn];
int f[4][maxn * maxn];
int n, m, w;
queue<Pair> q;
int No(int x, int y){ return x * (m + 2) + y; }
int On(int no, int &x, int &y){
	x = no / (m + 2);
	y = no % (m + 2);
}
int Find(int *f, int u){ return u == f[u] ? u : f[u] = Find(f, f[u]); }
int main(){
	scanf("%d%d%d", &n, &m, &w);
	for(int i = 1; i <= n; i++)
		scanf("%s", mmap[i] + 1);
	int sx, sy, tx, ty;
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	for(int i = 0; i <= n + 1; i++)
		mmap[i][0] = mmap[i][m + 1] = '#';
	for(int i = 0; i <= m + 1; i++)
		mmap[0][i] = mmap[n + 1][i] = '#';
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= m + 1; j++)
			for(int k = 0; k < 4; k++)
				f[k][No(i, j)] = No(i, j);
	int ans = -1;
	for(int i = 0; i < 4; i++)
		f[i][No(sx, sy)] = No(sx + d[0][i], sy + d[1][i]);
	q.push(Pair(No(sx, sy), 0));
	while(!q.empty()){
		int x, y;
		On(q.front().first, x, y);
		int step = q.front().second;
//		printf("x:%d y:%d step:%d id:%d\n", x, y, step, q.front().first);
		q.pop();
		if(x == tx && y == ty){
			ans = step;
			break;
		}
		for(int k = 0; k < 4; k++){
			int id = No(x, y);
			while(true){
//				printf("k:%d Find:%d id:%d\n", k, Find(f[k], id), id);
				int nx, ny;
				On(Find(f[k], id), nx, ny);
				if(mmap[nx][ny] == '#' || abs(nx - x) > w || abs(ny - y) > w)
					break;
//				printf("push:%d nx:%d ny:%d\n", No(nx, ny), nx, ny);
				q.push(Pair(No(nx, ny), step + 1));
				for(int i = 0; i < 4; i++)
					f[i][No(nx, ny)] = No(nx + d[0][i], ny + d[1][i]);
				id = No(nx, ny);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}