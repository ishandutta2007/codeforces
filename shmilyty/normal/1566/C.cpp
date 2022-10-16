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
int t,n,ans,ok,ok1;
string a,b;
void solve()
{
	cin>>n>>a>>b;
	ans=0,ok=0,ok1=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			ans+=2;
			if(ok1)
				ans++;
			ok1=ok=0;
		}
		elif(a[i]=='1')
		{
			if(ok1)
			{
				ok1=0;
				ans+=2;
			}
			else
				ok=1;
		}
		else
		{
			if(ok)
			{
				ok=0;
				ans+=2;
				continue;
			}
			if(ok1)
				ans++;
			ok1=1;
		}
	}
	if(ok1)
		ans++;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}