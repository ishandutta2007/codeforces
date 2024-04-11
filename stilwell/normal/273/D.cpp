#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 1000000007
using namespace std;

int n,m,i,j,k,ans;
int f00[205][205],f01[205][205],f10[205][205],f11[205][205];

void add(int &a,int b){a+=b;if(a>=p)a-=p;}

int main()
{
	scanf("%d%d",&n,&m);
	for(;n;--n)
	{
		for(i=1;i<=m;++i)
		for(j=i;j<=m;++j)
		{
			if(i+1<=j)add(f11[i+1][j],f01[i][j]);
			if(i<=j-1)add(f11[i][j-1],f10[i][j]);
		}
		for(i=1;i<=m;++i)
		for(j=i;j<=m;++j)
		{
			if(i+1<=j)add(f10[i+1][j],f00[i][j]);
			if(i<=j-1)add(f01[i][j-1],f00[i][j]);
			if(i+1<=j-1)add(f11[i+1][j-1],f00[i][j]);
		}
		for(j=m;j>=1;--j)
		for(i=j;i>=2;--i)
		add(f00[i-1][j],f00[i][j]);
		for(i=1;i<=m;++i)
		for(j=1;j<m;++j)
		add(f00[i][j+1],f00[i][j]);
		
		for(j=1;j<=m;++j)
		for(i=1;i<j;++i)
		add(f10[i+1][j],f10[i][j]);
		for(i=1;i<=m;++i)
		for(j=i;j<m;++j)
		add(f10[i][j+1],f10[i][j]);
		
		for(i=1;i<=m;++i)
		for(j=m;j>i;--j)
		add(f01[i][j-1],f01[i][j]);
		for(j=m;j>=1;--j)
		for(i=j;i>=2;--i)
		add(f01[i-1][j],f01[i][j]);
		
		for(j=1;j<=m;++j)
		for(i=1;i<j;++i)
		add(f11[i+1][j],f11[i][j]);
		for(i=1;i<=m;++i)
		for(j=m;j>i;--j)
		add(f11[i][j-1],f11[i][j]);
		
		for(i=1;i<=m;++i)
		for(j=i;j<=m;++j)
		add(f00[i][j],1);
		
		for(i=1;i<=m;++i)
		for(j=i;j<=m;++j)
		{
			add(ans,f00[i][j]);
			add(ans,f01[i][j]);
			add(ans,f10[i][j]);
			add(ans,f11[i][j]);
		}
	}
	printf("%d\n",ans);
}