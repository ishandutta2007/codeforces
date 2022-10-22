#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, Q;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int A[1010][1010];
int D[1010][1010];
bool vis[1010][1010];
queue<pii> Qu;

int sz(int x, int y){
	if (x < 1 || x > N || y < 1 || y > M) return 0;
	if (vis[x][y]) return 0;
	vis[x][y] = true;
	int r=1;
	for (int i=0; i<4; i++) if (A[x][y] == A[x+dx[i]][y+dy[i]]) r += sz(x+dx[i], y+dy[i]);
	return r;
}

void pus(int x, int y, int d){
	if (x < 1 || x > N || y < 1 || y > M) return;
	if (D[x][y] > -1) return;
	D[x][y] = d;
	Qu.push(pii(x, y));
}

void dfs(int x, int y){
	if (x < 1 || x > N || y < 1 || y > M) return;
	if (!D[x][y]) return;
	pus(x, y, 0);
	for (int i=0; i<4; i++) if (A[x][y] == A[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i]);
}

int main(){
	int x,y;
	LL t;
	scanf("%d %d %d", &N, &M, &Q);
	for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) scanf("%1d", &A[i][j]), D[i][j] = -1; 
	for (int i=1; i<=N; i++) for (int j=1; j<=M; j++){
		if (vis[i][j]) continue;
		if (sz(i, j) > 1) dfs(i, j);
	}
	while (!Qu.empty()){
		tie(x, y) = Qu.front();
		Qu.pop();
		for (int i=0; i<4; i++) pus(x+dx[i], y+dy[i], D[x][y]+1);
	}
	while (Q--){
		scanf("%d %d %lld", &x, &y, &t);
		if (D[x][y] == -1) printf("%d\n", A[x][y]);
		else if (D[x][y] >= t) printf("%d\n", A[x][y]);
		else printf("%lld\n", A[x][y] ^ (t&1) ^ (D[x][y]&1));
	}
	return 0;
}