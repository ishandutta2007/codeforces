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
int t,n,c,a[1000001],vis[1000001],f[1000001];
void solve()
{
	n=read();
	c=read();
	fill(vis+1,vis+1+c,0);
	fill(f+1,f+1+c,0);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		vis[a[i]]=1;
		f[a[i]]=1;
	}
//	sort(a+1,a+1+n);
	if(vis[1]!=1)
	{
		puts("No");
		return ;
	}
	for(int i=1;i<=c;i++)
		f[i]+=f[i-1];
	for(int l=2;l<=c;l++)
		if(vis[l])
			for(int j=2;j*l<=c;j++)
				if(!vis[j]&&f[min(c,j*l+l-1)]>f[j*l-1])
				{
					puts("No");
					return ;
				}
	puts("Yes");
 } 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}