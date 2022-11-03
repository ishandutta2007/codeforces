/*
ID: Sfiction
OJ: CF
PROB: 510B
*/
#include <cstdio>
#include <cstring>

const int MAXN=55;
const int d[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int n,m;
char map[MAXN][MAXN];
int last[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool BFS(int x0,int y0){
	static int que[MAXN*MAXN][2];
	char color=map[x0][y0];
	int x,y;
	memset(vis,0,sizeof(vis));
	que[0][0]=x0;
	que[0][1]=y0;
	vis[x0][y0]=true;
	for (int l=0,r=1;l<r;++l){
		x0=que[l][0];
		y0=que[l][1];
		for (int i=0;i<4;++i){
			x=x0+d[i][0];
			y=y0+d[i][1];
			if (map[x][y]==color){
				if (!vis[x][y]){
					vis[x][y]=true;
					last[x][y]=i;
					que[r][0]=x;
					que[r][1]=y;
					++r;
				}
				else if (i+last[x0][y0]!=3)
					return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%s",map[i]+1);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (!vis[i][j] && BFS(i,j)){
				puts("Yes");
				return 0;
			}
	puts("No");
	return 0;
}