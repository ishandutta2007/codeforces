/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,lf[N],cnt,fa[N];
vector <int> e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x,int father)
{
	lf[x]=1;fa[x]=father;
	for (int u:e[x]) if (u!=fa[x])
	{
		dfs(u,x);
		if (lf[u]==1) lf[x]=0;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].push_back(v);e[v].push_back(u);
		}
		dfs(1,1);
		int bud=0;
		for (int i=2;i<=n;i++) if (lf[i]==0) bud++;
		bool bl=1;
		for (int i=2;i<=n;i++) if (lf[i]&&fa[i]==1) bl=0;
		int ans=0;
		for (int i=2;i<=n;i++) ans+=lf[i];
		ans-=bud;ans+=bl;
		printf("%d\n",ans);
	}
}