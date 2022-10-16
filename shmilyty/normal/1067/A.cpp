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
int n,cnt,a[100001],f[2][201][3];
//0: 1: 2: 
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(a[1]==-1)
		for(int i=1;i<=200;i++)
			f[cnt][i][0]=1;
	else
		f[cnt][a[1]][0]=1;
	for(int i=2;i<=n;i++,cnt^=1)
	{
		int x=0;
		for(int l=1;l<=200;l++)
			for(int j=0;j<3;j++)
				f[cnt^1][l][j]=0;
		for(int l=1;l<=200;l++)
		{
			f[cnt^1][l][0]=((a[i]==-1||a[i]==l)?x:0);
			(x+=f[cnt][l][0]+f[cnt][l][1]+f[cnt][l][2])%=mod;	
		}
		for(int l=1;l<=200;l++)
			f[cnt^1][l][1]=((a[i]==-1||a[i]==l)?(f[cnt][l][0]+f[cnt][l][1]+f[cnt][l][2])%mod:0);
		x=0;
		for(int l=200;l;l--)
		{
			f[cnt^1][l][2]=((a[i]==-1||a[i]==l)?x:0);
			(x+=f[cnt][l][1]+f[cnt][l][2])%=mod;
		}
	}
	int res=0;
	for(int i=1;i<=200;i++)
		(res+=f[cnt][i][1]+f[cnt][i][2])%=mod;
	cout<<res;
	return 0;
}