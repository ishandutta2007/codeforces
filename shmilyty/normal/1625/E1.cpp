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
const int N=3e5+5;
int n,q,top,cnt,dfn[N],dep[N],lst[N],sz[N],id[N],fa[N],mat[N],stk[N];
bool vis[N];
char s[N];
vector<int> G[N];
struct BIT{
	int n;
	vector<int> v;
	void init(int nn)
	{
		n=nn;
		v.resize(nn+1);
	}
	void modify(int x,int val)
	{
		for(;x<=n;x+=lowbit(x))
			v[x]+=val; 
	}
	int query(int x)
	{
		int res=0;
		for(;x;x^=lowbit(x))
			res+=v[x];
		return res;
	}
}t[N],ans;
void dfs(int x)
{
	dfn[x]=++cnt;
	dep[x]=dep[fa[x]]+1;
	t[x].init((int)(G[x].size()));
	for(int i=0;i<sz[x];i++)
	{
		int l=G[x][i];
		id[l]=i+1;
		t[x].modify(i+1,1);
		dfs(l);
	}
	ans.modify(dfn[x],sz[x]*(sz[x]+1)/2);
}
void modify(int L,int R)
{
	int faa=fa[L];
	t[faa].modify(id[L],-1);
	ans.modify(dfn[faa],-sz[faa]*(sz[faa]+1)/2);
	sz[faa]--;
	ans.modify(dfn[faa],sz[faa]*(sz[faa]+1)/2);
}
int query(int L,int R)
{
	int x=lst[R],y=mat[R];
	int res=ans.query(dfn[x])-ans.query(dfn[L]-1);
	int faa=fa[L];
	int size=t[faa].query(id[y])-t[faa].query(id[L])+1;
	return res+size*(size+1)/2;
}
signed main()
{
	n=read();
	q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
			stk[++top]=i;
		elif(top)
			vis[stk[top--]]=vis[i]=1;
	}
	top=0;
	for(int i=1;i<=n;i++)
		if(vis[i])
		{
			if(s[i]=='(')
			{
				fa[i]=stk[top];
				sz[stk[top]]++;
				G[fa[i]].push_back(i);
				stk[++top]=i;
			}
			else
			{
				mat[stk[top]]=i;
				mat[i]=stk[top];
				top--;
			}
		}
	ans.init(n+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='('&&vis[i])
			lst[i]=i;
		else
			lst[i]=lst[i-1];
	dfs(0);
	while(q--)
	{
		int opt=read(),l=read(),r=read();
		if(opt&1)
			modify(l,r);
		else
			cout<<query(l,r)<<'\n';
	}
	return 0;
}