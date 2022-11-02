#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,t,n,m,A,B,i,j,k,tmp1,tmp2,u,v,top;
char s[25][25],p[55][55];
int f[55][55][55][55],done[55][55][55][55];
int mex[105][10005];

int sg(int u,int d,int l,int r)
{
	if(u>d||l>r)return 0;
	if(done[u][d][l][r]==T)return f[u][d][l][r];
	int i,j,now=++t;
	++top;
	for(i=u;i<=d;++i)
	for(j=l;j<=r;++j)
	{
		if(p[i][j]=='R')mex[top][sg(u,d,l,j-1)^sg(u,d,j+1,r)]=now;
		if(p[i][j]=='L')mex[top][sg(u,i-1,l,r)^sg(i+1,d,l,r)]=now;
		if(p[i][j]=='X')mex[top][sg(u,i-1,l,j-1)^sg(u,i-1,j+1,r)^sg(i+1,d,l,j-1)^sg(i+1,d,j+1,r)]=now;
	}
	for(i=0;;++i)
	if(mex[top][i]!=now)
	{
		done[u][d][l][r]=T;
		f[u][d][l][r]=i;
		--top;
		return i;
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(i=1;i<=50;++i)
		for(j=1;j<=50;++j)
		p[i][j]='.';
		A=0;
		B=n/2+n%2+m/2+m%2-1;
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		if((i+j)%2==0)
		{
			u=(i+j-1)/2+1;
			if(u>A)A=u;
			v=(j-i)/2+(n/2+n%2);
			p[u][v]=s[i][j];
		}
		++T;
		tmp1=sg(1,A,1,B);
		for(i=1;i<=50;++i)
		for(j=1;j<=50;++j)
		p[i][j]='.';
		A=0;
		B=n/2+m/2;
		for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		if((i+j)%2==1)
		{
			u=(i+j-1)/2;
			if(u>A)A=u;
			v=(j-i+1)/2+(n/2);
			p[u][v]=s[i][j];
		}
		++T;
		tmp2=sg(1,A,1,B);
		if(tmp1^tmp2)printf("WIN\n");
		else printf("LOSE\n");
	}
}