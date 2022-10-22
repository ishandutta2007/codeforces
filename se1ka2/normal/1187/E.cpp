#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedGraph
{
    int n;
    vector<vector<Edge<T>>> g;
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

template <typename T>
vector<T> Dijkstra(WeightedGraph<T> &g, int s){
    int n = g.n;
    vector<T> d(n);
    fill(d.begin(), d.end(), -1);
    queue<int> que;
    d[s] = 0;
    que.push(s);
    while(que.size()){
        int now = que.front();
        que.pop();
        for(Edge<T> e : g.g[now]){
            if(d[e.to] == -1){
                d[e.to] = d[now] + e.cost;
                que.push(e.to);
            }
        }
    }
    return d;
}

int n;
WeightedGraph<int> g(n);
vector<int> d;
ll memo[200005];
vector<int> t;

ll dfs(int i){
    if(memo[i]) return memo[i];
    ll res = 1;
    for(Edge<int> e : g.g[i]){
        if(d[e.to] > d[i]) res += dfs(e.to);
    }
    return memo[i] = res;
}

void EulerTour(int i){
    t.push_back(i);
    for(Edge<int> e : g.g[i]){
        if(d[e.to] > d[i]){
            EulerTour(e.to);
            t.push_back(i);
        }
    }
}

int main()
{
    cin >> n;
    g.n = n;
    g.g.resize(n);
    ll s = n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g.add_edge(u, v, 1);
        g.add_edge(v, u, 1);
    }
    d = Dijkstra(g, 0);
    ll now = 1;
    for(int i = 1; i < n; i++) now += d[i] + 1;
    ll ans = now;
    EulerTour(0);
    int l = t.size();
    for(int i = 1; i < l; i++){
        if(d[t[i]] > d[t[i - 1]]){
            now -= dfs(t[i]);
            now += s - dfs(t[i]);
            ans = max(ans, now);
        }
        else{
            now += dfs(t[i - 1]);
            now -= s - dfs(t[i - 1]);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}