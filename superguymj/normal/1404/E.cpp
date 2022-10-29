#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<queue>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=205,M=N*N*10;
const int INF=0x3f3f3f3f;
int n,m,hshtag;
char S[N][N];
int tot,last[M],ans,cnt=1,cur[M],dis[M];
int C[N][N],R[N][N],s,t;
struct edge{int to,c,next;} e[M*2];
queue <int> q;

void addedge(int u,int v,int c)
{
    e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].c=0;e[cnt].next=last[v];last[v]=cnt;
}

int dfs(int x,int rt)
{
    if (x==t || !rt) return rt;
    int ret=0;
    for (int &i=cur[x]; i; i=e[i].next)
        if (e[i].c && dis[e[i].to]==dis[x]+1)
        {
            int f=dfs(e[i].to,min(e[i].c,rt-ret));
            e[i].c-=f;
            e[i^1].c+=f;
            ret+=f;
            if (rt==ret) break;
        }
    return ret;
}

bool bfs()
{
    rep(i,1,tot) dis[i]=0;
    dis[s]=1;
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=last[u];i;i=e[i].next)
            if (e[i].c && !dis[e[i].to])
            {
                dis[e[i].to]=dis[u]+1;
                if (e[i].to==t) return 1;
                q.push(e[i].to);
            }
    }
    return 0;
}

void dinic()
{
    while (bfs())
    {
        rep(i,1,tot) cur[i]=last[i];
        ans+=dfs(s,INF);
    }
}

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",S[i]+1);
	rep(i,1,n) rep(j,1,m) if(S[i][j]=='#') ++hshtag;
	rep(i,1,n-1) rep(j,1,m) if(S[i][j]=='#' && S[i+1][j]=='#') C[i][j]=++tot;
	int lim=tot;
	rep(i,1,n) rep(j,1,m-1) if(S[i][j]=='#' && S[i][j+1]=='#') R[i][j]=++tot;
	s=tot+1,t=s+1,tot=t;
	rep(i,1,lim) addedge(s,i,1);
	rep(i,lim+1,tot-2) addedge(i,t,1);
	rep(i,1,n) rep(j,1,m) if(C[i][j])
	{
		if(R[i][j-1]) addedge(C[i][j],R[i][j-1],INF);
		if(R[i+1][j-1]) addedge(C[i][j],R[i+1][j-1],INF);
		if(R[i][j]) addedge(C[i][j],R[i][j],INF);
		if(R[i+1][j]) addedge(C[i][j],R[i+1][j],INF);
	}
	dinic();
	printf("%d\n",hshtag-(tot-2)+ans);
	return 0;
}