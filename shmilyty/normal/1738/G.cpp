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
int t,n,k,f[1002][1002],ans[1001][1001],nxt[1001][1001];
char c[1001][1001];
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			f[i][l]=0;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			ans[i][l]=1;
	for(int i=n;i;i--)
		for(int l=n;l;l--)
		{
			if(c[i][l]=='1')
				nxt[i][l]=0;
			elif(i<n&&l<n)
				nxt[i][l]=(nxt[i+1][l+1]<0?-1:nxt[i+1][l+1]+1);
			else
				nxt[i][l]=-1;
		}
	// for(int i=1;i<=n;i++)
		// for(int l=1;l<=n;l++)
			// cout<<nxt[i][l]<<" \n"[l==n];
	for(int i=1;i<=n-k+1;i++)
		for(int l=1;l<=n-k+1;l++)
		{
			int x=max(f[i-1][l],f[i][l-1]);
			// cout<<x<<" \n"[l==k];
			if(i+x>n||l+x>n||nxt[i+x][l+x]<0)
			{
				puts("NO");
				return ;
			}
			x+=nxt[i+x][l+x];
			ans[i+x][l+x]=0;
			f[i][l]=x;
		}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=n;l++)
			cout<<ans[i][l];
		cout<<'\n';
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}