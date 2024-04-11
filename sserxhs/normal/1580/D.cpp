#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4002;
ll g[N][N];
int st[N],c[N][2],f[N],siz[N],a[N];
int n,m,i,tp,rt;
void dfs(int x)
{
	int lc=c[x][0],rc=c[x][1];
	siz[x]=1;
	if (!lc&&!rc)
	{
		g[x][0]=0;
		g[x][1]=(ll)a[x]*(m-1);
		return;
	}
	if (!lc&&rc) swap(lc,rc);
	if (!rc)
	{
		dfs(lc);
		siz[x]+=siz[lc];
		memcpy(g[x],g[lc],(siz[lc]+1)*sizeof g[0][0]);
		for (int i=0;i<=siz[lc];i++) g[x][i+1]=max(g[x][i+1],g[lc][i]+(ll)(m-1)*a[x]-2ll*i*a[x]);
		return;
	}
	dfs(lc);dfs(rc);siz[x]+=siz[lc]+siz[rc];
	for (int i=0;i<=siz[lc];i++) for (int j=0;j<=siz[rc];j++) g[x][i+j]=max(g[x][i+j],g[lc][i]+g[rc][j]-2ll*i*j*a[x]);
	for (int i=0;i<=siz[lc];i++) for (int j=0;j<=siz[rc];j++) g[x][i+j+1]=max(g[x][i+j+1],g[lc][i]+g[rc][j]+(ll)(m-1)*a[x]-2ll*(i*j+i+j)*a[x]);
}
int main()
{
	memset(g,-0x3f,sizeof g);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];st[tp+1]=0;
		while (tp&&a[st[tp]]>a[i]) --tp;
		c[st[tp]][1]=i;
		c[i][0]=st[tp+1];
		st[++tp]=i;
	}
	for (i=1;i<=n;i++) f[c[i][0]]=f[c[i][1]]=i;
	rt=min_element(f+1,f+n+1)-f;;
	dfs(rt);cout<<g[rt][m]<<endl;
}