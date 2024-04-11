#include<cstdio>

using namespace std;

long long lon,n,i,a[100001],ans;

int main()
{
	scanf("%I64d%I64d",&lon,&n);
	for(i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	a[0]=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=a[i-1])ans+=a[i]-a[i-1];
		else ans+=(lon-a[i-1])+a[i];
	}
	printf("%I64d",ans);
}