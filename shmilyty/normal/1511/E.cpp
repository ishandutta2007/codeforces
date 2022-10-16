#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int n,m,ans,c,w,p[300001],f[300001];
string s[300001];
const int mod=998244353;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int l=0;l<m;l++)
			if(s[i][l]=='o')
				w++;
	}
	p[0]=1;
	p[1]=2;
	f[2]=1;
	for(int i=2;i<=299999;i++)
	{
		p[i]=p[i-1]*2%mod;
		f[i+1]=(f[i]+f[i-1]*2+p[i-1])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=0;l<m;l++) 
			if(s[i][l]=='o')
				c++;
			else
			{
				(ans+=f[c]*p[w-c]%mod)%=mod;
				c=0;
			}
		(ans+=f[c]*p[w-c]%mod)%=mod;
		c=0;
	}
	for(int i=0;i<m;i++)
	{
		for(int l=1;l<=n;l++)
			if(s[l][i]=='o')
				c++;
			else
			{
				(ans+=f[c]*p[w-c]%mod)%=mod;
				c=0;
			}
		(ans+=f[c]*p[w-c]%mod)%=mod;
		c=0;
	}
	cout<<ans;
	return 0;
}