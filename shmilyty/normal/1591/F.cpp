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
const int mod=998244353;
int n,ans,top,a[500001],stk[500001],f[500001],sum[500001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		while(top&&a[stk[top]]>a[i])
		{
			(ans+=mod-sum[top]*a[stk[top]]%mod)%=mod;
			(tmp+=sum[top])%=mod;
			top--;
		}
		(tmp+=f[i-1])%=mod;
		stk[++top]=i;
		sum[top]=tmp;
		(ans+=sum[top]*a[i]%mod)%=mod;
		f[i]=(mod-ans)%mod;
	}
	if(n&1)
		cout<<(mod-f[n])%mod;
	else
		cout<<f[n];
	return 0;
}