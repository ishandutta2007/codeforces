#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
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
int n,m,lim,cnt,to[100001];
bool vis[100001],tag[100001];
array<int,3> a[100001];
vector<int> v[100001];
void solve()
{
	for(int i=1;i<=cnt;i++)
		if(a[i][0]&1)
			tag[to[a[i][1]]]=tag[to[a[i][2]]]=1;
		else
			tag[a[i][1]]=1;
	for(int i=1;i<=n;i++)
		if(tag[i])
			for(int j=i;;)
			{
				v[i].push_back(j);
				j=to[j];
				if(tag[j])
					break;
			}
	for(int i=1;i<=cnt;i++)
		if(a[i][0]&1)
			swap(to[a[i][1]],to[a[i][2]]);
		else
		{
			int ans=-1,tot=0;
			for(int l=a[i][1];!vis[l];l=to[v[l].back()])
			{
				tot+=v[l].size();
				vis[l]=1;
			}
			a[i][2]%=tot;
			for(int l=a[i][1];vis[l];l=to[v[l].back()])
			{
				if(ans==-1&&v[l].size()>a[i][2])
					ans=v[l][a[i][2]];
				a[i][2]-=v[l].size();
				vis[l]=0;
			}
			cout<<ans<<'\n';
		}
	for(int i=1;i<=cnt;i++)
		if(a[i][0]&1)
		{
			v[to[a[i][1]]].clear();
			v[to[a[i][2]]].clear();
			tag[to[a[i][1]]]=tag[to[a[i][2]]]=0;
		}
		else
		{
			v[a[i][1]].clear();
			tag[a[i][1]]=0; 
		}
	cnt=0;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		to[i]=read();
	lim=round(sqrt(m));
	while(m--)
	{
		int x=read(),y=read(),z=read();
		a[++cnt]={x,y,z};
		if(cnt%lim==0)
			solve();
	}
	if(cnt)
		solve();
	return 0;
}