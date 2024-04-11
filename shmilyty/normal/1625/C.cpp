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
const int INF=0x3f3f3f3f;
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
int n,L,k,cnt=1,d[501],v[501],f[2][501][501];
signed main()
{
	n=read();
	L=read();
	k=read();
	for(int i=1;i<=n;i++)
		d[i]=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	memset(f,INF,sizeof(f));
	f[0][0][1]=0;
	for(int i=2;i<=n;i++,cnt^=1)
	{
		for(int l=0;l<=k;l++)
			for(int j=1;j<=i;j++)
				f[cnt][l][j]=INF;
		for(int l=0;l<=k;l++)
			for(int j=1;j<i;j++)
			{
				f[cnt][l][i]=min(f[cnt][l][i],f[cnt^1][l][j]+(d[i]-d[j])*v[j]);
				if(l)
					f[cnt][l][j]=min(f[cnt][l][j],f[cnt^1][l-1][j]);
			}
	}
	int ans=INF;
	for(int i=0;i<=k;i++)
		for(int l=1;l<=n;l++)
			ans=min(ans,f[cnt^1][i][l]+(L-d[l])*v[l]);
	cout<<ans;
	return 0;
}