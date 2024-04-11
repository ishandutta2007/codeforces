#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=500005;
int n,m,dis[N],ans[N],vis[N],q[N],head,tail;
vector <int> vt[N][2];

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		int u,v,tp;
		scanf("%d%d%d",&u,&v,&tp);
		vt[v][tp].pb(u);
	}
	rep(i,1,n) dis[i]=n+1,ans[i]=-1;
	q[head=tail=0]=n,vis[n]=1,dis[n]=ans[n]=0;
	while(head<=tail)
	{
		int x=q[head++];
		rep(i,0,1)
		{
			int sz=vt[x][i].size();
			rep(j,0,sz-1)
			{
				int v=vt[x][i][j];
				if(vis[v]) continue;
				if(ans[v]==-1) ans[v]=i^1;
				else if(ans[v]==i)
				{
					dis[v]=dis[x]+1;
					q[++tail]=v,vis[v]=1;
				}
			}
		}
	}
	if(dis[1]==n+1) puts("-1");
	else printf("%d\n",dis[1]);
	rep(i,1,n) if(ans[i]==-1) ans[i]=0;
	rep(i,1,n) putchar('0'+ans[i]);
	puts("");
	return 0;
}