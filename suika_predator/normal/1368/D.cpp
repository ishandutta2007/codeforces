#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[233333],cnt[23];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int b=0;b<20;b++)
		{
			if(a[i]&(1<<b))cnt[b]++;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long cur=0;
		for(int b=0;b<20;b++)
		{
			if(cnt[b]>=i)
			{
				cur+=(1<<b);
			}
		}
		ans+=cur*cur;
	}
	cout<<ans<<endl;
	return 0;
}