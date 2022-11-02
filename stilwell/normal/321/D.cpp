#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ans,sum,sum1,sum0,tmp1,tmp0;
int a[55][55][2],b[55];

void dfs(int x)
{
	if(x>m)
	{
		for(i=m+1;i<=n;++i)b[i]=b[m]^b[i-m];
		sum=0;
		for(i=1;i<=n;++i)sum+=a[m][i][b[i]];
		for(i=1;i<m;++i)
		{
			sum1=a[i][m][1]+a[i+m][m][b[m]^1];
			for(j=1;j<m;++j)
			{
				tmp1=a[i][j][1]+a[i][j+m][0]+a[i+m][j][1^b[j]]+a[i+m][j+m][b[j]^b[m]];
				tmp0=a[i][j][0]+a[i][j+m][1]+a[i+m][j][b[j]]+a[i+m][j+m][b[j]^b[m]^1];
				sum1+=max(tmp1,tmp0);
			}
			sum0=a[i][m][0]+a[i+m][m][b[m]];
			for(j=1;j<m;++j)
			{
				tmp1=a[i][j][1]+a[i][j+m][1]+a[i+m][j][1^b[j]]+a[i+m][j+m][b[j]^b[m]^1];
				tmp0=a[i][j][0]+a[i][j+m][0]+a[i+m][j][b[j]]+a[i+m][j+m][b[j]^b[m]];
				sum0+=max(tmp1,tmp0);
			}
			sum+=max(sum1,sum0);
		}
		if(sum>ans)ans=sum;
		return;
	}
	b[x]=1;dfs(x+1);
	b[x]=0;dfs(x+1);
}

int main()
{
	scanf("%d",&n);m=n+1>>1;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	scanf("%d",&a[i][j][0]),a[i][j][1]=-a[i][j][0];
	ans=0x80000000;
	dfs(1);
	printf("%d\n",ans);
}