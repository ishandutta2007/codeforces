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
    
    void init(int n_){
        n = n_;
        g.resize(n_);
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
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

template <typename T>
struct WeightedTree
{
    int n;
    int root;
    vector<vector<Edge<T>>> t;
    vector<int> par;
    vector<int> dpt;
    
    WeightedTree(){}
    
    WeightedTree(WeightedGraph<T> &g, int root) : n(g.n), root(root){
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(Edge e : g.g[pa]){
                int ch = e.to;
                if(dpt[ch] == -1){
                    t[pa].push_back(e);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    void init(WeightedGraph<T> &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(Edge e : g.g[pa]){
                int ch = e.to;
                if(dpt[ch] == -1){
                    t[pa].push_back(e);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }
};

typedef Edge<int> edge;

WeightedTree<int> t;
ll p00[200005];
ll p01[200005];
ll p10[200005];
ll p11[200005];
ll dp[200005];

ll path00(int i){
    if(p00[i] >= 0) return p00[i];
    ll res = 0;
    for(edge e : t.t[i]){
        int ch = e.to;
        if(e.cost == 0) res += path00(ch) + 1;
    }
    return p00[i] = res;
}

ll path11(int i){
    if(p11[i] >= 0) return p11[i];
    ll res = 0;
    for(edge e : t.t[i]){
        int ch = e.to;
        if(e.cost == 1) res += path11(ch) + 1;
    }
    return p11[i] = res;
}

ll path01(int i){
    if(p01[i] >= 0) return p01[i];
    ll res = 0;
    for(edge e : t.t[i]){
        int ch = e.to;
        if(e.cost == 1) res += path00(ch) + path01(ch);
    }
    return p01[i] = res;
}

ll path10(int i){
    if(p10[i] >= 0) return p10[i];
    ll res = 0;
    for(edge e : t.t[i]){
        int ch = e.to;
        if(e.cost == 0) res += path11(ch) + path10(ch);
    }
    return p10[i] = res;
}

ll dfs(int i){
    if(dp[i] >= 0) return dp[i];
    ll res = path00(i) * path00(i) + path00(i) * path10(i) + path00(i) * path11(i) +
        path01(i) * path11(i) + path11(i) * path11(i) + path00(i) * 2 + path01(i) + path10(i) + path11(i) * 2;
    for(edge e : t.t[i]){
        int ch = e.to;
        res += dfs(ch);
        if(e.cost == 0){
            res -= (path00(ch) + 1) * (path00(ch) + 1 + path10(ch) + path11(ch));
        }
        else{
            res -= (path11(ch) + 1) * (path11(ch) + 1 + path01(ch) + path00(ch));
        }
    }
    return dp[i] = res;
}

int main()
{
    int n;
    cin >> n;
    WeightedGraph<int> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }
    t.init(g, 0);
    fill(p00, p00 + n, -1);
    fill(p01, p01 + n, -1);
    fill(p10, p10 + n, -1);
    fill(p11, p11 + n, -1);
    fill(dp, dp + n, -1);
    cout << dfs(0) << endl;
}