#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int Maxn = 3000 + 10;  
const LL INF = 1e16;  
  
struct edge{  
    int from , to; LL cap , flow;  
};  
  
struct Dinic{  
    int n,m,s,t;  
    vector<edge> edges;  
    vector<LL> f[Maxn];  
    bool vis[Maxn];  
    LL d[Maxn];  
    int cur[Maxn];   
    void init(int n) {
        this->n = n;
        edges.clear();
        for (int i = 0; i < Maxn; i ++) f[i].clear();
        memset(d, 0, sizeof(d));
        memset(cur, 0, sizeof(cur));
    }
    void AddEdge(int from,int to,LL cap)  
    {  
        edges.push_back((edge){from,to,cap,0});  
        edges.push_back((edge){to,from,0,0});  
        m = edges.size();  
        f[from].push_back(m-2);  
        f[to].push_back(m-1);  
    }  
    bool BFS()   
    {  
        memset(vis,0,sizeof(vis));  
        queue<int> q;  
        q.push(s);  
        d[s] = 0;  
        vis[s] = 1;  
        while(!q.empty())  
        {  
            int x = q.front(); q.pop();  
            for(int i=0;i<f[x].size();i++)  
            {  
                edge &e = edges[f[x][i]];  
                //cout<<"to="<<e.to<<"from="<<e.from<<' '<<e.flow<<' '<<e.cap<<' '<<vis[e.to]<<endl;  
                if(!vis[e.to] && e.flow < e.cap) //   
                {  
                    vis[e.to] = 1;  
                    d[e.to] = d[x] + 1;//  
                    q.push(e.to);   
                }  
            }  
        }  
        return vis[t];//   
    }  
    LL DFS(int x,LL a)//xa   
    {  
        if(x == t || a == 0) return a;  
        LL flow = 0 , r;  
          
        for(int& i = cur[x];i < f[x].size();i++)  
        {  
            edge& e = edges[f[x][i]];  
            if(d[x] + 1 == d[e.to] && (r = DFS(e.to , min(a,e.cap - e.flow) ) ) > 0 )  
            {  
                e.flow += r;  
                edges[f[x][i] ^ 1].flow -= r;  
                flow += r;//   
                a -= r;  
                if(a == 0) break;  
            }  
        }  
        return flow;  
    }  
    LL MaxFlow(int s,int t)  
    {  
        this->s = s; this->t = t;  
        LL flow = 0;  
        while(BFS())  
        {      
            memset(cur,0,sizeof(cur));  
            flow += DFS(s,INF);  
            //printf("%d\n", flow);
        }  
        return flow;  
    }  
} G;  

int n,m;
int a[Maxn];
int main(){
    scanf("%d%d",&n,&m);
    G.init(n+m+5);
    int S=n+m+1,T=n+m+2;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        G.AddEdge(S,i,a[i]);
    }
    LL sum=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G.AddEdge(u,i+n,INF);
        G.AddEdge(v,i+n,INF);
        G.AddEdge(i+n,T,w); sum+=w;
    }

    LL C = G.MaxFlow(S,T);
    LL ans = sum - C;
    cout << ans << endl;
}