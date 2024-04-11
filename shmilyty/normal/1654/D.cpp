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
int ans,isp[200001],t,n,num[200001],maxx[200001],inv[200001],f[200001];
vector<int> pri,v[200001];
vector<array<int,3>> G[200001];
const int mod=998244353;
void dfs(int x,int fa)
{
	for(auto i:G[x])
		if(i[0]!=fa)
		{
			for(int l:v[i[1]])
			{
				num[l]++;
				maxx[l]=max(maxx[l],num[l]);
			}
			for(int l:v[i[2]])
				num[l]--;
			dfs(i[0],x);
			for(int l:v[i[1]])
				num[l]--;
			for(int l:v[i[2]])
				num[l]++;
		}
}
void dfs1(int x,int fa)
{
	for(auto i:G[x])
		if(i[0]!=fa)
		{
			f[i[0]]=f[x]*inv[i[1]]%mod*i[2]%mod;
			dfs1(i[0],x);
		}
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		G[i].clear();
	fill(num,num+1+n,0);
	fill(maxx,maxx+1+n,0);
	for(int i=1;i<n;i++)
	{
		int I=read(),L=read(),x=read(),y=read();
		int g=__gcd(x,y);
		x/=g;
		y/=g;
//		cout<<x<<" "<<y<<endl;
		G[I].push_back({L,x,y});
		G[L].push_back({I,y,x});
	}
	dfs(1,0);
	f[1]=1;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=maxx[i];l++)
			(f[1]*=i)%=mod;
//	cout<<f[1]<<endl;
	dfs1(1,0);
//	for(int i=1;i<=n;i++)
//		cout<<f[i]<<endl;
	ans=0;
	for(int i=1;i<=n;i++)
		(ans+=f[i])%=mod;
	cout<<ans<<'\n';
}
signed main()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<=200000;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=2;i<=200000;i++)
	{
		if(!isp[i])
			pri.push_back(i);
		for(int l:pri)
		{
			if(i*l>200000)
				break;
			isp[i*l]=1;
			if(i%l==0)
				break;
		}
	}
	for(int i=2;i<=200000;i++)
	{
		int x=i;
		for(int l:pri)
		{
			while(x%l==0)
			{
				v[i].push_back(l);
				x/=l;
			}
			if(!isp[x])
			{
				v[i].push_back(x);
				break;
			}
			if(x==1)
				break;
		}
	}
	t=read();
	while(t--)
		solve();
	return 0;
}