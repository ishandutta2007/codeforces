#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,cnt,z;
int a[233333],s[233333],d[233333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=sqrt(a[i])+1e-10;
		if(s[i]*s[i]==a[i])cnt++;
		if(a[i]==0)z++;
	}
	if(cnt>n/2)
	{
		int ans=0;
		while(cnt>n/2)
		{
			if(cnt>z)ans++;
			else ans+=2;
			cnt--;
		}
		printf("%d\n",ans);
	}
	else if(cnt<n/2)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			d[i]=min(abs(s[i]*s[i]-a[i]),abs((s[i]+1)*(s[i]+1)-a[i]));
		}
		sort(d+1,d+n+1);
		for(int i=1;i<=n/2;i++)ans+=d[i];
		printf("%lld\n",ans);
	}
	else printf("0\n");
	return 0;
}