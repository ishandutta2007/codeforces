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
int t,n;
string s,s1,s2,ans;
void solve()
{
	n=read();
	cin>>s;
	s1=s2=s[0];
	ans=s1+s2;
	for(int i=1;i<n;i++)
	{
		if(s[i]>s[i-1])
			break;
		s1+=s[i];
		s2=s[i]+s2;
	}
	cout<<min(ans,s1+s2)<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}