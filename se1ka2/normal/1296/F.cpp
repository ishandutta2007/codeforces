#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 1000000000;

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

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<P> par;
    vector<int> dpt;
    
    void init(WeightedGraph<int> &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = P(-1, -1);
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(Edge<int> e : g.g[pa]){
                int ch = e.to;
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = P(pa, e.cost);
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(WeightedGraph<int> &g, int root_){
        init(g, root_);
    }
};

int main()
{
    int n;
    cin >> n;
    WeightedGraph<int> g(n);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g.add_edge(x, y, i);
        g.add_edge(y, x, i);
    }
    Tree t(g, 0);
    int f[5002];
    fill(f, f + n - 1, 1);
    int m;
    cin >> m;
    int aa[5002], bb[5002], gg[5002];
    for(int i = 0; i < m; i++){
        int a, b, g;
        cin >> aa[i] >> bb[i] >> gg[i];
        aa[i]--; bb[i]--;
        a = aa[i], b = bb[i], g = gg[i];
        if(t.dpt[a] < t.dpt[b]) swap(a, b);
        while(t.dpt[a] > t.dpt[b]){
            f[t.par[a].second] = max(f[t.par[a].second], g);
            a = t.par[a].first;
        }
        while(a != b){
            f[t.par[a].second] = max(f[t.par[a].second], g);
            a = t.par[a].first;
            f[t.par[b].second] = max(f[t.par[b].second], g);
            b = t.par[b].first;
        }
    }
    for(int i = 0; i < m; i++){
        int l = INF;
        int a, b, g;
        a = aa[i], b = bb[i], g = gg[i];
        if(t.dpt[a] < t.dpt[b]) swap(a, b);
        while(t.dpt[a] > t.dpt[b]){
            l = min(f[t.par[a].second], l);
            a = t.par[a].first;
        }
        while(a != b){
            l = min(f[t.par[a].second], l);
            a = t.par[a].first;
            l = min(f[t.par[b].second], l);
            b = t.par[b].first;
        }
        if(l != g){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++) cout << f[i] << " ";
}