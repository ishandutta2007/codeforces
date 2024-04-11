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
int t,n,m,r,c,ans;
void solve()
{
	n=read();
	m=read();
	r=read();
	c=read();
	ans=-2;
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=1;l<=m;l++)
			if(s[l-1]=='B')
			{
				if(r==i&&c==l)
					ans=0;
				if(r==i||c==l)
					if(ans!=0) 
						ans=1;
				ok=0;
			}
	}
	if(ans!=-2)
	{
		cout<<ans<<endl;
		return ;
	}
	if(ok)
		puts("-1");
	else
		puts("2");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}