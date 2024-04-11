#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,M,i,j,k,ans;
int f[45][300][300];

void dp(int x,int y,int z)
{
	if(x>m)
	{
		int sum=0,tmp;
		for(tmp=z;tmp;tmp/=2)sum+=tmp%2;
		if(f[i][j][k]+sum<f[i+1][y][z])
		f[i+1][y][z]=f[i][j][k]+sum;
		return;
	}
	if(k&(1<<x-1))dp(x+1,y,z);
	else
	{
		if(x>1)dp(x+1,y,z|(1<<x-2));
		if(x<m)dp(x+1,y,z|(1<<x));
		dp(x+1,y|(1<<x-1),z);
		dp(x+1,y,z|(1<<x-1));
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	if(n<m)swap(n,m);
	M=1<<m;
	memset(f,0x3f,sizeof(f));
	f[1][0][0]=0;
	for(i=1;i<=n;++i)
	for(j=0;j<M;++j)
	for(k=0;k<M;++k)
	dp(1,0,j);
	ans=n*m;
	for(i=0;i<M;++i)if(f[n+1][0][i]<ans)ans=f[n+1][0][i];
	printf("%d\n",n*m-ans);
}