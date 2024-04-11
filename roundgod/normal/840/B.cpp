#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 300005
#define INF 1000000
using namespace std;
struct edge{int to,num;};
typedef pair<int,int> P;
int n,m;
vector<edge> G[MAXN];
int d[MAXN],deg[MAXN],p[MAXN],r[MAXN],save[MAXN];
bool used[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d %d",&n,&m);
    init(n);
    memset(used,false,sizeof(used));
    int s=0,f=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        if(d[i]==1) s++;
        if(d[i]==-1) f=1;
    }
    if(s%2==1&&!f)
    {
        printf("-1\n");
        return 0;
    }
    f=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(s%2==1&&!f)
        {
            if(d[x]==-1) {d[x]=1; f=1;}
            else if(d[y]==-1) {d[y]=1; f=1;}
        }
        if(d[x]==-1) d[x]=0;
        if(d[y]==-1) d[y]=0;
        if(!same(x-1,y-1))
        {
            G[x].push_back((edge){y,i});
            G[y].push_back((edge){x,i});
            unite(x-1,y-1);
            deg[x]++;
            deg[y]++;
        }
    }
    queue<int> P;
    for(int i=1;i<=m;i++)
        if(deg[i]==1) P.push(i);
    int k=0;
    while(!P.empty())
    {
        int x=P.front();
        P.pop();
        if(deg[x]==1)
        {
        used[x]=true;
        for(int i=0;i<G[x].size();i++)
            if(!used[G[x][i].to])
            {
                deg[G[x][i].to]--;
                if(d[x]==1)
                {
                    d[G[x][i].to]=1-d[G[x][i].to];
                    save[k]=G[x][i].num;
                    k++;
                }
                if(deg[G[x][i].to]==1) P.push(G[x][i].to);
            }
        }
    }
    sort(save,save+k);
    printf("%d\n",k);
    for(int i=0;i<k;i++)
        printf("%d ",save[i]);
    return 0;
}