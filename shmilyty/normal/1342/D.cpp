#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans,m[200001],c[200001],num[200001];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		num[m[i]]++;
	}
	for(int i=200000;i>=1;i--)
		num[i-1]+=num[i];
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		ans=max(ans,(num[i]+c[i]-1)/c[i]);
	}
	cout<<ans<<endl;
	sort(m+1,m+1+n);
	for(int i=1;i<=ans;i++)
	{
		int t=0,now=i;
		while(now<=n)
		{
			t++;
			now+=ans;
		}
		cout<<t;
		now=i;
		while(now<=n)
		{
			cout<<" "<<m[now];
			now+=ans;
		}
		cout<<endl;
	}
	return 0;
}