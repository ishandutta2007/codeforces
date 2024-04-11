#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int N = (int)3e5 + 500;
const ll INF = (ll)1e18;

struct edge{
    int to, cost, i;
    edge(int _to, int _cost, int _i){
        to = _to, cost = _cost, i = _i;
    }
};

int n,m,k,a,b,y;
vector<edge> G[N];
ll dis[N];
int prv[N], pvi[N];
vector<int> res;

void dijkstra(){

    fill(dis, dis+N, INF);
    dis[0] = 0;
    priority_queue<P, vector<P>, greater<P> > pque;
    pque.push({0, 0});

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        ll dist = p.first;
        if(dist > dis[i]) continue;

        for(edge e : G[i]){
            if(e.cost + dis[i] < dis[e.to]){
                dis[e.to] = e.cost + dis[i];
                pque.push({dis[e.to], e.to});
                prv[e.to] = i;
                pvi[e.to] = e.i;
            }
        }
    }
}

int cur_edges;
void dfs(int i, int par){
    if(cur_edges == 0) return ;
    for(auto e : G[i]){
        if(e.to != par && cur_edges > 0){
            res.push_back(e.i);
            cur_edges--;
            dfs(e.to, i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> y;
        a--, b--;
        G[a].push_back(edge(b, y, i));
        G[b].push_back(edge(a, y, i));
    }
    dijkstra();

    for(int i = 0; i < n; i++) G[i].clear();
    for(int i = 1; i < n; i++){
//        G[i].push_back(edge(prv[i], 1, pvi[i]));
        G[prv[i]].push_back(edge(i, 1, pvi[i]));
    }

    cur_edges = k;
    dfs(0, -1);

    cout << res.size() << endl;
    for(int x : res) cout << x + 1 << " ";

}