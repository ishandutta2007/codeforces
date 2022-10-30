#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,i,j,k,Sx,Sy,ans;
int x[10],y[10],f[200],g[200],tot;
char s[15][10005];
bool use[5];

void add(int &x,int y){x+=y;if(x>=p)x-=p;}
int dp()
{
	int i;
	f[000]=f[001]=f[010]=f[100]=f[011]=f[101]=f[110]=f[111]=0;
	f[000]=1;
	for(i=1;i<=n;++i)
	{
		g[000]=g[001]=g[010]=g[100]=g[011]=g[101]=g[110]=g[111]=0;
		if(s[1][i]!='.')f[100]=f[101]=f[110]=f[111]=0;
		if(s[2][i]!='.')f[010]=f[011]=f[110]=f[111]=0;
		if(s[3][i]!='.')f[001]=f[011]=f[101]=f[111]=0;
		if(f[000])
		{
			if(s[1][i]!='.')add(f[100],f[000]);else
			if(s[2][i]!='.')add(f[010],f[000]);else
			if(s[3][i]!='.')add(f[001],f[000]);else
			{
				add(g[100],f[000]);
				add(g[001],f[000]);
				add(g[111],f[000]);
			}
		}
		if(f[001])
		{
			if(s[1][i]!='.')add(f[101],f[001]);else
			if(s[2][i]!='.')add(f[011],f[001]);else
			{
				add(g[000],f[001]);
				add(g[110],f[001]);
			}
		}
		if(f[010])
		{
			if(s[1][i]!='.')add(f[110],f[010]);else
			if(s[3][i]!='.')add(f[011],f[010]);else
			{
				add(g[101],f[010]);
			}
		}
		if(f[100])
		{
			if(s[2][i]!='.')add(f[110],f[100]);else
			if(s[3][i]!='.')add(f[101],f[100]);else
			{
				add(g[000],f[100]);
				add(g[011],f[100]);
			}
		}
		if(f[011])
		{
			if(s[1][i]!='.')add(f[111],f[011]);else
			{
				add(g[100],f[011]);
			}
		}
		if(f[101])
		{
			if(s[2][i]!='.')add(f[111],f[101]);else
			{
				add(g[010],f[101]);
			}
		}
		if(f[110])
		{
			if(s[3][i]!='.')add(f[111],f[110]);else
			{
				add(g[001],f[110]);
			}
		}
		if(f[111])
		{
			add(g[000],f[111]);
		}
		f[000]=g[000];
		f[001]=g[001];f[010]=g[010];f[100]=g[100];
		f[011]=g[011];f[101]=g[101];f[110]=g[110];
		f[111]=g[111];
	}
	return f[000];
}
void dfs(int a,int b)
{
	if(a>tot/2)
	{
		int i,j;
		if(b)
		{
			for(i=1;i<=tot/2;++i)
			if(use[i])
			{
				j=i*2-1;s[x[j]][y[j]]='X';
				j=i*2;  s[x[j]][y[j]]='X';
			}
			j=dp();
			if(b%2)add(ans,j);else add(ans,p-j);
			for(i=1;i<=tot/2;++i)
			if(use[i])
			{
				j=i*2-1;s[x[j]][y[j]]='.';
				j=i*2;  s[x[j]][y[j]]='.';
			}
		}
		return;
	}
	use[a]=true;dfs(a+1,b+1);
	use[a]=false;dfs(a+1,b);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=3;++i)scanf("%s",s[i]+1);
	for(i=1;i<=3;++i)
	for(j=1;j<=n;++j)
	if(s[i][j]=='O')
	Sx=i,Sy=j;
	if(Sx-2>=1&&s[Sx-1][Sy]=='.'&&s[Sx-2][Sy]=='.')
	{
		x[++tot]=Sx-1;y[tot]=Sy;
		x[++tot]=Sx-2;y[tot]=Sy;
	}
	if(Sx+2<=3&&s[Sx+1][Sy]=='.'&&s[Sx+2][Sy]=='.')
	{
		x[++tot]=Sx+1;y[tot]=Sy;
		x[++tot]=Sx+2;y[tot]=Sy;
	}
	if(Sy-2>=1&&s[Sx][Sy-1]=='.'&&s[Sx][Sy-2]=='.')
	{
		x[++tot]=Sx;y[tot]=Sy-1;
		x[++tot]=Sx;y[tot]=Sy-2;
	}
	if(Sy+2<=n&&s[Sx][Sy+1]=='.'&&s[Sx][Sy+2]=='.')
	{
		x[++tot]=Sx;y[tot]=Sy+1;
		x[++tot]=Sx;y[tot]=Sy+2;
	}
	dfs(1,0);
	printf("%d\n",ans);
}