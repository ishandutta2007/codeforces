#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,a,b,c,i,j,k,ans;
int miu[2005],gcd[2005][2005];

int cal(int a,int b)
{
	if(!b)return a;
	if(gcd[a][b])return gcd[a][b];
	gcd[a][b]=cal(b,a%b);
}

int calc(int x,int y)
{
	int i,sum=0;
	for(i=1;i<=x;++i)if(gcd[i][y]==1)sum+=x/i;
	return sum;
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	n=max(max(a,b),c);
	for(i=1;i<=n;++i)
	{
		miu[i]=1;k=i;
		for(j=2;j<=k;++j)
		if(k%j==0)
		{
			k/=j;miu[i]=-miu[i];
			if(k%j==0)miu[i]=0;
		}
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(!gcd[i][j])cal(i,j);
	for(i=1;i<=a;++i)
	for(j=1;j<=n;++j)
	if(gcd[i][j]==1&&miu[j])
	ans+=miu[j]*(a/i)*calc(b/j,i)*calc(c/j,i);
	ans%=1073741824;
	if(ans<0)ans+=1073741824;
	printf("%d\n",ans);
}