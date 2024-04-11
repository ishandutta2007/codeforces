#include <cstdio>
char mp[505][505];
bool visit[505][505];
int out[250005][2];
int len;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,k;
void dfs(int x,int y){
	int nx,ny;
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		nx=x+d[i][0];
		ny=y+d[i][1];
		if(nx<1||ny<1||nx>n||ny>m||visit[nx][ny]||mp[nx][ny]=='#'){
			continue;
		}
		dfs(nx,ny);
	}
	out[++len][0]=x;
	out[len][1]=y;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='#'||visit[i][j]){
				continue;
			}
			dfs(i,j);
		}
	}
	for(int i=1;i<=k;i++){
		mp[out[i][0]][out[i][1]]='X';
	}
	for(int i=1;i<=n;i++){
		puts(mp[i]+1);
	}
	return 0;
}