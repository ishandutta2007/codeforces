/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int n,q,a[N],p[N],v[N],pos[N],t[N],cnt;
int vi[N],w,de[N],fa[N][21];
vector <int> f[N],e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	n=100000;
	for (int i=2;i<=n;i++)
	{
		if (!v[i]) v[i]=p[++w]=i;
		for (int j=1;j<=w;j++)
		{
			if (p[j]>n/i||p[j]>v[i]) break;
			v[p[j]*i]=p[j];
		}
	}
}
void add(int x,int v)
{
	for (int i=0;i<len(f[x]);i++)
	{
		int u=f[x][i];
		if (t[u]>1) cnt--;
		t[u]+=v;
		if (t[u]>1) cnt++;
	}
}
void dfs(int x,int father)
{
	vi[x]=1;fa[x][0]=father;
	for (int i=0;i<len(e[x]);i++)
	{
		int u=e[x][i];if (u==fa[x][0]) continue;
		de[u]=de[x]+1;
		dfs(u,x);
	}
}
signed main()
{
	prework();
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		while (x!=1)
		{
			int now=v[x];
			while (x%now==0) x/=now;
			f[i].push_back(now);
		}
	}
	for (int i=n,j=n;i>=1;i--)
	{
		add(i,1);
		while (j>=i&&cnt) add(j--,-1);
		pos[i]=j;
	}
	// for (int i=1;i<=n;i++) printf("%d ",pos[i]);
	// printf("\n");
	for (int i=1;i<=n;i++) e[pos[i]+1].push_back(i);
	dfs(n+1,n+1);
	for (int j=1;j<=20;j++) for (int i=1;i<=n+1;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	while (q--)
	{
		int l=read(),r=read();
		int x=l;
		for (int i=20;i>=0;i--) if (fa[x][i]<=r) x=fa[x][i];
		printf("%d\n",de[l]-de[x]+1);
	}
}