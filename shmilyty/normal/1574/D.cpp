#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
priority_queue<pair<int,vector<int>>>q;
int n,m,c[11],a[11][200001];
set<vector<int>> vis,s;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
		for(int l=1;l<=c[i];l++)
			a[i][l]=read();
	}
	m=read();
	while(m--)
	{
		vector<int> v;
		for(int i=1;i<=n;i++)
			v.push_back(read());
		s.insert(v);
	}
	vector<int> v;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		tot+=a[i][c[i]];
		v.push_back(c[i]);
	}
	q.push({tot,v});
	while(!q.empty())
	{
		auto f=q.top();
		q.pop();
		int sum=f.first;
		vector<int> v=f.second;
		if(vis.count(v))
			continue;
		if(!s.count(v))
		{
			for(int i:v)
				cout<<i<<" ";
			return 0;
		} 
		vis.insert(v);
		for(int i=0;i<n;i++)
			if(v[i]!=1)
			{
				sum-=a[i+1][v[i]];
				sum+=a[i+1][v[i]-1];
				v[i]--;
				q.push({sum,v});
				sum-=a[i+1][v[i]];
				sum+=a[i+1][v[i]+1];
				v[i]++;
			}
	}
	return 0;
}