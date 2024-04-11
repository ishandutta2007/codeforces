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
int n,ans,x[200001],y[200001],s[200001],f[200001],g[200001];
const int mod=998244353;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
		s[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int pos=lower_bound(x+1,x+1+n,y[i])-x;
		int cnt=g[i]+x[i]-g[pos]-y[i];
		cnt=(cnt%mod+mod)%mod;
		g[i+1]=(g[i]+cnt)%mod;
		(ans+=s[i]*cnt)%=mod;
	}
	cout<<(ans+x[n]+1)%mod<<endl;
	return 0;
}