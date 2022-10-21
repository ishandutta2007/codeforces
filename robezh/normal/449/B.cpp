#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int N = (int)1e5 + 500;
const ll INF = (ll)1e18;

struct edge{
    int to, cost;
    edge(int _to, int _cost){
        to = _to, cost = _cost;
    }
};

int n,m,k,a,b,y;
vector<edge> G[N];
vector<edge> B;
ll dis[N], Bdis[N];
int cntin[N];

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
            }
            else if(e.cost + dis[i] == dis[e.to]){
                if(dis[e.to] == Bdis[e.to]) cntin[e.to] ++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();


    fill(Bdis, Bdis+N, INF);
    int res = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> y;
        a--, b--;
        G[a].push_back(edge(b, y));
        G[b].push_back(edge(a, y));
    }
    for(int i = 0; i < k; i++){
        cin >> b >> y;
        b--;
        Bdis[b] = min(Bdis[b], (ll)y);
    }
    for(int i = 0; i < n; i++){
        if(Bdis[i] != INF){
            G[0].push_back(edge(i, (int)Bdis[i]));
        }
    }
    dijkstra();

    for(int i = 0; i < n; i++){
        if(dis[i] == Bdis[i] && cntin[i] == 0) res++;
    }
    cout << k - res << endl;

}