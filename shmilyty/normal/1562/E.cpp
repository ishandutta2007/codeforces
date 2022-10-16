#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int t,n,m,ans,x[5001],y[5001],c[5001],sa[5001],a[5001],f[5001][5001],g[5001];
char s[5001];
void SA()
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(c,0,sizeof(c));
	memset(sa,0,sizeof(sa));
	for(int i=1;i<=n;i++)
	{
		x[i]=s[i];
		++c[x[i]];
	}
    for(int i=2;i<=m;i++)
		c[i]+=c[i-1];
    for(int i=n;i>=1;i--)
		sa[c[x[i]]--]=i;
    for(int k=1;k<=n;k<<=1)
    {	
        int num=0;
        for(int i=n-k+1;i<=n;++i) 
			y[++num]=i;
        for(int i=1;i<=n;i++)
            if(sa[i]>k)
				y[++num]=sa[i]-k;
        for(int i=1;i<=m;i++)
			c[i]=0;
        for(int i=1;i<=n;i++)
			c[x[i]]++;
        for(int i=2;i<=m;i++)
			c[i]+=c[i-1];
        for(int i=n;i>=1;i--)
		{
			sa[c[x[y[i]]]--]=y[i];
			y[i]=0;
		}
        swap(x,y);
        num=1;
		x[sa[1]]=1;
        for(int i=2;i<=n;i++)
        {	
            if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])
				x[sa[i]]=num;
            else 
				x[sa[i]]=++num;
        }
        if(num==n)
			break;
        m=num;
    }
}
void solve()
{
	n=read();
	m=122;
	scanf("%s",s+1);
	SA();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			f[i][l]=0;
	fill(g+1,g+1+n,0);
	fill(a+1,a+1+n,0);
	for(int i=1;i<=n;i++)
		a[sa[i]]=i;
	for(int i=n;i>=1;i--)
		for(int l=n;l>=1;l--)
			if(s[i]!=s[l])
				f[i][l]=0;
			else
				f[i][l]=f[i+1][l+1]+1;
	g[1]=n;
	ans=n;
	for(int i=2;i<=n;i++)
	{
		g[i]=n-i+1;
		for(int l=1;l<i;l++)
			if(a[i]>a[l])
				g[i]=max(g[i],g[l]+n-i+1-f[i][l]);
		ans=max(ans,g[i]);
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}