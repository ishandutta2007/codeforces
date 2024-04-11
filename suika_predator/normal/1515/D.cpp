#include<bits/stdc++.h>
using namespace std;
int T,n,l,r,x;
int cnt[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>l>>r;
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=l;i++)
		{
			cin>>x;
			cnt[x]++;
		}
		for(int i=1;i<=r;i++)
		{
			cin>>x;
			cnt[x]--;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			while(l>r&&cnt[i]>=2)
			{
				l-=2;
				cnt[i]-=2;
				ans++;
			}
			while(l<r&&cnt[i]<=-2)
			{
				r-=2;
				cnt[i]+=2;
				ans++;
			}
		}
		int tans=0;
		tans+=abs(r-l);
		for(int i=1;i<=n;i++)
		{
			tans+=abs(cnt[i]);
		}
		cout<<ans+tans/2<<endl;
	}
	return 0;
}