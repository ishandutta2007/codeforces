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
int t,n,c1,c2,cnt,a[200001],b[200001],c[200001];
char s[200001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	scanf("%s",s+1);
	c1=c2=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='B')
			b[++c1]=a[i];
		else
			c[++c2]=a[i];
	sort(b+1,b+1+c1);
	sort(c+1,c+1+c2,greater<int>());
	cnt=1;
	for(int i=1;i<=c1;i++,cnt++)
		if(b[i]<cnt)
		{
			puts("NO");
			return ;
		}
	cnt=n;
	for(int i=1;i<=c2;i++,cnt--)
		if(c[i]>cnt)
		{
			puts("no");
			return ;
		}
	puts("YES");
 } 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}