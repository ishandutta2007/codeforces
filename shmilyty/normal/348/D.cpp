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
int n,m,f[3001][3001];
char s[3001][3001];
int solve(int x,int y,int xx,int yy)
{
	memset(f,0,sizeof(f));
	if(s[x][y]=='#')
		return 0;
	f[x][y]=1;
	for(int i=x;i<=xx;i++)
		for(int l=y;l<=yy;l++)
			if(s[i][l]!='#')
				(f[i][l]+=f[i-1][l]+f[i][l-1])%=mod; 
	return f[xx][yy];
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	cout<<(solve(1,2,n-1,m)*solve(2,1,n,m-1)%mod-solve(1,2,n,m-1)*solve(2,1,n-1,m)%mod+mod)%mod;
	return 0;
}