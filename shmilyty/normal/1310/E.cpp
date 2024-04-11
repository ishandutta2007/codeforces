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
const int mod=998244353;
int n,k,ans,f[2030],a[100],b[2030],c[2030];
bool check(int len)
{
	for(int i=1;i<=len;i++)
		b[i]=a[i];
	for(int i=1;i<k;i++)
	{
		int sum=0,cnt=0;
		for(int l=1;l<=len;l++)
			sum+=l*b[l];
		if(sum>n)
			return 0;
		for(int l=len;l;l--)
			while(b[l]--)
				c[++cnt]=l;
		for(int l=1;l<=cnt;l++)
			b[l]=c[l];
		len=cnt;
	}
	return 1;
}
void dfs(int x,int rst,int lim)
{
	if(x>1)
		(ans+=check(x-1))%=mod;
	if(!rst)
		return ;
	for(int i=1;i<=min(rst,lim);i++)
	{
		a[x]=i;
		dfs(x+1,rst-i,i);
	}
}
signed main()
{
	n=read();
	k=read();
	if(k==1)
	{
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int l=i;l<=n;l++)
				(f[l]+=f[l-i])%=mod;
			(ans+=f[i])%=mod;
		}
		cout<<ans;
	}
	elif(k==2)
	{
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int l=i*(i+1)/2;l<=n;l++)
				(f[l]+=f[l-i*(i+1)/2])%=mod;
			(ans+=f[i])%=mod;
		}
		cout<<ans;
	}
	else
	{
		dfs(1,min(n,64ll),64);
		cout<<ans;
	}
	return 0;
}