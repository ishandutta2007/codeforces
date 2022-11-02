#include<cstdio>
#include<cmath>

using namespace std;

bool a[40000001],b[40000001];
long long i,j,p,n,ans;

int main()
{
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
	{
		if(!a[i])
		{
			a[i]=1,ans++;
			p=trunc(sqrt(n*n-i*i));
			if(!b[p])b[p]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1,ans++;
			p=trunc(sqrt(n*n-i*i));
			if(!a[p])a[p]=1;
		}
	}
	ans-=1;
	ans*=4;
	if(n==0)ans=1;
	printf("%I64d",ans);
}