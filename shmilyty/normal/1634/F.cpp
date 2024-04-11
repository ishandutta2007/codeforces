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
int n,q,mod,ok,a[300001],fib[300001]; 
signed main()
{
	n=read();
	q=read();
	mod=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		(a[i]+=mod-read())%=mod;
	for(int i=n;i;i--)
	{
		(a[i]+=mod-a[i-1])%=mod;
		if(i!=1)
			(a[i]+=mod-a[i-2])%=mod;
		if(a[i])
			ok++;
	}
	fib[1]=1;
	for(int i=2;i<=300000;i++)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	while(q--)
	{
		char c;
		scanf("%c",&c);
		int x=read(),y=read();
		int k=1;
		if(c=='B')
			k=mod-1;
		if(a[x])
			ok--;
		(a[x]+=k)%=mod;
		if(a[x])
			ok++;
		if(y!=n)
		{
			if(a[y+1])
				ok--;
			(a[y+1]+=mod-k*fib[y-x+2]%mod)%=mod;
			if(a[y+1])
				ok++;
		}
		if(y<n-1)
		{
			if(a[y+2])
				ok--;
			(a[y+2]+=mod-k*fib[y-x+1]%mod)%=mod;
			if(a[y+2])
				ok++; 
		}
		if(ok)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}//1