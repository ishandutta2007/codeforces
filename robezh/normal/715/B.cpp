#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const int N = (int)1e4 + 500;
const ll INF = (ll)1e18;


struct edge{
    int to;
    ll cost;
    bool era;
    int id;
    int rev;
    edge(){}
    edge(int _to, ll _cost, bool _era, int _id, int _rev){
        to = _to, cost = _cost, era = _era, id = _id, rev = _rev;
    }
};

int n,m,s,t;
ll L;
vector<edge> G[N];
ll dis[N];
ll res[N];
bool rule_out[N];
int e_from[N], e_to[N];
int prev_ver[N];
edge* prev_edge[N];
priority_queue<P, vector<P>, greater<P> > pque;
vector<int> path;
vector<int> pre;
vector<edge*> pre_e;

void print_out_graph() {
    cout << "graph: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "list of " << i << ": " << endl;
        for(edge e : G[i]) cout << "( " << e.to << ", " << e.cost << " ), ";
        cout << endl;
    }
}

void dijkstra(int s){
    fill(dis, dis+N, INF);
    dis[s] = 0;
    while(!pque.empty()) pque.pop();
    pque.push({0, s});

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int i = p.second;
        ll dist = p.first;
        if(dist > dis[i]) continue;

        for(edge &e : G[i]){
            if(e.cost == -1) continue;
            if(e.cost + dis[i] < dis[e.to]){
                dis[e.to] = e.cost + dis[i];
                prev_ver[e.to] = i;
                prev_edge[e.to] = &e;

                pque.push({dis[e.to], e.to});
            }
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> n >> m >> L >> s >> t;
    for(int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        G[a].push_back(edge(b, cost == 0 ? -1 : cost, cost == 0, i, G[b].size()));
        G[b].push_back(edge(a, cost == 0 ? -1 : cost, cost == 0, i, G[a].size()-1));
        e_from[i] = a;
        e_to[i] = b;
    }
    dijkstra(s);
    if(dis[t] < L) return cout << "NO" << endl, 0;
    for(int i = 0; i < n; i++) {
        for(auto &e : G[i]) {
            if(e.era) e.cost = 1;
        }
    }
    dijkstra(s);
    if(dis[t] > L) return cout << "NO" << endl, 0;

    fill(rule_out, rule_out + N, true);
    fill(res, res + N, -1);
    int cur = t;
    while(cur != s) {
        auto it = prev_edge[cur];
        rule_out[it->id] = false;
        cur = prev_ver[cur];
    }
    for(int i = 0; i < n; i++) {
        for(auto &e : G[i]) {
            if(e.era && rule_out[e.id]) {
                e.cost = -1;
            }
        }
    }
//    dijkstra(s);

    int cnt = 0;
    cur = t;
    while(cur != s) {
        auto it = prev_edge[cur];
        if(it->era) {
            path.push_back(cur);
            pre.push_back(prev_ver[cur]);
            pre_e.push_back(it);
        }
        cur = prev_ver[cur];
    }

    reverse(path.begin(), path.end());
    reverse(pre_e.begin(), pre_e.end());
    reverse(pre.begin(), pre.end());

//    print_out_graph();

    for(int i = 0; i < path.size(); i++) {
        int v = path[i];
        auto e = pre_e[i];
        int pv = pre[i];
        e->cost = -1;
        G[e->to][e->rev].cost = -1;

        ll tot = 0;
//        cout << "before " << i << "th iteration" << endl;
//        print_out_graph();

        dijkstra(s); tot += dis[pv];
        dijkstra(t); tot += dis[v];
//
//        cout << "after " << i << "th iteration" << endl;
//        print_out_graph();


        e->cost = G[e->to][e->rev].cost = max(L - tot, 1LL);
    }
    dijkstra(s);
    assert(dis[t] == L);
    dijkstra(t);
    assert(dis[s] == L);


    for(int i = 0; i < n; i++) {
        for(const auto &e : G[i]) {
            if(res[e.id] != -1) continue;
            if(e.cost == -1) res[e.id] = INF;
            else res[e.id] = e.cost;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < m; i++)
        cout << e_from[i] << " " << e_to[i]<< " " << res[i] << endl;

}