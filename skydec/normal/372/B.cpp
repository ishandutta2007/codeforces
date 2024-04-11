#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int f[45][45][45][45];
char str[45][45];int n,m;
int up[45][45];
int q;
void init()
{
	rep(i,1,n)rep(j,1,m)if(str[i][j]=='1')up[i][j]=0;else up[i][j]=up[i-1][j]+1;
	rep(i,1,n)rep(j,1,m)rep(x,i,n)rep(y,j,m)
	{
		f[i][j][x][y]=f[i][j][x-1][y]+f[i][j][x][y-1]-f[i][j][x-1][y-1];
		int res=0;int Min=x-i+1;
		per(k,y,j)
		{
			Min=min(Min,up[x][k]);
			res+=Min;
		}
		f[i][j][x][y]+=res;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n)scanf("%s",str[i]+1);
	init();
	while(q--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",f[a][b][c][d]);
	}
	return 0;
}