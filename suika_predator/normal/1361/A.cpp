#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y;
vector<int> G[555555];
pair<int,int> srt[555555];
int ok[555555],t[555555];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		srt[i].first=t[i];
		srt[i].second=i;
	}
	sort(srt+1,srt+n+1);
	for(int i=1;i<=n;i++)
	{
		int u=srt[i].second;
//		cerr<<i<<' '<<u<<endl;
		for(auto x:G[u])
		{
			if(t[x])
				ok[t[x]]=1;
		}
		int mex;
		for(mex=1;ok[mex];mex++){}
		if(mex!=t[u])
		{
			cout<<-1<<endl;
			return 0;
		}
		for(auto x:G[u])
		{
			if(t[x])
				ok[t[x]]=0;
		}
	}
	for(int i=1;i<=n;i++)cout<<srt[i].second<<' ';
	return 0;
}