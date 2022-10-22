#include<bits/stdc++.h>
using namespace std;
bool vis[15][15][2];
double f[15][15][2];
int up[15][15];
double work(int x,int y,bool U){
	if(x==1&&y==1)return 0;
	if(y<1)return work(x-1,1-y,U);
	if(y>10)return work(x-1,10-(y-10-1),U);
	if(x==1&&y<=7)return 6.0;
	if(vis[x][y][U])return f[x][y][U];
	vis[x][y][U]=1;
	double tmp=1e9;
	f[x][y][U]=0;
	if(up[x][y]&&x-up[x][y]>0&&!U)tmp=work(x-up[x][y],y,1);
	for(int i=1;i<=6;++i)
		if(x&1) f[x][y][U]+=work(x,y-i,0)/6.0;
		else f[x][y][U]+=work(x,y+i,0)/6.0;
	f[x][y][U]=min(f[x][y][U]+1.0,tmp);
	return f[x][y][U];
}
int main(){
	for(int i=1;i<=10;++i)
		for(int j=1;j<=10;++j)
			scanf("%d",&up[i][j]);
	printf("%.10lf",work(10,1,0));
	return 0;
}