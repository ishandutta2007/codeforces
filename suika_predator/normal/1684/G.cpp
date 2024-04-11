#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<long long> a(n+5);
	int ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]*2>m)
		{
			ok=0;
			break;
		}
	}
	if(not ok)
	{
		cout<<-1<<"\n";
		return 0;
	}
	
	vector<vector<int>> G(n+5);
	int sp=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]*3>m)
		{
			sp++;
			for(int j=1;j<=n;j++)
			{
				if(a[i]%a[j]==0 and 2*a[i]+a[j]<=m)
				{
					G[i].push_back(j);
				}
			}
		}
	}
	vector<int> r(n+5),b(n+5),f(n+5);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(auto v:G[i])
		{
			if(not f[v])
			{
				r[i]=v;
				f[v]=i;
				cnt++;
				break;
			}
		}
	}
	function<bool(int)> find=[&](int x)
	{
		for(auto v:G[x])
		{
			if(not b[v])
			{
				b[v]=1;
				if(not f[v] or find(f[v]))
				{
					f[v]=x;
					r[x]=v;
					return true;
				}
			}
		}
		return false;
	};
	for(int i=1;i<=n;i++)
	{
		if(r[i])continue;
		for(int j=1;j<=n;j++)b[j]=0;
		if(find(i))cnt++;
	}
	if(cnt==sp)
	{
		vector<pair<int,int>> ans;
		for(int i=1;i<=n;i++)
		{
			if(r[i])
			{
//				cerr<<"pair "<<a[i]<<' '<<a[r[i]]<<endl;
				ans.emplace_back(2*a[i]+a[r[i]],a[i]+a[r[i]]);
			}
			else if(f[i])
			{
				continue;
			}
			else
			{
				ans.emplace_back(3*a[i],2*a[i]);
			}
		}
		cout<<ans.size()<<"\n";
		for(auto [x,y]:ans)
		{
			cout<<x<<' '<<y<<"\n";
		}
	}
	else
	{
		cout<<-1<<"\n";
	}
	
	return 0;
}