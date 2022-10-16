#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int h[233333],ans[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
		{
			pq.emplace(0,i);
			h[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			int u=pq.top().second;pq.pop();
			ans[i]=u;
			h[u]+=x;
			pq.emplace(h[u],u);
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
		while(!pq.empty())pq.pop();
	}
	return 0;
}