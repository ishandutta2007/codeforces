#include<bits/stdc++.h>
using namespace std;
const int N=60,pn=9;
int n,tot,sx;
int a[N][N],p[3][3],vis[N][N];
struct Query
{
	int ax,ay,bx,by;
};
Query operator +(Query a,int b)
{
	return (Query){a.ax+b,a.ay+b,a.bx+b,a.by+b};
}
int zpd=0;
int h[20];
Query q[20];
int get(Query d)
{
	int x;
	printf("? %d %d %d %d\n",d.ax,d.ay,d.bx,d.by);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int cnt,pd;
int stk[20];
void check()
{
	int i;
	if(zpd==2) printf("L%d %d %d\n",stk[1],stk[2],stk[3]);
	for(i=1;i<=cnt;i++) 
	{
		if(stk[i]!=stk[cnt-i+1]) return ; 
	}
	pd=1;
}
void dfs(int x,int y,int tx,int ty)
{
	cnt++;stk[cnt]=p[x][y];
	if(x==tx&&y==ty)
	{
		check();
		cnt--;
		return ;
	}
	if(x<tx) dfs(x+1,y,tx,ty);
	if(y<ty) dfs(x,y+1,tx,ty);
	cnt--;
}
int find(Query d)
{
	cnt=0;pd=0;
	dfs(d.ax-1,d.ay-1,d.bx-1,d.by-1);
	return pd;
}
int main()
{
	int i,j,ns,bz;
	scanf("%d",&n);
	tot=9;
	sx=1<<tot;
	q[1]=(Query){1,1,2,2};
	q[2]=(Query){1,1,1,3};
	q[3]=(Query){1,1,3,1};
	q[4]=(Query){2,2,3,3};
	q[5]=(Query){1,1,3,2};
	q[6]=(Query){1,1,2,3};
	q[7]=(Query){1,2,3,3};
	q[8]=(Query){2,1,3,3};
	q[9]=(Query){1,2,3,2};
	q[10]=(Query){2,1,2,3};
	vis[1][1]=vis[n][n]=1;
	a[1][1]=1;
	for(i=2;i<n;i++) 
	{
		vis[i][i]=1;
		if(get((Query){i-1,i-1,i,i})==1) a[i][i]=a[i-1][i-1];
		else a[i][i]=(a[i-1][i-1]^1);
	}
	for(i=1;i<=n-2;i++)
	{
		if(a[i][i]==1&&a[i+2][i+2]==0) 
		{
			bz=i;
			break;
		}
	}
	//printf("bz%d\n",bz);
	h[1]=(a[bz][bz]==a[bz+1][bz+1]);
	h[4]=(a[bz+1][bz+1]==a[bz+2][bz+2]);
	for(i=1;i<=10;i++) 
	{
		if(i!=1&&i!=4) h[i]=get((q[i]+(bz-1)));
	}
	for(ns=1;ns<sx;ns+=2)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(ns&(1<<(i*3+j))) p[i][j]=1;
				else p[i][j]=0;
				
			}
		}
		bool pd=1;
		for(i=1;i<=10;i++)
		{
			if(find(q[i])!=h[i]) 
			{
				//printf("#%d\n",i);
				pd=0;
			}
		}
		if(pd==1)
		{
			for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
				a[bz+i][bz+j]=p[i][j];
			}
		}
	}
	for(i=bz;i<=bz+2;i++)
	{
		for(j=bz-1;j>=1;j--)
		{
			if(get((Query){i,j,i,j+2})==1) a[i][j]=a[i][j+2];
			else a[i][j]=(a[i][j+2]^1);
		}
		for(j=bz+3;j<=n;j++)
		{
			if(get((Query){i,j-2,i,j})==1) a[i][j]=a[i][j-2];
			else a[i][j]=(a[i][j-2]^1);
		}
	}
	for(j=1;j<=n;j++)
	{
		for(i=bz-1;i>=1;i--)
		{
			if(i==j) continue;
			if(get((Query){i,j,i+2,j})==1) a[i][j]=a[i+2][j];
			else a[i][j]=(a[i+2][j]^1);
		}
		for(i=bz+3;i<=n;i++)
		{
			if(i==j) continue;
			if(get((Query){i-2,j,i,j})==1) a[i][j]=a[i-2][j];
			else a[i][j]=(a[i-2][j]^1);
		}
	}
	puts("!");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			putchar(a[i][j]+48);
		}
		putchar('\n');
	}
	fflush(stdout);
	return 0;
}