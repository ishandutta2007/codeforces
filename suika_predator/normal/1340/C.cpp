#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
int n,m,k,g,r;
long long dis[11111][1111];
int a[11111];
deque<pair<int,int> > q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	cin>>g>>r;
	sort(a+1,a+m+1);
	memset(dis,0x3f,sizeof(dis));
	dis[0][0]=0;
	q.push_back(make_pair(0,0));
	while(!q.empty())
	{
		pair<int,int> _=q.front();q.pop_front();
		int i=_.first,j=_.second;
//		cerr<<i<<' '<<j<<' '<<dis[i][j]<<endl;
		if(i<m)
		{
			int t=a[i+1]-a[i]+j;
			if(t<g&&dis[i+1][t]==inf)
			{
				dis[i+1][t]=dis[i][j];
				q.push_front(make_pair(i+1,t));
			}
			else if(t==g&&dis[i+1][0]==inf)
			{
				dis[i+1][0]=dis[i][j]+1;
				q.push_back(make_pair(i+1,0));
			}
		}
		if(i>1)
		{
			int t=a[i]-a[i-1]+j;
			if(t<g&&dis[i-1][t]==inf)
			{
				dis[i-1][t]=dis[i][j];
				q.push_front(make_pair(i-1,t));
			}
			else if(t==g&&dis[i-1][0]==inf)
			{
				dis[i-1][0]=dis[i][j]+1;
				q.push_back(make_pair(i-1,0));
			}
		}
	}
	long long minn=inf;
	for(int i=1;i<g;i++)
	{
		if(dis[m][i]!=inf)
			minn=min(minn,i+dis[m][i]*(r+g));
	}
	if(dis[m][0]!=inf)
		minn=min(minn,dis[m][0]*(r+g)-r);
	if(minn==inf)cout<<-1<<endl;
	else cout<<minn<<endl;
	return 0;
}