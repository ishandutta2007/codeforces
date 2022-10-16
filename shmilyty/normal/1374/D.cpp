#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int> num;
int t,a[200001];
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		int n,k,ans=0,maxx=0;
		scanf("%lld%lld",&n,&k);
		num.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%k==0)	
				continue; 
			num[k-a[i]%k]++;
			if(num[k-a[i]%k]==maxx)
				ans=max(ans,k-a[i]%k);
			if(num[k-a[i]%k]>maxx)
			{
				maxx=num[k-a[i]%k];
				ans=k-a[i]%k;
			}
		}
		if(maxx==0&&ans==0)
			puts("0");
		else
			cout<<(maxx-1)*k+ans+1<<endl;
	} 
	return 0;
}