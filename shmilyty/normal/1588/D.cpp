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
int t,n,nxt[10][150][52];
map<vector<int>,pair<int,string>> vis;
int toi(char c)
{
	if(c<'a')
		return c-'A';
	return c-'a'+26;
}
char toc(int x)
{
	if(x<26)
		return (char)x+'A';
	return (char)x-26+'a';
}
pair<int,string> dfs(vector<int> x)
{
	if(vis.count(x))
		return vis[x];
	pair<int,string> ans={0,""};
	for(int i=0;i<52;i++)
	{
		bool flag=1;
		vector<int> u;
		for(int l=0;l<n;l++)
		{
			if(nxt[l][x[l]][i]==-1)
			{
				flag=0;
				break;
			}
			u.push_back(nxt[l][x[l]][i]);
		}
		if(flag)
		{
			auto tmp=dfs(u);
			ans=max(ans,{tmp.first+1,toc(i)+tmp.second});
		}
	}
	return vis[x]=ans;
}
void solve()
{
	vis.clear();
	n=read();
	memset(nxt,-1,sizeof(nxt));
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		s=" "+s;
		for(int l=0;l<s.size();l++)
			for(int j=s.size()-1;j>l;j--)
				nxt[i][l][toi(s[j])]=j;
	}
	vector<int> cnt(n,0);
	cout<<dfs(cnt).first<<endl<<dfs(cnt).second<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}