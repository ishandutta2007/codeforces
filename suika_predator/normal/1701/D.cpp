#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> b(n+5);
		vector<vector<pair<int,int>>> G(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			// floor(i/a[i])=b[i]
			int l=1,r=n;
			while(l<r)
			{
				int mid=(l+r+1)/2;
				if(i/mid<b[i])r=mid-1;
				else l=mid;
			}
			int R=l;
			l=1,r=n;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(i/mid<=b[i])r=mid;
				else l=mid+1;
			}
			int L=l;
			G[L].emplace_back(R,i);
//			cerr<<i<<' '<<L<<' '<<R<<endl;
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		vector<int> ans(n+5);
		for(int i=1;i<=n;i++)
		{
			for(auto [r,id]:G[i])
				pq.emplace(r,id);
			auto [r,id]=pq.top();pq.pop();
			ans[id]=i;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<"\n";
	}
	
	return 0;
}