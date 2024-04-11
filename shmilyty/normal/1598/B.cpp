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
int t,n,a[1001][5];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int l=0;l<5;l++)
			a[i][l]=read();
	for(int i=0;i<5;i++)
		for(int l=i+1;l<5;l++)
		{
			int x=0,y=0,flag=1;
			for(int j=1;j<=n;j++)
			{
				if(!a[j][i]&&!a[j][l]) 
				{
					flag=0;
					break;
				}
				if(a[j][i])
					x++;
				if(a[j][l])
					y++;
			}
			if(flag&&x>=n/2&&y>=n/2)
			{
				puts("Yes");
				return ;
			}
		}
	puts("No");
}
signed main()
{	
	t=read();
	while(t--)
		solve();
	return 0;
}