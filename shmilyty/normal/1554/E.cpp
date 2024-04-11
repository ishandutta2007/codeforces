#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,ans,k,a[100001],in[100001],nn[100001],flag;
vector<int> G[100001];
const int mod=998244353;
int dfs(int x,int fa)
{
    if(!flag) 
		return 0;
    int tot=G[x].size();
    for(int i:G[x])
		if(i!=fa) 
			tot-=dfs(i,x);
    if(tot%k&&(tot-1)%k) 
		flag=0;
    if(tot%k==0)
	{
		ans=__gcd(ans,tot);
		return 1;
	}
    else
	{
		ans=__gcd(ans,tot-1);
		return 0;
	}
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=0;
		G[i].clear();
	}
	for(int i=2;i<=n;i++)
	{
		int x=read(),y=read();
		in[x]++;
		in[y]++;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int maxn=n-1;
	for(int i=2;i*i<=maxn;i++)
		if(maxn%i==0)
		{
			flag=1;
			ans=0;
			k=i;
			dfs(1,0);
			if(flag)
				a[ans]=1;
			while(maxn%i==0)
				maxn/=i;
		}
	if(maxn>1)
	{
		flag=1;
		ans=0;
		k=maxn;
		dfs(1,0);
		if(flag)
			a[ans]=1;
	}
	a[1]=1;
	for(int i=1;i<n;i++)
		(a[1]*=2)%=mod;
	for(int i=2;i<=n;i++)
		(a[1]+=mod-a[i])%=mod;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" "; 
	puts(""); 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}