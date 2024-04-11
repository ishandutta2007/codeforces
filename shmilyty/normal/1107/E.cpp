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
int n,ans,a[101],f[101][101][101];
char s[101];
signed main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int len=1;len<=n;len++)
		for(int l=1;l+len<=n+1;l++)
			for(int i=l+len-1;i<=n;i++)
			{
				int r=l+len-1;
				f[l][r][i-r]=max(f[l][r][i-r],f[l][r-1][0]+a[i-r+1]);
				for(int j=l;j<r;j++)
					if(s[j]==s[r])
						f[l][r][i-r]=max(f[l][r][i-r],f[l][j][i-r+1]+f[j+1][r-1][0]);
			}
	cout<<f[1][n][0];
	return 0;
}