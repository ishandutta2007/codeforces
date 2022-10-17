#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
char mp[2005][2005];
queue<int> qx,qy;
int n,m,r,c,x,y;
bool inside[2005][2005];
int dist[2005][2005];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(){
	memset(dist,0x3f,sizeof dist);
	dist[r][c]=0;
	qx.push(r);
	qy.push(c);
	inside[r][c]=1;
	int nx,ny;
	int nnx,nny;
	while(!qx.empty()){
		nx=qx.front();
		ny=qy.front();
		inside[nx][ny]=0;
		qx.pop();
		qy.pop();
		for(int i=0;i<4;i++){
			nnx=nx+d[i][0];
			nny=ny+d[i][1];
			if(nnx<1||nny<1||nnx>n||nny>m){
				continue;
			}
			if(mp[nnx][nny]=='*'){
				continue;
			}
			if(i>1){
				if(dist[nnx][nny]>dist[nx][ny]){
					dist[nnx][nny]=dist[nx][ny];
					if(!inside[nnx][nny]){
						qx.push(nnx);
						qy.push(nny);
						inside[nnx][nny]=1;
					}
				}
			}
			else if(i==1){
				if(dist[nx][ny]+1<=x&&dist[nnx][nny]>dist[nx][ny]+1){
					dist[nnx][nny]=dist[nx][ny]+1;
					if(!inside[nnx][nny]){
						qx.push(nnx);
						qy.push(nny);
						inside[nnx][nny]=1;
					}
				}
			}
			else{
				if(dist[nx][ny]-c+ny>y){
					continue;
				}
				if(dist[nnx][nny]>dist[nx][ny]){
					dist[nnx][nny]=dist[nx][ny];
					if(!inside[nnx][nny]){
						qx.push(nnx);
						qy.push(nny);
						inside[nnx][nny]=1;
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	bfs();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dist[i][j]<=x&&dist[i][j]-c+j<=y){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}