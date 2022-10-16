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
int n,m,R,G,ans,dis,f[10001][1001],a[10001];
deque<array<int,2>> q;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
		a[i]=read();
	sort(a+1,a+1+m);
	memset(f,-1,sizeof(f));
	ans=INF;
	G=read();
	R=read();
	f[1][0]=0;
	q.push_back({1,0});
	while(!q.empty())
	{
		auto x=q.front();
		q.pop_front();
		if(x[0]==m)
		{
			if(!x[1])
				ans=min(ans,f[m][x[1]]*(G+R)-R);
			else
				ans=min(ans,f[m][x[1]]*(G+R)+x[1]);
			continue;
		}
		dis=a[x[0]+1]-a[x[0]];
		if(dis+x[1]<G&&f[x[0]+1][dis+x[1]]==-1)
		{
			f[x[0]+1][dis+x[1]]=f[x[0]][x[1]];
			q.push_front({x[0]+1,dis+x[1]});
		}
		if(dis+x[1]==G&&f[x[0]+1][0]==-1)
		{
			f[x[0]+1][0]=f[x[0]][x[1]]+1;
			q.push_back({x[0]+1,0});
		}
		if(x[0]==1)
			continue;
		dis=a[x[0]]-a[x[0]-1];
		if(dis+x[1]<G&&f[x[0]-1][dis+x[1]]==-1)
		{
			f[x[0]-1][dis+x[1]]=f[x[0]][x[1]];
			q.push_front({x[0]-1,dis+x[1]});
		}
		if(dis+x[1]==G&&f[x[0]-1][0]==-1)
		{
			f[x[0]-1][0]=f[x[0]][x[1]]+1;
			q.push_back({x[0]-1,0});
		}
	}
	if(ans==INF)
		puts("-1");
	else
		cout<<ans;
	return 0;
}