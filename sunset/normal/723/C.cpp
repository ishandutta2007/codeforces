#include<bits/stdc++.h>

using namespace std;

const int maxn=2333;

int m,n,s,a[maxn],cnt[maxn],flag[maxn],change;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=m)
			cnt[a[i]]++;
	}
	int ave=n/m;
	for(int i=1;i<=m;i++)
	{
		if(cnt[i]<ave)
			flag[i]=ave-cnt[i];
		s+=flag[i];
	}
	if(s==0)
	{
		int maxx=19260817;
		for(int i=1;i<=m;i++)
			maxx=min(maxx,cnt[i]);
		printf("%d %d\n",maxx,0);
		for(int i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("%d",a[n]);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>m)
		{
			for(int j=1;j<=m;j++)
				if(flag[j])
				{
					a[i]=j,change++,flag[j]--,cnt[a[i]]++;break;
				}
		}
		else
		{
			if(cnt[a[i]]>ave)
				for(int j=1;j<=m;j++)
					if(flag[j])
					{
						cnt[a[i]]--,a[i]=j,change++,flag[j]--;break;
					}
		}
	}
	printf("%d %d\n",ave,change);
	for(int i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d",a[n]);
	return 0;
}