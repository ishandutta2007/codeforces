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
int t,n,ans;
string s;
int sol(int a,int b)
{
	int ok=0,res=0;
	for(int i=n-1;i>=0;i--)
		if(ok)
		{
			if(s[i]-'0'==b)
				return res;
			res++;
		}
		else
		{
			if(s[i]-'0'==a)
				ok++;
			else
				res++;
		}
	return INF;
}
void solve()
{
	cin>>s;
	n=s.size();
	ans=INF;
	ans=min(ans,sol(0,0));
	ans=min(ans,sol(0,5));
	ans=min(ans,sol(5,2));
	ans=min(ans,sol(5,7));
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}