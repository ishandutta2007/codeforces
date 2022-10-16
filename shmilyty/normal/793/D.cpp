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
const int INF=1e18;
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
int n,k,m,cnt,f[2][102][102];
vector<array<int,2>> G[102];
signed main()
{
	n=read();
	k=read()-1;
	if(!k)
	{
		puts("0");
		return 0;
	}
	m=read();
	while(m--)
	{
		int x=read(),y=read(),z=read();
		G[x].push_back({y,z});
	}
	for(int i=0;i<=n+1;i++)
		for(int l=0;l<=n+1;l++)
			f[0][i][l]=INF;
	for(int i=1;i<=n;i++)
		f[0][i][0]=f[0][i][n+1]=0;
	while(k--)
	{
		for(int i=0;i<=n+1;i++)
			for(int l=0;l<=n+1;l++)
				f[cnt^1][i][l]=INF;
		for(int i=0;i<=n+1;i++)
			for(int l=0;l<=n+1;l++)
				if(f[cnt][i][l]!=INF)
					for(auto j:G[i])
						if(min(i,l)<j[0]&&j[0]<max(i,l))
						{
							f[cnt^1][j[0]][i]=min(f[cnt^1][j[0]][i],f[cnt][i][l]+j[1]);
							f[cnt^1][j[0]][l]=min(f[cnt^1][j[0]][l],f[cnt][i][l]+j[1]);
						}
		cnt^=1;
	}
	int ans=INF;
	for(int i=0;i<=n+1;i++)
		for(int l=0;l<=n+1;l++)
			ans=min(ans,f[cnt][i][l]);
	if(ans>2000000)
		puts("-1");
	else
		cout<<ans;
	return 0;
}