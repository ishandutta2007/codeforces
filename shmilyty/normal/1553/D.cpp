#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int T;
string s,t;
void solve()
{
	cin>>s>>t;
	if(s.size()<t.size())
	{
		puts("NO");
		return ; 
	}
	int od=(s.size()-t.size())&1;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==t[cnt]&&((i&1)==od))
		{
			cnt++;
			od^=1;
			if(cnt==t.size())
			{
				puts("YES");
				return ;
			}
		}
	}
	puts("NO");
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}