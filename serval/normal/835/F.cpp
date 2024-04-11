#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=200005;
const int maxe=400005;
int n,i,j,u,v,w;
int h[maxn],to[maxe],nx[maxe],cnt;
long long wt[maxe];
bool vis[maxn],inq[maxn];
int par[maxn];
int st[maxn],stpos[maxn],sttop;
int cir[maxn],cirlen;
bool incir[maxn];
long long cirval[maxe],parval[maxn];
long long ans;
long long g[maxn];
int aq[maxe],aql,aqr;
int bq[maxe],bql,bqr;
long long minv,cirans[maxn];
void addedge(int u,int v,int w)
{
	cnt++;
	to[cnt]=v;
	wt[cnt]=w;
	nx[cnt]=h[u];
	h[u]=cnt;
}
void dfs(int u,int f)
{
	vis[u]=1;
	par[u]=f;
	inq[u]=1;
	st[++sttop]=u;
	stpos[u]=sttop;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f)
			if (!vis[to[i]])
			{
				parval[to[i]]=wt[i];
				dfs(to[i],u);
			}
			else
				if (cirlen==0)
				{
					int pos=to[i];
					while (!inq[pos])
					{
						cirlen++;
						cir[cirlen]=pos;
						incir[pos]=1;
						cirval[cirlen]=parval[pos];
						pos=par[pos];
					}
					for (int j=stpos[pos];j<sttop;j++)
					{
						cirlen++;
						cir[cirlen]=st[j];
						incir[st[j]]=1;
						cirval[cirlen]=parval[st[j+1]];
					}
					cirlen++;
					cir[cirlen]=u;
					incir[u]=1;
					cirval[cirlen]=wt[i];
				}
	inq[u]=0;
	sttop--;
}
void dp(int u,int f)
{
	long long sec=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=f&&!incir[to[i]])
		{
			dp(to[i],u);
			if (g[to[i]]+wt[i]>g[u])
			{
				sec=g[u];
				g[u]=g[to[i]]+wt[i];
			}
			else
				if (g[to[i]]+wt[i]>sec)
					sec=g[to[i]]+wt[i];
		}
	if (g[u]+sec>ans)
		ans=g[u]+sec;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dfs(1,0);
	for (i=1;i<=cirlen;i++)
		dp(cir[i],0);
	for (i=cirlen+1;i<=cirlen*2;i++)
	{
		cir[i]=cir[i-cirlen];
		cirval[i]=cirval[i-cirlen];
	}
	for (i=1;i<=cirlen*2;i++)
		cirval[i]+=cirval[i-1];
	aql=bql=1;
	aqr=bqr=0;
	for (i=1;i<=cirlen*2;i++)
	{
		while (aql<=aqr&&aq[aql]<=i-cirlen)
			aql++;
		while (bql<=bqr&&bq[bql]<=aq[aql])
			bql++;
		while (bql<=bqr&&
			g[cir[bq[bqr]]]+cirval[bq[bqr]-1]<=g[cir[i]]+cirval[i-1])
			bqr--;
		bq[++bqr]=i;
		if (i>cirlen)
			cirans[i-cirlen]=g[cir[aq[aql]]]-cirval[aq[aql]-1]
							+g[cir[bq[bql]]]+cirval[bq[bql]-1];
		while (aql<=aqr&&
			g[cir[aq[aqr]]]-cirval[aq[aqr]-1]<=g[cir[i]]-cirval[i-1])
			aqr--;
		aq[++aqr]=i;
	}
	aql=bql=1;
	aqr=bqr=0;
	for (i=cirlen*2;i;i--)
	{
		while (bql<=bqr&&bq[bql]>=i+cirlen)
			bql++;
		while (aql<=aqr&&aq[aql]>=bq[bql])
			aql++;
		while (aql<=aqr&&
			g[cir[aq[aqr]]]-cirval[aq[aqr]-1]<=g[cir[i]]-cirval[i-1])
			aqr--;
		aq[++aqr]=i;
		if (i<=cirlen)
			cirans[(i+cirlen-2)%cirlen+1]=
				max(cirans[(i+cirlen-2)%cirlen+1],
				g[cir[aq[aql]]]-cirval[aq[aql]-1]
				+g[cir[bq[bql]]]+cirval[bq[bql]-1]);
		while (bql<=bqr&&
			g[cir[bq[bqr]]]+cirval[bq[bqr]-1]<=g[cir[i]]+cirval[i-1])
			bqr--;
		bq[++bqr]=i;
	}
	minv=1e18;
	for (i=1;i<=cirlen;i++)
		if (cirans[i]<minv)
			minv=cirans[i];
	if (minv>ans)
		ans=minv;
	printf("%lld\n",ans);
	return 0;
}