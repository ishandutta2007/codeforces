#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
char mp[1005][1005];
queue<int> qx,qy;
int ans[1005][1005];
bool visit[1005][1005];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
void bfs(int sx,int sy){
	qx.push(sx);
	qy.push(sy);
	memset(ans,0x3f,sizeof(ans));
	ans[sx][sy]=0;
	visit[sx][sy]=1;
	int x,y;
	int nx,ny;
	while(!qx.empty()){
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for(int i=0;i<4;i++){
			nx=x+d[i][0];
			ny=y+d[i][1];
			if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='T'||visit[nx][ny]){
				continue;
			}
			ans[nx][ny]=ans[x][y]+1;
			visit[nx][ny]=1;
			qx.push(nx);
			qy.push(ny);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int sx,sy;
	int ex,ey;
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='E'){
				sx=i;
				sy=j;
			}
			if(mp[i][j]=='S'){
				ex=i;
				ey=j;
			}
		}
	}
	bfs(sx,sy);
	int answer=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==ex&&j==ey){
				continue;
			}
			if(i==sx&&j==sy){
				continue;
			}
			if(mp[i][j]=='T'){
				continue;
			}
			if(ans[i][j]<=ans[ex][ey]){
				answer+=mp[i][j]-'0';
			}
		}
	}
	printf("%d\n",answer);
	return 0;
}