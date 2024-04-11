#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
struct que{
	int to,val;
	bool operator<(const que&a)const
	{
		return val>a.val;
	}
};
priority_queue<que> q; 
vector<array<int,2>> G[2010];
int n,m,s,t,ns,nt,p[2010],dis[2010],tmp[2][2010],cnt[2010][2010],sum[2010][2010],f[2][2010][2010];
map<int,int> S,T;
void dij(int x)
{
	fill(dis+1,dis+1+n,INF);
	dis[x]=0;
	q.push({x,0});
	while(!q.empty())
	{
		int u=q.top().to,v=q.top().val;
		q.pop(); 
		if(dis[u]!=v)
			continue;
		for(auto i:G[u])
			if(dis[i[0]]>v+i[1])
			{
				dis[i[0]]=v+i[1];
				q.push({i[0],v+i[1]});
			}
	}
}
signed main()
{
	n=read();
	m=read();
	s=read();
	t=read();
	for(int i=1;i<=n;i++)
		p[i]=read();
	while(m--)
	{
		int x=read(),y=read(),z=read();
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	dij(s);
	for(int i=1;i<=n;i++)
		tmp[0][i]=dis[i];
	sort(dis+1,dis+1+n);
	for(int i=1;i<=n;i++)
		if(i==1||dis[i]!=dis[i-1])
			S[dis[i]]=++ns;
	dij(t);
	for(int i=1;i<=n;i++)
		tmp[1][i]=dis[i];
	sort(dis+1,dis+1+n);
	for(int i=1;i<=n;i++)
		if(i==1||dis[i]!=dis[i-1])
			T[dis[i]]=++nt;
	for(int i=1;i<=n;i++)
	{
		sum[S[tmp[0][i]]][T[tmp[1][i]]]+=p[i];
		cnt[S[tmp[0][i]]][T[tmp[1][i]]]++;
	}
	for(int i=1;i<=ns;i++)
		for(int l=1;l<=nt;l++)
		{
			sum[i][l]+=sum[i][l-1]+sum[i-1][l]-sum[i-1][l-1];
			cnt[i][l]+=cnt[i][l-1]+cnt[i-1][l]-cnt[i-1][l-1];
		}
	for(int i=ns;i;i--)
		for(int l=nt;l;l--)
		{
			if(cnt[i][nt]+cnt[i-1][l-1]-cnt[i][l-1]-cnt[i-1][nt])
				f[0][i][l]=max(f[0][i+1][l],f[1][i+1][l])+(sum[i][nt]+sum[i-1][l-1]-sum[i][l-1]-sum[i-1][nt]);
			else
				f[0][i][l]=f[0][i+1][l];
			if(cnt[ns][l]+cnt[i-1][l-1]-cnt[i-1][l]-cnt[ns][l-1])
				f[1][i][l]=min(f[0][i][l+1],f[1][i][l+1])-(sum[ns][l]+sum[i-1][l-1]-sum[i-1][l]-sum[ns][l-1]);
			else
				f[1][i][l]=f[1][i][l+1];
		}
	if(f[0][1][1]>0)
		puts("Break a heart");
	elif(f[0][1][1]==0)
		puts("Flowers");
	else
		puts("Cry");
	return 0;
}