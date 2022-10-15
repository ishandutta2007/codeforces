#include<bits/stdc++.h>
#define MAXN 14
#define MAXM 105
#define INF 1005000000
#define MOD 1000000007
#define F first
#define S second
#define x1 sakodsa
#define y1 dkoasad
#define x2 aksodas
#define y2 sadlapa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
struct node1 
{
    int x,y;
};
node1 towers[MAXN];
struct node2
{
    int x,y,t;
};
node2 quests[MAXM];
int tdist[(1<<MAXN)][MAXN];
int qdist[(1<<MAXN)][MAXM];
bool cmp(node2 p,node2 q)
{
    return p.t<q.t;
}
int calc_dist(int x1,int y1,int x2,int y2)
{
    return max(x1-x2,x2-x1)+max(y1-y2,y2-y1);
}
int f[(1<<MAXN)][MAXM];//f[mask][cnt]: minimum time to visit set mask of towers, and complete cnt quests
int g[(1<<MAXN)][MAXM];//g[mask][num]: maximum number of quests completed visiting mask of towers, and is at quest num
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d%d",&towers[i].x,&towers[i].y);
    for(int i=0;i<m;i++) scanf("%d%d%d",&quests[i].x,&quests[i].y,&quests[i].t);
    sort(quests,quests+m,cmp);
    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<n;i++)
        {
            tdist[mask][i]=INF;
            for(int j=0;j<n;j++) if(mask&(1<<j)) tdist[mask][i]=min(tdist[mask][i],calc_dist(towers[j].x,towers[j].y,towers[i].x,towers[i].y));
        }
    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<m;i++)
        {
            qdist[mask][i]=INF;
            for(int j=0;j<n;j++) if(mask&(1<<j)) qdist[mask][i]=min(qdist[mask][i],calc_dist(towers[j].x,towers[j].y,quests[i].x,quests[i].y));
        }
    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<m;i++)
            g[mask][i]=(mask==0?1:-INF);
    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<=m;i++)
            f[mask][i]=((__builtin_popcount(mask)<=1&&i==0)?0:INF);  
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<=m;i++)
        {
            if(f[mask][i]==INF) continue;
            for(int j=0;j<n;j++) //visiting a new tower
            {
                if(mask&(1<<j)) continue;
                f[mask^(1<<j)][i]=min(f[mask^(1<<j)][i],f[mask][i]+tdist[mask][j]);
            }
            for(int j=0;j<m;j++)//completing a new quest
            {
                if(quests[j].t<f[mask][i]+qdist[mask][j]) continue;
                f[mask][i+1]=min(f[mask][i+1],quests[j].t);
                g[mask][j]=max(g[mask][j],i+1);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(g[mask][i]==-INF) continue;
            for(int j=0;j<n;j++) //visiting a new tower
            {
                if(mask&(1<<j)) continue;
                int d=calc_dist(quests[i].x,quests[i].y,towers[j].x,towers[j].y);
                f[mask^(1<<j)][g[mask][i]]=min(f[mask^(1<<j)][g[mask][i]],quests[i].t+min(tdist[mask][j],d));
            }
            for(int j=i+1;j<m;j++)//completing a new quest
            {
                int d=calc_dist(quests[i].x,quests[i].y,quests[j].x,quests[j].y);
                if(quests[j].t<quests[i].t+min(qdist[mask][j],d)) continue;
                g[mask][j]=max(g[mask][j],g[mask][i]+1);
                f[mask][g[mask][i]+1]=min(f[mask][g[mask][i]+1],quests[j].t); 
            } 
        }
    }
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++)
        for(int i=0;i<m;i++)
            ans=max(ans,g[mask][i]);
    printf("%d\n",ans);
    return 0;
}