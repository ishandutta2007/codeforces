#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=3e5+5;
int N, M, K;
struct PQNode{
    int v;
    ll dis;
    PQNode(int _v = 0, ll _dis = 0) : v(_v), dis(_dis) {}
    bool operator < (const PQNode& x) const {
        return dis > x.dis;
    }
};
struct Edge{
    int id, v;
    ll w;
    Edge(int _id = 0, int _v = 0, ll _w = 0) : id(_id), v(_v), w(_w) {}
};
vector <Edge> E[MAX_N];
void addEdge(int i, int u, int v, ll w) {
    E[u].push_back(Edge(i, v, w));
}
bool vis[MAX_N];
ll dist[MAX_N];
int fat[MAX_N],faEdge[MAX_N];
priority_queue<PQNode> PQ;
void Dijkstra(){
    memset(dist,0x3f,sizeof dist);
    memset(vis,false,sizeof vis);
    dist[1]=0;
    fat[1]=1;
    PQ.push(PQNode(1,0));
    while(!PQ.empty()){
        int u=PQ.top().v;
        PQ.pop();
        if(vis[u]){
        	continue;
		}
        vis[u]=1;
        for (int i = 0; i < (int)E[u].size(); i++) {
            int id = E[u][i].id;
            int v = E[u][i].v;
            ll w = E[u][i].w;
            if (vis[v])
                continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                fat[v] = u;
                faEdge[v] = id;
                PQ.push(PQNode(v, dist[v]));
            }
        }
    }
}
vector<int> son[MAX_N];
queue<int> BQ;
vector<int> ans;
void bfs(){
	BQ.push(1);
    while(!BQ.empty()&&K > 0) {
        int u=BQ.front();
		BQ.pop();
        for(int i=0;i<(int)son[u].size();i++){
            int v=son[u][i];
            if(K>0){
                ans.push_back(faEdge[v]);
                BQ.push(v);
                K--;
            }
            else{
            	break;
			}
        }
    }
}
int main(){
    cin>>N>>M>>K;
    for(int i=1;i<=M;i++){
    	int u, v; ll w;
    	scanf("%d%d%lld", &u, &v, &w);
    	addEdge(i, u, v, w);
    	addEdge(i,v,u,w);
    }
    Dijkstra();
    for(int i=2;i<=N;i++)
        son[fat[i]].push_back(i);
    bfs();
    cout << ans.size() << endl;
    bool firstprint=1;
    for(int i=0;i<(int)ans.size();i++){
        if(firstprint){
        	firstprint=0;
		}
        else{
        	putchar(' ');
		}
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}