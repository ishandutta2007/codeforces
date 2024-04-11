#include<bits/stdc++.h>
using namespace std;
int sq[11111111],num[11111111];
int a[233333];
int f[233333][23];
int go[233333][23];
multiset<int> s;
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=1;i<=10000;i++)
	{
		for(int j=i*i;j<=10000000;j+=i*i)
		{
			sq[j]=i;
		}
	}
	int T;
	cin>>T;
	int n,k;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]=a[i]/sq[a[i]]/sq[a[i]];
			memset(f[i],0x3f,sizeof(f[i]));
			num[a[i]]=n+1;
		}
		s.clear();
		for(int i=1;i<=k;i++)
			s.insert(n+1);
		for(int i=n;i>=1;i--)
		{
			s.insert(num[a[i]]);
			while((int)s.size()>k+1)s.erase(--s.end());
			num[a[i]]=i;
			int j=0;
			for(auto it=s.begin();j<k+1;j++,it++)
			{
				go[i][j]=(*it)-1;
//				cerr<<i<<' '<<j<<' '<<go[i][j]<<endl;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				for(int t=0;j+t<=k;t++)
				{
					f[go[i][t]][j+t]=min(f[go[i][t]][j+t],f[i-1][j]+1);
				}
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=k;i++)
			ans=min(ans,f[n][i]);
		cout<<ans<<endl;
	}
	
	return 0;
}