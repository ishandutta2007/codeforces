/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,l[N],r[N],v[N],ans;
vector <int> e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x)
{
	if (e[x].empty())
	{
		v[x]=r[x];ans++;
		return;
	}
	v[x]=0;
	for (int u:e[x])
	{
		dfs(u);
		v[x]+=v[u];
	}
	v[x]=min(v[x],r[x]);
	if (v[x]<l[x]) v[x]=r[x],ans++;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=2;i<=n;i++) e[read()].push_back(i);
		for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
		ans=0;
		dfs(1);
		printf("%lld\n",ans);
	}
}