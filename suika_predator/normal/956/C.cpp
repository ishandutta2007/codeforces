#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,a[233333],mk[233333],cur;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mk[i]=a[i];
	}
	for(int i=n;i>=1;i--)mk[i-1]=max(mk[i]-1,mk[i-1]);
	for(int i=1;i<=n;i++)mk[i]=max(mk[i],mk[i-1]);
	for(int i=1;i<=n;i++)ans+=mk[i]-a[i];
	printf("%lld\n",ans);
	return 0;
}