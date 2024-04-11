#include<bits/stdc++.h>
using namespace std;
vector<int> G1[111111],G2[111111];
int vis1[111111],vis2[111111];
queue<int> q0,q1,q2;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m1,m2,u,v;
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)q0.push(i);
	for(int i=1;i<=m1;i++)
	{
		cin>>u>>v;
		G1[u].push_back(v);
		G1[v].push_back(u);
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>u>>v;
		G2[u].push_back(v);
		G2[v].push_back(u);
	}
	cout<<n-1-max(m1,m2)<<endl;
	queue<pair<int,int> > q;
	q.emplace(1,1);
	q.emplace(2,1);
	vis1[1]=vis2[1]=1;
	while(m1<n-1 and m2<n-1)
	{
		while(!q.empty())
		{
			auto pr=q.front();q.pop();
			int u=pr.second;
			if(pr.first==1)
			{
				for(auto v:G1[u])
				{
					if(!vis1[v])
					{
						vis1[v]=1;
						q1.push(v);
						q.emplace(1,v);
					}
				}
			}
			else
			{
				for(auto v:G2[u])
				{
					if(!vis2[v])
					{
						vis2[v]=1;
						q2.push(v);
						q.emplace(2,v);
					}
				}
			}
		}
		u=v=0;
		while(v==0 and !q0.empty())
		{
			v=q0.front();q0.pop();
			if(vis1[v] or vis2[v])v=0;
		}
		if(v!=0)
		{
			u=1;
			G1[u].push_back(v);G1[v].push_back(u);G2[u].push_back(v);G2[v].push_back(u);
			vis1[v]=vis2[v]=1;
			q.emplace(1,v);q.emplace(2,v);
		}
		else
		{
			while(u==0 and !q1.empty())
			{
				u=q1.front();q1.pop();
				if(vis2[u])u=0;
			}
			while(v==0 and !q2.empty())
			{
				v=q2.front();q2.pop();
				if(vis1[v])v=0;
			}
			G1[u].push_back(v);G1[v].push_back(u);G2[u].push_back(v);G2[v].push_back(u);
			vis1[v]=vis2[u]=1;
			q.emplace(1,v);q.emplace(2,u);
		}
		assert(u!=0 and v!=0);
		cout<<u<<' '<<v<<"\n";
		m1++,m2++;
	}
	return 0;
}