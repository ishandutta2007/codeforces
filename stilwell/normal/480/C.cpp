#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int n,m,a,b,i,j,k,l,r,ans;
int f[5005][5005];

void add(int &a,int b){a+=b;if(a>=p)a-=p;}

int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&m);
	f[0][a]=1;
	for(i=0;i<m;++i)
	{
		for(j=1;j<=n;++j)
		if(j!=b)
		{
			if(j<b)k=b-j;else k=j-b;--k;
			l=j-k;if(l<1)l=1;
			r=j+k+1;if(r>n)r=n+1;
			add(f[i+1][l],f[i][j]);
			add(f[i+1][r],p-f[i][j]);
		}
		for(j=1;j<=n;++j)add(f[i+1][j],f[i+1][j-1]);
		for(j=1;j<=n;++j)add(f[i+1][j],p-f[i][j]);
	}
	for(i=1;i<=n;++i)if(i!=b)add(ans,f[m][i]);
	printf("%d\n",ans);
}