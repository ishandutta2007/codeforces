#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 30000;
const int inf = (1<<29);
struct EDGES{
    int u , v , cap , flow , cost;
    EDGES(int u , int v , int cap ,  int cost):u(u) , v(v) , cap(cap) , flow(0) , cost(cost){}
};
class MCMF{
    int n , dis[MAXN] , state[MAXN] , P[MAXN];
    vector < EDGES > edges;
    vector < int > adj[MAXN];
    deque < int > Q;
    public:
    void init(int N){
        n = N;
        for(int j = 0 ; j <= n ; j++)
            adj[j].clear();
    }
    void addedge(int a , int b , int c , int d){
        adj[a].push_back(edges.size());  edges.push_back(EDGES(a , b , c , d));
        adj[b].push_back(edges.size()); edges.push_back(EDGES(b , a , 0 , -d));
    }
    bool getpath(int src , int snk){
        Q.clear();
        for(int j=0;j<=n;j++){
            state[j] = 0;
            dis[j] = inf;
        }
        Q.push_back(src); dis[src] = 0;
        state[src] = 1;
        while(!Q.empty()){
            int x = Q.front(); Q.pop_front();
            state[x] = 2;
            for(auto j : adj[x]){
                int nxt = edges[j].v;
                if(edges[j].cap - edges[j].flow > 0 && dis[nxt] > dis[x] + edges[j].cost){
                    dis[nxt] = dis[x] + edges[j].cost;
                    P[nxt] = j;
                    if(state[nxt] == 0)
                        Q.push_back(nxt);
                    if(state[nxt] == 2)
                        Q.push_front(nxt);
                    state[nxt] = 1;
                }
            }
       }
       return dis[snk] != inf;
    }
    pair < int , int > augment(int x , int src , int flow){
        if(x == src) return make_pair(flow , 0);
        auto &E = edges[P[x]] , &rev=edges[(P[x]^1)];
        auto tosrc = augment(E.u , src , min(flow , E.cap - E.flow));
        tosrc.second += E.cost;
        E.flow += tosrc.first;
        rev.flow -= tosrc.first;
        return tosrc;
    }
    pair < int , int > MAXFLOW(int src , int snk){
        int flow = 0 , cost = 0;
        int best = 0;
        while(getpath(src , snk)){
            auto add = augment(snk , src , inf);
            flow += add.first;
            cost += add.second * add.first;
            best = min(best , cost);
        }
        return make_pair(flow , cost);
    }
}G;
int in1[1000000];
int out1[1000000];
int in7[10000];
int out7[10000];
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int source = 2*n, src = 2*n+1, sink = src+1;
    G.init(sink+1);
    int num = 3;
    for (int i=0;i<n;i++) {
        in1[i]=i*2;
        out1[i]=i*2+1;
        G.addedge(in1[i],out1[i],1,-1);
        G.addedge(out1[i],sink,2,0);
        G.addedge(src,in1[i],2,0);
        cin>>a[i];
        int x = num;
        for (int j=i-1;j>=0;j--) {
            if (a[i]%7==a[j]%7 && x){
                x--;
                G.addedge(out1[j],in1[i],2,0);
            }
        }
        x=num;
        for (int j=i-1;j>=0;j--) {
            if (a[j]-a[i]==1  && x) {
                x--;
                G.addedge(out1[j],in1[i],2,0);
            }
        }
        x=num;
        for (int j=i-1;j>=0;j--) {
            if (a[i]-a[j]==1 && x) {
                x--;
                G.addedge(out1[j],in1[i],2,0);
            }
        }
    }
    G.addedge(source,src,2,0);
    cout<<-G.MAXFLOW(source,sink).second<<endl;


}