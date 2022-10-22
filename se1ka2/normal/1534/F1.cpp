#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Graph
{
    int n;
    std::vector<std::vector<int>> g;
    
    Graph(){}
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

struct SCC      //StronglyConnectedComponents
{
    int n;
    int k;
    std::vector<std::vector<int>> g, rg;
    std::vector<bool> used;
    std::vector<int> cmp;
    std::vector<int> vs;
    
    SCC(){}
    
    SCC(int n) : n(n){
        g.resize(n);
        rg.resize(n);
        used.resize(n);
        cmp.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
        rg[to].push_back(from);
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
        for(int i = 0; i < n; i++) used[i] = false;
        for(int i = 0; i < n; i++){
            if(!used[i]) dfs(i);
        }
        for(int i = 0; i < n; i++) used[i] = false;
        k = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!used[vs[i]]){
                rdfs(vs[i], k);
                k++;
            }
        }
        return k;
    }
    
    int decomposition(Graph &dag){
        k = decomposition();
        dag.n = k;
        dag.g.resize(k);
        std::map<std::pair<int, int>, bool> mp;
        for(int u = 0; u < n; u++){
            for(int v : g[u]){
                if(!mp[std::pair<int, int> (cmp[u], cmp[v])] && cmp[u] != cmp[v]){
                    mp[std::pair<int, int> (cmp[u], cmp[v])] = true;
                    dag.add_edge(cmp[v], cmp[u]);
                }
            }
        }
        return k;
    }
};

string s[400005];
int a[400005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> a[i];
    SCC g(n * m);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] != '#'){
                ans--;
                continue;
            }
            if(i > 0 && s[i - 1][j] == '#') g.add_edge(i * m + j, (i - 1) * m + j);
            int k = i;
            while(k < n && (k == i || s[k][j] != '#')){
                if(j > 0 && s[k][j - 1] == '#') g.add_edge(i * m + j, k * m + (j - 1));
                if(j < m && s[k][j + 1] == '#') g.add_edge(i * m + j, k * m + (j + 1));
                k++;
            }
            if(k < n) g.add_edge(i * m + j, k * m + j);
        }
    }
    Graph dag;
    int k = g.decomposition(dag);
    for(int i = 0; i < k; i++){
        if(dag.g[i].size() == 0) ans++;
    }
    cout << ans << endl;
}