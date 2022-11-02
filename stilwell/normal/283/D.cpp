#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ans;
int b[5005],f[5005];
long long a[5005];

bool cal(int x,int y)
{
	int delta=y-x;
	if(a[x]%a[y]==0)
	{
		if(delta>b[y])return true;
		else return b[x]+delta==b[y];
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		for(;!(a[i]&1);a[i]>>=1)++b[i];
	}
	ans=n;
	for(i=1;i<=n;++i)
	{
		f[i]=i-1;
		for(j=1;j<i;++j)
		if(cal(j,i)&&f[j]+i-j-1<f[i])
		f[i]=f[j]+i-j-1;
		if(f[i]+n-i<ans)ans=f[i]+n-i;
	}
	printf("%d\n",ans);
}