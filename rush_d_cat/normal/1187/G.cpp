#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 1e9+7;
const int N = 20005;
vector<int> g[N];
struct Edge
{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int ca,int f,int co):from(u),to(v),cap(ca),flow(f),cost(co){};
};
struct MCMF
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];//
    int d[N];//
    int p[N];//
    int a[N];//

    void init(int n)//
    {
        this->n=n;
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }

    void addedge(int from,int to,int cap,int cost)//
    {
        //printf("add %d %d %d %d\n", from,to,cap,cost);
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool SPFA(int s,int t,int &flow,int &cost)//flow,cost
    {
        for(int i=0;i<n;i++)
            d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]--;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)//
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])
                    {
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if(d[t]==INF) return false;//
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s)//
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }

    int MincotMaxflow(int s,int t)
    {
        int flow=0,cost=0;
        while(SPFA(s,t,flow,cost));
        //printf("flow = %d\n", flow);
        return cost;
    }
} G;
const int B = 120;
int n,m,k,c,d;
int a[52],has[52][52];
pair<int,int> e[N]; 
int id(int x,int t) {
    return x*B+t;
}
void build() {
    int S=id(n,B)+1,T=S+1;
   // printf("%d %d\n", S,T);
    G.init(T+1);
    for(int i=1;i<=k;i++){
        G.addedge(S,id(a[i],0),1,0);
    }
    for(int i=1;i<=n;i++){
        for(int t=0;t<B-1;t++){
            G.addedge(id(i,t),id(i,t+1),k,0);
            for(auto j: g[i]) {
                //if(t>=80) continue;
                for(int x=1;x<=k;x++) G.addedge(id(i,t),id(j,t+1),1,(2*x-1)*d);
            }
        }
    }
    for(int i=1;i<B-1;i++){
        //if(i>=80) continue;
        G.addedge(id(1,i),T,k,i*c);
    }
    cout << G.MincotMaxflow(S,T) << endl;
}
int main() {
    scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
    for(int i=1;i<=k;i++) {
        scanf("%d",&a[i]); 
    }
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    build();
}