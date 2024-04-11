#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int a[200010],flag[200010],flag2[200010];
int main()
{
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		flag[a[i]]++;
	}
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		if(flag[a[i]]==1)continue;
		while(flag[cur])cur++;
		if(a[i]>cur||flag2[a[i]])
		{
			flag[a[i]]--;
			a[i]=cur;
			flag[cur]++;
			ans++;
		}
		else
		{
			flag2[a[i]]=1;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}