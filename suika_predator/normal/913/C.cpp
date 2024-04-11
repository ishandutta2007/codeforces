#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,l;
int a[2333];
long long ans;
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=i;j++)
		{
			if((1ll<<(i-j))*a[j]<a[i])
				a[i]=(1<<(i-j))*a[j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]<a[i-1])a[i-1]=a[i];
	}
	//for(int i=1;i<=n;i++)cout<<a[i]<<endl;
	long long minn=0x3f3f3f3f3f3f3f3fll;
	for(int i=n;i>=1;i--)
	{
		ans+=1ll*a[i]*(l/(1<<(i-1)));
		minn=min(minn,ans+a[i]);
		//cout<<i<<' '<<ans<<' '<<minn<<endl;
		l%=(1<<(i-1));
	}
	minn=min(minn,ans);
	printf("%lld\n",minn);
	return 0;
}