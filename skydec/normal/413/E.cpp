#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
char map[2][MAXN*4];
int n,m;
int tw[19];
int biu(int x,int y)
{
	if(x==-1||y==-1)return -2;
	return x+y;
}
void MIN(int &x,int y)
{
	if(y<0)return;
	if(x<0)x=y;
	if(y<x)x=y;
}
struct info
{
	int c[2][2];
	void init(int x)
	{
		if(map[0][x]=='X'||map[1][x]=='X')
		c[0][1]=c[1][0]=-1;
		else c[0][1]=c[1][0]=1;
		if(map[0][x]=='X')c[0][0]=-1;
		else c[0][0]=0;
		if(map[1][x]=='X')c[1][1]=-1;
		else c[1][1]=0;
	}
	info operator +(const info &b)const
	{
		info reu;
		for(int k1=0;k1<=1;k1++)
		for(int k2=0;k2<=1;k2++)
		{
			reu.c[k1][k2]=-1;
			for(int p2=0;p2<=1;p2++)
			MIN(reu.c[k1][k2],biu(c[k1][p2],b.c[p2][k2])+1);
		}
		return reu;
	}
}f[MAXN][19];
int TW(int x)
{
	int reu=0;
	while(x)
	{
		x/=2;
		reu++;
	}
	return reu-1;
}
info ask(int l,int r)
{
	//printf("%d %d\n",l,r);
	info reu=f[l][0];
	l++;
	int len=r-l+1;
	while(len)
	{
		int p=len&-len;
		reu=reu+f[l][TW(p)];
		l+=tw[TW(p)];
		len-=p;
	}
	return reu;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=1;i++)scanf("%s",map[i]+1);
	tw[0]=1;for(int i=1;i<=18;i++)tw[i]=tw[i-1]*2;
	for(int i=1;i<=n;i++)f[i][0].init(i);
	for(int j=1;j<=18;j++)
	for(int i=1;i<=n;i++)
	if(i+tw[j]-1<=n)
	{
		f[i][j]=f[i][j-1]+f[i+tw[j-1]][j-1];
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		int p1,p2;
		p1=(l>n);
		p2=(r>n);
		if(l>n)l-=n;
		if(r>n)r-=n;
		if(l>r)
		{
			int tmp=l;l=r;r=tmp;
			tmp=p1;p1=p2;p2=tmp;
		}
		info q=ask(l,r);
		printf("%d\n",q.c[p1][p2]);
	}
	return 0;
}