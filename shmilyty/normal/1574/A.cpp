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
int t,n,sum;
bool dfs(int x,int tot,int cnt,string s)
{
	if(x==2*n)
	{
		sum++;
		cout<<s<<endl;
		if(sum==n)
			return 1;
		return 0;
	}
	if(tot!=n)
	{
		int res=dfs(x+1,tot+1,cnt+1,s+'(');
		if(res)
			return 1;
	}
	if(cnt)
	{
		int res=dfs(x+1,tot,cnt-1,s+')');
		if(res)
			return 1;
	}
	return 0;
}
signed main()
{
	t=read();
	while(t--)
	{
		sum=0;
		n=read();
		dfs(0,0,0,"");
	}
	return 0;
}