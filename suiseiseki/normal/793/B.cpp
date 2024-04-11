#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char mp[1005][1005];
int ans[1005][1005][4];
bool in[1005][1005][4];
int sx,sy;
int ex,ey;
int n,m;
queue<int> qx,qy,qt;
void bfs(){
	memset(ans,0x3f,sizeof(ans));
	for(int i=0;i<4;i++){
		qx.push(sx);
		qy.push(sy);
		qt.push(i);
		ans[sx][sy][i]=0;
		in[sx][sy][i]=1;
	}
	int x,y,t;
	int nx,ny,nt;
	while(!qx.empty()){
		x=qx.front();
		y=qy.front();
		t=qt.front();
		qx.pop();
		qy.pop();
		qt.pop();
		in[x][y][t]=0;
		for(int i=0;i<4;i++){
			nx=x+d[i][0];
			ny=y+d[i][1];
			nt=i;
			if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]=='*'){
				continue;
			}
			if(nt==t){
				if(ans[nx][ny][nt]>ans[x][y][t]){
					ans[nx][ny][nt]=ans[x][y][t];
					if(!in[nx][ny][nt]){
						qx.push(nx);
						qy.push(ny);
						qt.push(nt);
						in[nx][ny][nt]=1;
					}
				}
			}
			else{
				if(ans[nx][ny][nt]>ans[x][y][t]+1){
					ans[nx][ny][nt]=ans[x][y][t]+1;
					if(!in[nx][ny][nt]){
						qx.push(nx);
						qy.push(ny);
						qt.push(nt);
						in[nx][ny][nt]=1;
					}
				}
			}
		}
	}
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(mp[i][j]=='T'){
				ex=i;
				ey=j;
			}
		}
	}
	bfs();
	int answer=(1<<30);
	for(int i=0;i<4;i++){
		answer=mn(answer,ans[ex][ey][i]);
	}
	if(answer<=2){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}