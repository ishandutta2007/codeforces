#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

struct UnionFind
{
    std::vector<int> par, sz;
    
    UnionFind(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    void unite(int i, int j){
        i = find(i), j = find(j);
        if(i == j) return;
        if(sz[i] < sz[j]) std::swap(i, j);
        par[j] = i;
        sz[i] += sz[j];
    }
    
    int size(int i){
        return sz[find(i)];
    }
};

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
    std::vector<std::vector<Edge<T>>> g;
    
    WeightedGraph(){}
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

ll w[200005];
ll a[200005], b[200005];
P p[200005];
P d[200005];

int main()
{
    ll n, m;
    cin >> n >> m;
    WeightedGraph<int> g(n);
    ll x = 0;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> w[i];
        a[i]--; b[i]--;
        g.add_edge(a[i], b[i], i);
        g.add_edge(b[i], a[i], i);
        p[i] = P(w[i], i);
        x ^= w[i];
    }
    sort(p, p + m);
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < n; i++) d[i] = P(1 << 30, -1);
    d[0] = P(0, -1);
    que.push(P(0, 0));
    set<int> st;
    for(int i = 1; i < n; i++) st.insert(i);
    int c = 0;
    while(que.size()){
        P p = que.top();
        que.pop();
        int u = p.second;
        if(d[u].first < p.first) continue;
        st.erase(u);
        set<int> s;
        for(Edge<int> e : g.g[u]){
            int v = e.to, i = e.cost;
            if(st.find(v) != st.end()){
                s.insert(v);
                if(d[v].first > w[i]){
                    d[v] = P(w[i], i);
                    que.push(P(w[i], v));
                }
            }
        }
        for(auto itr = st.begin(); itr != st.end(); itr++){
            int v = *itr;
            if(s.find(v) == s.end()){
                d[v] = P(0, -1);
                que.push(P(0, v));
                c++;
            }
        }
        swap(st, s);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += d[i].first;
    if(c < n * (n - 1) / 2 - m){
        cout << ans << endl;
        return 0;
    }
    UnionFind uf(n);
    for(int i = 0; i < n; i++){
        int j = d[i].second;
        if(j != -1) uf.unite(a[j], b[j]);
    }
    for(int i = 0; i < m; i++){
        int j = p[i].second;
        if(!uf.same(a[j], b[j])){
            cout << ans + min(x, w[j]) << endl;
            return 0;
        }
    }
    cout << ans + x << endl;
}