#include <iostream>
#include <vector>
using namespace std;

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
    int n, m, k;
    cin >> n >> m >> k;
    int b[540000];
    for(int i = 0; i < 540000; i++) b[i] = -1;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int c = 0;
        for(int i = 0; i < k; i++){
            c *= 27;
            if(s[i] == '_') c += 26;
            else c += s[i] - 'a';
        }
        b[c] = i;
    }
    SCC g(n);
    for(int i = 0; i < m; i++){
        string s;
        int mt;
        cin >> s >> mt;
        mt--;
        vector<int> v;
        for(int u = 0; u < (1 << k); u++){
            string t = s;
            for(int j = 0; j < k; j++){
                if((u >> j) & 1) t[j] = '_';
            }
            int c = 0;
            for(int i = 0; i < k; i++){
                c *= 27;
                if(t[i] == '_') c += 26;
                else c += t[i] - 'a';
            }
            if(b[c] >= 0) v.push_back(b[c]);
        }
        bool f = false;
        for(int i : v){
            if(i == mt) f = true;
            else g.add_edge(mt, i);
        }
        if(!f){
            cout << "NO" << endl;
            return 0;
        }
    }
    int l = g.decomposition();
    if(l < n) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        int ans[100005];
        for(int i = 0; i < n; i++) ans[g.cmp[i]] = i;
        for(int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
        cout << endl;
    }
}