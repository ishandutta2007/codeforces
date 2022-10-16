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
int t,n,a[200001],b[200001],num[200001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	fill(num+1,num+1+n,0);
	for(int i=1,l=1;i<=n;i++)
	{
		int x=b[i];
		if(l<=n&&a[l]==x)
		{
			l++;
			continue;
		}
		if(num[x]&&a[l-1]==x)
		{
			num[x]--;
			continue;
		}
		while(l<=n&&a[l]!=x)
		{
			num[a[l]]++;
			l++;
		}
		if(l==n+1)
		{
			// cout<<" "<<i<<endl;
			puts("No");
			return ;
		}
		l++;
		// cout<<i<<" "<<l<<endl;
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