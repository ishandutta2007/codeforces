#include <iostream>
#include <queue>
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
                    dag.add_edge(cmp[u], cmp[v]);
                }
            }
        }
        return k;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        SCC g0(n + m);
        int l = n;
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            if(a == b){
                g0.add_edge(a, l);
                g0.add_edge(l, a);
                l++;
            }
            else g0.add_edge(a, b);
        }
        int k = g0.decomposition();
        int c[800005];
        for(int u = 0; u < k; u++) c[u] = 0;
        for(int u = 0; u < n + m; u++) c[g0.cmp[u]]++;
        int d[800005];
        for(int u = 0; u < n + m; u++) d[u] = 0;
        if(c[g0.cmp[0]] >= 2) d[0] = -1;
        else d[0] = 1;
        queue<int> que0, que1;
        if(d[0] == -1) que0.push(0);
        else que1.push(0);
        while(que0.size() + que1.size()){
            int u;
            if(que0.size()){
                u = que0.front();
                que0.pop();
            }
            else{
                u = que1.front();
                que1.pop();
            }
            for(int v : g0.g[u]){
                if(d[u] == -1 || c[g0.cmp[v]] >= 2){
                    if(d[v] >= 0){
                        d[v] = -1;
                        que0.push(v);
                    }
                }
                else{
                    if(d[v] == 0){
                        d[v] = d[u];
                        que1.push(v);
                    }
                    else if(d[v] == 1){
                        d[v] = 2;
                        que1.push(v);
                    }
                }
            }
        }
        for(int u = 0; u < n; u++) cout << d[u] << " ";
        cout << "\n";
    }
}