#include <cstdio>
#include <queue>
using namespace std;
bool vis[505][5005];
int d,s;
queue<int> qx,qy;
int pre[505][5005][3];
void bfs(){
	vis[0][0]=1;
	qx.push(0);
	qy.push(0);
	int x,y;
	int nx,ny;
	while(!qx.empty()){
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for(int i=0;i<10;i++){
			nx=(x<<1)+(x<<3)+i;
			ny=y+i;
			nx%=d;
			if(ny>s){
				continue;
			}
			if(vis[nx][ny]){
				continue;
			}
			vis[nx][ny]=1;
			qx.push(nx);
			qy.push(ny);
			pre[nx][ny][0]=x;
			pre[nx][ny][1]=y;
			pre[nx][ny][2]=i;
		}
	}
}
void print(int x,int y){
	if(x==0&&y==0){
		return;
	}
	print(pre[x][y][0],pre[x][y][1]);
	printf("%d",pre[x][y][2]);
}
int main(){
	scanf("%d%d",&d,&s);
	bfs();
	if(!vis[0][s]){
		puts("-1");
	}
	else{
		print(0,s);
		puts("");
	}
	return 0;
}