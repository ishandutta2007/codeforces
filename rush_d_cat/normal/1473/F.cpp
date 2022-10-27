#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3000 + 10;
const int Maxn = 3000 + 10;  
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

int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	G.init(n+3);
	int S=n+1,T=n+2;
	vector<int> las(101,0);
	int ans=0;
	for(int i=1;i<=n;i++) {
		if(b[i]>=0) {
			ans += b[i];
			G.AddEdge(S,i,b[i]);
		}else{
			G.AddEdge(i,T,- b[i]);
		}
		for(int x=1;x<=100;x++){
			if(a[i]%x==0 && las[x]>0) {
				G.AddEdge(i,las[x],INF);
			}
		}
		las[a[i]]=i;
	}	
	ans -= G.MaxFlow(S,T);
	cout<<ans<<endl;
}