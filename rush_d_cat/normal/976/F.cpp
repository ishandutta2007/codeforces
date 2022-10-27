#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
const int N = 5000 + 10;  
const int INF = 1e9 + 7;  
#define mp(x,y) make_pair(x,y)
  
struct Edge {  
    int from , to , cap , flow, id;  
};  
bool visit[N];
struct Dinic {   
    int n,m,s,t;  
    vector<Edge> edges;  
    vector<int> f[N];  
    bool vis[N];  
    int d[N];  
    int cur[N];   
    void init(int n) {
        this->n = n;
        edges.clear();
        for (int i = 0; i < N; i ++) f[i].clear();
        memset(d, 0, sizeof(d));
        memset(cur, 0, sizeof(cur));
        memset(visit, 0, sizeof(visit));
    }
    void AddEdge(int from,int to,int cap,int id)  
    {  
        edges.push_back((Edge){from,to,cap,0,id});  
        edges.push_back((Edge){to,from,0,0,id});  
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
                Edge &e = edges[f[x][i]];  
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
    int DFS(int x,int a)//xa   
    {  
        if(x == t || a == 0) return a;  
        int flow = 0 , r;  
          
        for(int& i = cur[x];i < f[x].size();i++)  
        {  
            Edge& e = edges[f[x][i]];  
            if(d[x] + 1 == d[e.to] && (r = DFS(e.to , min(a,e.cap - e.flow) ) ) > 0 )  
            {  
                e.flow += r;  
                edges[f[x][i] ^ 1].flow -= r;  
                //get Ans
                //printf("miao: %d\n", edges[f[x][i] ^ 1].id);
                //visit[edges[f[x][i] ^ 1].id] = 1;

                flow += r;//   
                a -= r;  
                if(a == 0) break;  
            }  
        }  
        return flow;  
    }  
    int MaxFlow(int s,int t)  
    {  
        this->s = s; this->t = t;  
        int flow = 0;  
        while(BFS())  
        {      
            memset(cur,0,sizeof(cur));  
            flow += DFS(s,INF);  
            //printf("%d\n", flow);
        }  
        for (int i=0;i<edges.size();i++) {
            if (edges[i].flow) visit[edges[i].id] = 1;
        }
        return flow;  
    }  
} G;

int n1,n2,m,deg[N];
vector< pair<int, int> > v[N];

void build_gragh(int k) {
    int S = n1+n2+1, T=n1+n2+2;
    G.init(T+2);
    for(int i=1;i<=n1;i++) {
        G.AddEdge(S,i,deg[i]-k,0);
    }
    for(int i=1;i<=n2;i++) {
        G.AddEdge(i+n1,T,deg[i+n1]-k,0);
    }
    for(int i=1;i<=n1;i++) {
        for (int j=0;j<v[i].size();j++) {
            G.AddEdge(i,v[i][j].first+n1,1,v[i][j].second);
        }
    }
    int ret = G.MaxFlow(S,T);

    printf("%d ", m-ret);
    for (int i=1;i<=m;i++) {
        if (visit[i] == 0) 
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    scanf("%d%d%d",&n1,&n2,&m);
    for(int i=1;i<=m;i++) {
        int x, y; 
        scanf("%d%d",&x,&y);
        v[x].push_back(mp(y, i));
        deg[x] ++, deg[n1+y]++;
    }
    printf("0\n");
    int mnDegree = *min_element(deg+1,deg+1+n1+n2);
    for (int i = 1; i <= mnDegree; i ++) {
        build_gragh(i);
    }
}