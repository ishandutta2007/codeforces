#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

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
    
/*
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
*/
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005], b[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        SCC g(n);
        P p[100005];
        for(int i = 0; i < n; i++) p[i] = P(a[i], i);
        sort(p, p + n);
        for(int i = 0; i < n - 1; i++) g.add_edge(p[i + 1].second, p[i].second);
        for(int i = 0; i < n; i++) p[i] = P(b[i], i);
        sort(p, p + n);
        for(int i = 0; i < n - 1; i++) g.add_edge(p[i + 1].second, p[i].second);
        g.decomposition();
        for(int i = 0; i < n; i++){
            if(g.cmp[i] == 0) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}