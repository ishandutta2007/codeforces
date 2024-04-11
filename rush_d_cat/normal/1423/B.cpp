#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int M = 1e5 + 7;
int n, m, a[M], b[M], u[M], v[M];

const int Maxn = 1e5 + 10;  
const int INF = 0x6fffffff >> 2;  
  
struct edge{  
    int from , to , cap , flow;  
};  
  
struct Dinic{  
    int n,m,s,t;  
    vector<edge> edges;  
    vector<int> f[Maxn];  
    bool vis[Maxn];  
    int d[Maxn];  
    int cur[Maxn];   
    void init(int n) {
        this->n = n;
        edges.clear();
        for (int i = 0; i < Maxn; i ++) f[i].clear();
        memset(d, 0, sizeof(d));
        memset(cur, 0, sizeof(cur));
    }
    void AddEdge(int from,int to,int cap)  
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
    int DFS(int x,int a)//xa   
    {  
        if(x == t || a == 0) return a;  
        int flow = 0 , r;  
          
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
        return flow;  
    }  
} G;  

bool judge(int x){
    int s = 2 * n + 1, t = 2 * n + 2;

    G.init(2 * n + 10);

    for (int i = 1; i <= m; i++){
        if (b[x] >= a[i]){
            G.AddEdge(u[i], v[i] + n, 1);
        }   
    }
    for (int i = 1; i <= n; i++){
        G.AddEdge(s, i, 1);
        G.AddEdge(i + n, t, 1);
    }
    return G.MaxFlow(s, t) == n;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &u[i], &v[i], &a[i]); b[i] = a[i];
    }
    sort(b + 1, b + m + 1);
    int l = 1, r = m, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (judge(mid)) ans = b[mid], r = mid - 1;
        else l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}