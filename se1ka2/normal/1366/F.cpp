#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 1000000000000000000;
const ll MOD = 1000000007;
const ll HALF = 500000004;

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
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

ll c[4004][2004];

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;
    WeightedGraph<ll> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g.add_edge(u, v, w);
        g.add_edge(v, u, w);
    }
    int d[2004];
    fill(d, d + n, -1);
    queue<ll> que;
    d[0] = 0;
    que.push(0);
    while(que.size()){
        int u = que.front();
        que.pop();
        for(Edge<ll> e : g.g[u]){
            int v = e.to;
            if(d[v] == -1){
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) c[i][j] = -INF;
    }
    c[0][0] = 0;
    for(int i = 1; i <= n * 2; i++){
        for(int u = 0; u < n; u++){
            for(Edge<ll> e : g.g[u]){
                int v = e.to;
                c[i][v] = max(c[i][v], c[i - 1][u] + e.cost);
            }
        }
    }
    P p[2005];
    for(int u = 0; u < n; u++) p[u] = P(c[n * 2][u], u);
    sort(p, p + n, greater<P>());
    ll l[2005]{0};
    ll lar = 0;
    vector<P> st;
    for(int i = 0; i < n; i++){
        int u = p[i].second;
        for(Edge<ll> e : g.g[u]){
            l[u] = max(l[u], e.cost);
        }
        if(l[u] > lar){
            lar = l[u];
            while(st.size()){
                P r = st.back();
                int v = r.second;
                if(r.first * l[v] + c[n * 2][v] > r.first * l[u] + c[n * 2][u]) break;
                st.pop_back();
            }
            if(st.size()){
                P r = st.back();
                int v = r.second;
                st.push_back(P((c[n * 2][v] - c[n * 2][u] + (l[u] - l[v] - 1)) / (l[u] - l[v]), u));
            }
            else st.push_back(P(1, u));
        }
    }
    st.push_back(P(INF, -1));
    ll ans = 0;
    for(int i = 1; i <= min(n * 2, q); i++){
        ll s = 0;
        for(int j = 0; j < n; j++) s = max(s, c[i][j]);
        ans = (ans + s) % MOD;
    }
    if(q <= n * 2){
        cout << ans << endl;
        return 0;
    }
    for(int i = 0; i < (int)st.size() - 1; i++){
        int u = st[i].second;
        int right = min(st[i + 1].first - 1, q - n * 2);
        int left = min(st[i].first, q - n * 2 + 1);
        ans = (ans + (c[n * 2][u] % MOD + l[u] * left + c[n * 2][u] % MOD + l[u] * right) % MOD
               * (right - left + 1) % MOD * HALF % MOD) % MOD;
    }
    cout << ans << endl;
}