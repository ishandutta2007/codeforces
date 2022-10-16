#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> a(n+5);
		for(int i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
		int l=1,r=m*2;
		while(l<r)
		{
			int mid=(l+r)/2;
			long long need=0,ex=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]<=mid)ex+=(mid-a[i])/2;
				else need+=a[i]-mid;
			}
			if(need<=ex)r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	
	return 0;
}