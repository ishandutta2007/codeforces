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
struct node{
	int to,nxt,v;
}e[800001];
array<int,3> a[200000];
int t,n,cnt,q,m,ok,h[200001],ans[200001];
void add(int x,int y,int z)
{
	e[++cnt]={y,h[x],z};
	h[x]=cnt;
}
void dfs(int x,int pre)//dep[1]=1!!!
{
	if(!ok)
		return ;
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=pre)
		{
			if(ans[e[i].to]==-1)
			{
				ans[e[i].to]=(ans[x]^e[i].v);
				dfs(e[i].to,x);
			}
			elif((ans[e[i].to]^ans[x])!=e[i].v)
			{
				ok=0;
				return ;
			}
		}
}
void solve()
{
	n=read();
	m=read(); 
	for(int i=1;i<=n;i++)
		h[i]=0;
	cnt=0;
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),v=read();
		a[i]={x,y,v};
		if(v>=0)
		{
			add(x,y,__builtin_parity(v));
			add(y,x,__builtin_parity(v));
		}
	}
	for(int i=1;i<=n;i++)
		ans[i]=-1;
	while(m--)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	ok=1;
	for(int i=1;i<=n;i++)
		if(ans[i]==-1)
		{
			ans[i]=0;
			dfs(i,0);
			if(!ok)
				break;
		}
	if(ok)
	{
		puts("Yes");
		for(int i=1;i<n;i++)
			if(~a[i][2])
				cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<'\n';
			else
				cout<<a[i][0]<<" "<<a[i][1]<<" "<<(ans[a[i][0]]^ans[a[i][1]])<<'\n';
		return ;
	}
	puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}