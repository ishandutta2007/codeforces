#include <iostream>
#include <vector>
using namespace std;

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

struct SCCD    //StronglyConnectedComponentsDecomposition
{
    vector<vector<int>> g;
    vector<vector<int>> rg;
    int n;
    vector<bool> used;
    vector<int> cmp;
    vector<int> vs;
    
    SCCD(Graph &g_){
        n = g_.n;
        g.resize(n);
        rg.resize(n);
        for(int u = 0; u < n; u++) for(int v : g_.g[u]){
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        used.resize(n);
        cmp.resize(n);
    }
    
    void dfs(int u){
        used[u] = true;
        for(int v : g[u]){
            if(!used[v]) dfs(v);
        }
        vs.push_back(u);
    }
    
    void rdfs(int u, int k){
        used[u] = true;
        cmp[u] = k;
        for(int v : rg[u]){
            if(!used[v]) rdfs(v, k);
        }
    }
    
    int decomposition(){
        fill(used.begin(), used.end(), false);
        for(int i = 0; i < n; i++){
            if(!used[i]) dfs(i);
        }
        fill(used.begin(), used.end(), false);
        int k = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!used[vs[i]]){
                rdfs(vs[i], k);
                k++;
            }
        }
        return k;
    }
};

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m;
        scanf("%d %d", &n, &m);
        Graph g(n);
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            g.add_edge(a, b);
        }
        SCCD sccd(g);
        sccd.decomposition();
        int cat = 0, human = 0;
        for(int i = 0; i < n; i++){
            if(sccd.cmp[i] == 0) cat++;
            else human++;
        }
        if(human == 0){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%d %d\n", human, cat);
        for(int i = 0; i < n; i++){
            if(sccd.cmp[i] != 0) printf("%d ", i + 1);
        }
        printf("\n");
        for(int i = 0; i < n; i++){
            if(sccd.cmp[i] == 0) printf("%d ", i + 1);
        }
        printf("\n");
    }
}