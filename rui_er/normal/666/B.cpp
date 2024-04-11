// LUOGU_RID: 92827256
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e3+5, inf = 0x3f3f3f3f;

int n, m, dis[2][N][N], far[2][3][N], ans, ansA, ansB, ansC, ansD;
vector<int> e[2][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void bfs(int s, int id) {
	memset(dis[id][s], 0x3f, sizeof(dis[id][s]));
	queue<int> q;
	dis[id][s][s] = 0;
	dis[id][s][0] = -inf;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : e[id][u]) {
			if(dis[id][s][v] > dis[id][s][u] + 1) {
				dis[id][s][v] = dis[id][s][u] + 1;
				q.push(v);
			}
		}
	}
} 

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[0][u].push_back(v);
		e[1][v].push_back(u);
	}
	rep(i, 1, n) {
		bfs(i, 0);
		bfs(i, 1);
		rep(id, 0, 1) {
			rep(j, 1, n) {
				if(dis[id][i][j] < inf) {
					if(dis[id][i][j] > dis[id][i][far[id][0][i]]) {
						far[id][2][i] = far[id][1][i];
						far[id][1][i] = far[id][0][i];
						far[id][0][i] = j;
					}
					else if(dis[id][i][j] > dis[id][i][far[id][1][i]]) {
						far[id][2][i] = far[id][1][i];
						far[id][1][i] = j;
					}
					else if(dis[id][i][j] > dis[id][i][far[id][2][i]]) {
						far[id][2][i] = j;
					}
				}
			}
		}
	}
	rep(B, 1, n) {
		rep(C, 1, n) {
			if(B == C || dis[0][B][C] == inf) continue;
			rep(i, 0, 2) {
				int A = far[1][i][B];
				if(!A || A == B || A == C) continue;
				rep(j, 0, 2) {
					int D = far[0][j][C];
					if(!D || A == D || B == D || C == D) continue;
					if(dis[0][A][B] + dis[0][B][C] + dis[0][C][D] > ans) {
						ans = dis[0][A][B] + dis[0][B][C] + dis[0][C][D];
						ansA = A; ansB = B; ansC = C; ansD = D;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", ansA, ansB, ansC, ansD);
	return 0;
}