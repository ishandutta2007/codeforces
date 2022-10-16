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
const int mod=1e9+7;
int n,q,top,stk[100001],id[100001],a[100001],ans[100001],f[100002],fa[100001],p[100001],R[100001];
std::vector<array<int,2>> v[100001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
	n=read();
	q=read();
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=(p[i-1]<<1)%mod;
		fa[i]=i;
		a[i]=read();
	}
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		v[y].push_back({x,i});
	}
	for(int i=n;i;i--)
		f[i]=(f[i+1]*2+a[i]+mod)%mod;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		R[i]=i;
		int x=i;
		id[i]=++top;
		stk[top]=(stk[top-1]+mod+a[i])%mod;
		while(x>1&&a[x]>0)
		{
			int y=find(x-1);
			fa[x]=y;
			R[y]=i;
			if(a[x]>=mod||a[x]>mod>>(x-y-1))
				a[y]=mod;
			else
				a[y]+=a[x]<<(x-y);
			top--;
			stk[top]=(stk[top-1]+f[y]+mod-f[i+1]*p[i-y+1]%mod)%mod;
			x=find(x);
		}
		for(auto l:v[i])
		{
			x=find(l[0]);
			ans[l[1]]=((stk[top]+mod-stk[id[x]])*2%mod+f[l[0]]+mod-f[R[x]+1]*p[R[x]+1-l[0]]%mod)%mod;
		}
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
	return 0;
}