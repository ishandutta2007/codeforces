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
unordered_map<int,int> pre,nxt,mat,vis;
int n,ans;
int dfs(int x)
{
	vis[x]=1;
	int minn=INF;
	for(int i=x;;i+=x)
	{
		if(!mat.count(i))
		{
			pre[i]=x;
			return min(i,minn);
		}
		if(!vis.count(mat[i]))
		{
			pre[i]=x;
			nxt[mat[i]]=i;
			minn=min(minn,dfs(mat[i]));
		}
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		pre.clear();
		nxt.clear();
		vis.clear();
		int cnt=dfs(x);
		ans+=cnt;
		while(cnt)
		{
			mat[cnt]=pre[cnt];
			cnt=nxt[pre[cnt]];
		}
	}
	cout<<ans;
	return 0;
}