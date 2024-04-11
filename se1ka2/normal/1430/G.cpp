#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000;

template <typename S, typename T>    // S : cap, T : cost
struct Edge
{
    int to;
    S cap;
    T cost;
    int rev;
};

template <typename S, typename T>
struct Flow
{
    int n;
    vector<vector<Edge<S, T>>> g;
    vector<S> demand;
    vector<T> potential;
    vector<S> f;
    T scost;
    
    Flow(int n, vector<S> &demand) : n(n), demand(demand){
        g.resize(n);
        potential.assign(n, 0);
        f.resize(n);
        scost = 0;
    }
    
    void add_edge(int from, int to, S cap, T cost){
        g[from].push_back((Edge<S, T>){to, cap, cost, (int)g[to].size()});
        g[to].push_back((Edge<S, T>){from, 0, -cost, (int)g[from].size() - 1});
    }
    
    void init_potential_and_flow(){
        for(int i = 0; i < n; i++){
            bool f = false;
            for(int u = 0; u < n; u++){
                for(Edge<S, T> &e : g[u]){
                    if(e.cap == 0) continue;
                    int v = e.to;
                    if(potential[v] > potential[u] + e.cost){
                        potential[v] = potential[u] + e.cost;
                        f = true;
                    }
                }
            }
            if(!f) break;
        }
        for(int u = 0; u < n; u++){
            for(Edge<S, T> &e : g[u]){
                if(e.cap == 0) continue;
                int v = e.to;
                if(potential[v] > potential[u] + e.cost){
                    g[v][e.rev].cap = e.cap;
                    e.cap = 0;
                    scost += e.cost;
                }
            }
        }
    }
    
    T min_cost_flow(){
        typedef pair<T, int> P;
        init_potential_and_flow();
        while(true){
            priority_queue<P> que;
            vector<T> d(n, -1);
            vector<P> p(n, P(-1, -1));
            for(int u = 0; u < n; u++){
                if(demand[u] < f[u]){
                    d[u] = 0;
                    que.push(P(0, u));
                }
            }
            if(que.empty()) break;
            while(!que.empty()){
                P q = que.top();
                que.pop();
                int u = q.second;
                if(d[u] < q.first) continue;
                for(int i = 0; i < (int)g[u].size(); i++){
                    Edge<S, T> &e = g[u][i];
                    if(e.cap == 0) continue;
                    int v = e.to;
                    T cost = e.cost + potential[u] - potential[v];
                    if(d[v] == -1 || d[v] > d[u] + cost){
                        d[v] = d[u] + cost;
                        p[v] = P(u, i);
                        que.push(P(d[v], v));
                    }
                }
            }
            int s = -1;
            for(int u = 0; u < n; u++){
                if(demand[u] > f[u] && d[u] != -1 && (s == -1 || d[u] < d[s])) s = u;
            }
            if(s == -1) return -1;
            for(int u = 0; u < n; u++){
                if(d[u] == -1 || d[u] > d[s]) potential[u] += d[s];
                else potential[u] += d[u];
            }
            S flow = demand[s] - f[s];
            int v = s;
            while(p[v].first != -1){
                int u = p[v].first;
                Edge<S, T> &e = g[u][p[v].second];
                flow = min(flow, e.cap);
                v = u;
            }
            flow = min(flow, f[v] - demand[v]);
            v = s;
            f[s] += flow;
            while(p[v].first != -1){
                int u = p[v].first;
                Edge<S, T> &e = g[u][p[v].second];
                e.cap -= flow;
                g[v][e.rev].cap += flow;
                scost += e.cost * flow;
                v = u;
            }
            f[v] -= flow;
        }
        return scost;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int x[400], y[400];
    ll w[400];
    vector<ll> b(n);
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> w[i];
        x[i]--; y[i]--;
        b[y[i]] += w[i];
        b[x[i]] -= w[i];
    }
    Flow<ll, ll> g(n, b);
    for(int i = 0; i < m; i++) g.add_edge(x[i], y[i], INF, -1);
    g.min_cost_flow();
    ll l = 0;
    for(int i = 0; i < n; i++) l = min(l, g.potential[i]);
    for(int i = 0; i < n; i++) cout << g.potential[i] - l << " ";
    cout << endl;
}