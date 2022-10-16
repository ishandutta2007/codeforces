#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+1),b(n+1),pb(n+1),vis(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			pb[b[i]]=i;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(not vis[i])
			{
				int len=0;
				for(int j=i;not vis[j];j=pb[a[j]])
				{
					vis[j]=1;
					len++;
				}
				cnt+=len/2;
			}
		}
		long long ans=0;
		for(int l=1,r=n;l<=cnt;l++,r--)
		{
			ans+=(r-l)*2;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}