#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1005;
int n,m;
int c[N][N];
int cnt;
int ox[N*N],oy[N*N],oc[N*N],opc;
void opt(int x,int y,int cur)
{
	opc++;
	ox[opc]=x;
	oy[opc]=y;
	oc[opc]=cur;
	cnt-=(c[x][y]>0);
	cnt-=(c[x][y+1]>0);
	cnt-=(c[x+1][y]>0);
	cnt-=(c[x+1][y+1]>0);
	c[x][y]=c[x][y+1]=c[x+1][y]=c[x+1][y+1]=0;
}
void chk(int x,int y)
{
	if (x<1||x>=n||y<1||y>=m)
		return;
	int cur=0;
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
			cur=max(cur,c[x+i][y+j]);
	if (cur==0)
		return;
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)	
			if (c[x+i][y+j]!=0&&c[x+i][y+j]!=cur)
				return;
	opt(x,y,cur);
	for (int i=-1;i<=1;i++)
		for (int j=-1;j<=1;j++)
			if (i!=0||j!=0)
				chk(x+i,y+j);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&c[i][j]);
	cnt=n*m;
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
			chk(i,j);
	if (cnt)
		printf("-1\n");
	else
	{
		printf("%d\n",opc);
		for (int i=opc;i;i--)
			printf("%d %d %d\n",ox[i],oy[i],oc[i]);
	}
	return 0;
}