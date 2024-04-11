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
int t,vis[26];
string s;
void solve()
{
	cin>>s;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<s.size();i++)
	{
		if(vis[s[i]-'a'])
		{
			puts("NO");
			return ;
		}
		vis[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(vis[i]==0)
		{
			if(i!=(int)s.size())
			{
				puts("NO");
				return ;
			}
			break;
		}
		if(vis[i]!=1)
		{
			puts("NO");
			return ;
		}
	}
	bool flag=1;
	for(int i=1;i<s.size();i++)
		if(s[i]<s[i-1])
		{
			if(!flag)
			{
				puts("NO");
				return ;
			}
		}
		else
			flag=0;
	puts("YES");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}