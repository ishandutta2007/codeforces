#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define NICO 602
#define N 1000
#define INF 100000000
int n, m[NICO], p[NICO], x, sum = 0;
vector<int> G[NICO];

const int MAXN=600;//
const int MAXM=10010;//

struct Node
{
    int from,to,next;
    int cap;
}edge[MAXM];

int tol;
int head[MAXN];
int dep[MAXN];
int gap[MAXN];//gap[x]=y :dep[i]==xy

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v, int w)
{
    edge[tol].from=u;
    edge[tol].to=v;
    edge[tol].cap=w;
    edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].from=v;
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[MAXN];
    int front,rear;
    front=rear=0;
    dep[end]=0;
    que[rear++]=end;
    while(front!=rear)
    {
        int u=que[front++];
        if(front==MAXN)front=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1)continue;
            que[rear++]=v;
            if(rear==MAXN)rear=0;
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
int SAP(int start,int end)
{
    int res=0;
    BFS(start,end);

    int cur[MAXN];
    int S[MAXN];
    int top=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    while(dep[start]<n)
    {
        if(u==end)
        {
            int temp=INF;
            int inser;
            for(i=0;i<top;i++)
               if(temp>edge[S[i]].cap)
               {
                   temp=edge[S[i]].cap;
                   inser=i;
               }
            for(i=0;i<top;i++)
            {
                edge[S[i]].cap-=temp;
                edge[S[i]^1].cap+=temp;
            }
            res+=temp;
            top=inser;
            u=edge[S[top]].from;
        }
        if(u!=end&&gap[dep[u]-1]==0)//
          break;
        for(i=cur[u];i!=-1;i=edge[i].next)
           if(edge[i].cap!=0&&dep[u]==dep[edge[i].to]+1)
             break;
        if(i!=-1)
        {
            cur[u]=i;
            S[top++]=i;
            u=edge[i].to;
        }
        else
        {
            int min=n;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(edge[i].cap==0)continue;
                if(min>dep[edge[i].to])
                {
                    min=dep[edge[i].to];
                    cur[u]=i;
                }
            }
            --gap[dep[u]];
            dep[u]=min+1;
            ++gap[dep[u]];
            if(u!=start)u=edge[S[--top]].from;
        }
    }
    return res;
}



int match[NICO];
bool us[NICO];

bool dfs(int x) {
    for (int i = 0; i < G[x].size(); i ++) {
        if (us[G[x][i]]) continue;
        us[G[x][i]] = 1;
        if ( match[ G[x][i] ] == - 1 || dfs( match[G[x][i]] ) ) {
            match[G[x][i]] = x;
            return 1;
        }
    }
    return 0;
}

int hungary() {
    int tot = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; i ++) {
        memset(us, 0, sizeof(us));
        if (dfs(i)) tot ++;
    }
    return tot;
}


int main() 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &m[i]);
        for (int j = 1; j <= m[i]; j ++) {
            scanf("%d", &x); G[i].push_back(x);
        }
    }

    for (int i = 1; i <= n; i ++) {
        scanf("%d", &p[i]); p[i] *= -1;
        if (p[i] > 0) sum += p[i];
    }

    hungary();
    for (int i = 1; i <= n; i ++) {
        //printf("%d %d\n", i, match[i]);
    }

    memset(head, -1, sizeof(head));

    int S = n + 1, E = n + 2;

    for (int i = 1; i <= n; i ++) 
    {
        
        if (p[i] >= 0) {
            addedge(S, i, p[i]);
        } else {
            addedge(i, E, -p[i]);
        }

        for (int j = 0; j < G[i].size(); j ++) {
            int to = match[G[i][j]];
            addedge(i, to, INF);
        }
    }      

    n += 2;

    int ans = SAP(S, E);
    //printf("%d\n", ans);
    cout << -(sum - ans) << endl;
}