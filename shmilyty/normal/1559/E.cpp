#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int n,m,p[100001],mu[100001],pre[100001],L[100001],R[100001],f[51][100001],g[51][100001];
pair<int,int> a[51];
vector<int> pri;
const int mod=998244353;
int solve(int x)
{
	for(int i=1;i<=n;i++)
	{
		L[i]=(a[i].first+x-1)/x;
		R[i]=a[i].second/x;
//		cout<<L[i]<<" "<<R[i]<<endl;
		if(L[i]>R[i])
			return 0;
	}
	for(int i=0;i<=n;i++)
		for(int l=0;l<=m/x;l++)
			f[i][l]=g[i][l]=0;
	f[0][0]=1;
	for(int i=0;i<=m/x;i++)
		g[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int l=L[i];l<=m/x;l++)
		{
			f[i][l]=g[i-1][l-L[i]];
			if(l-R[i]>0)
				(f[i][l]+=mod-g[i-1][l-R[i]-1])%=mod;
//			cout<<i<<" "<<l<<" "<<f[i][l]<<endl;;
			g[i][l]=f[i][l];
			if(l)
				(g[i][l]+=g[i][l-1])%=mod;
		}
	return g[n][m/x];
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i]={x,y};
	}
	mu[1]=1;
	for(int i=2;i<=1e5;i++)
	{
		if(!p[i])
		{
			pri.push_back(i);
			mu[i]=-1;
		}
		for(int l=0;l<pri.size()&&pri[l]*i<=1e5;l++)
		{
			p[pri[l]*i]=1;
			if(i%pri[l]==0)
				break;
			mu[pri[l]*i]=-mu[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(mu[i]!=0)
			pre[i]=solve(i);
		
//		cout<<pre[i]<<endl;
	}
	int ans=0;
	for(int i=m;i>=1;i--)
	{
		(ans+=mod+mu[i]*pre[i]%mod)%=mod;
	}
	cout<<ans;
	return 0;
}