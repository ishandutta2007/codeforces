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
		vector<int> a(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long ans=0;
		vector<int> cnt(n+5);
		for(int r=n;r>=2;r--)
		{
			for(int i=a[r];i<=n;i++)
				cnt[i]++;
			long long tmp=0;
			for(int l=r-2;l>=2;l--)
			{
				tmp+=cnt[a[l]];
				if(a[l-1]<a[r-1])
					ans+=tmp;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}