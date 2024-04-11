#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int n,m,k,ans;
const int mod=1e9+7;
int sum(int x,int y)
{
	return ((((x+y)%mod)*((y-x+1)%mod))%mod)*500000004%mod;
}
signed main()
{
	n=read();
	m=read();
	k=sqrt((long long)n)+4;
	k=min(k,n); 
	for(int i=1;i<=k;i++)
	{
		(ans+=(n%i))%=mod;
		if(i==m)
		{
			cout<<(long long)ans<<endl;
			return 0;
		}
	}
	for(int i=k+1;i<=min(n,m);)
	{
		int now=n/i;
		int nxt=n/now;
		if(nxt>m)
			nxt=m;
		(ans+=((n%mod)*((nxt-i+1)%mod))%mod+mod-(((now%mod)*sum(i,nxt))%mod))%=mod;
		i=nxt+1;
	}
	if(n<m)
		(ans+=(((m-n)%mod)*(n%mod))%mod)%=mod;
	cout<<(long long)ans;
	return 0;
}