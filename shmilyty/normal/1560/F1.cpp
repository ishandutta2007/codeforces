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
int t,k,n,ans[21],num[10];
char s[10];
bool dfs(int x,int val,bool flag)
{
	if(val>k)
		return 0;
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
			cout<<ans[i];
		cout<<endl;
		return 1;
	}
	for(int i=flag?s[x]-'0':0;i<=9;i++)
	{
		num[i]++;
		ans[x]=i;
		int nxt=val;
		if(num[i]==1)
			nxt++;
		if(dfs(x+1,nxt,flag&&(i==s[x]-'0')))
			return 1;
		num[i]--;
	}
	return 0;
}
void solve()
{
	scanf("%s",s+1);
	k=read();
	n=strlen(s+1);
	memset(num,0,sizeof(num));
	memset(ans,0,sizeof(ans));
	if(!dfs(1,0,1))
	{
		cout<<10;
		for(int i=2;i<k;i++)
			cout<<i;
		cout<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}