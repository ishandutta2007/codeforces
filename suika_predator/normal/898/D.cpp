#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,k,t,cnt,ans;
int a[1000010];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t]++;
	}
	for(int i=1;i<=1000000;i++)
	{
		cnt+=a[i];
		if(i-m>=1)cnt-=a[i-m];
		while(cnt>=k)
		{
			cnt--;
			a[i]--;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}