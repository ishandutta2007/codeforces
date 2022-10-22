#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

struct Tree
{
    int n;
    int r;
    int l;
    std::vector<std::vector<int>> prit;
    std::vector<std::vector<int>> t;
    std::vector<int> par;
    std::vector<int> dpt;
    std::vector<int> tour;
    std::vector<std::vector<int>> appear_on_tour;
    std::vector<std::vector<int>> anc;
    
    Tree(){}
    
    Tree(int n) : n(n){
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
    }
    
    void add_edge(int u, int v){
        prit[u].push_back(v);
        prit[v].push_back(u);
    }
    
    void build(int r_){
        r = r_;
        for(int i = 0; i < n; i++) dpt[i] = -1;
        std::queue<int> que;
        par[r] = -1;
        dpt[r] = 0;
        que.push(r);
        while(que.size()){
            int u = que.front();
            que.pop();
            for(int v : prit[u]){
                if(dpt[v] == -1){
                    t[u].push_back(v);
                    par[v] = u;
                    dpt[v] = dpt[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    
    void rebuild(int r_){
        for(int u = 0; u < n; u++) t[u].clear();
        build(r_);
    }
    
/*
    std::vector<int> toposort(){
        std::vector<std::pair<int, int>> p(n);
        for(int i = 0; i < n; i++) p[i] = std::pair<int, int>(dpt[i], i);
        sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());
        std::vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
*/
    
    void dfs(int u, int &k){
        appear_on_tour[u].push_back(k);
        tour[k++] = u;
        for(int v : t[u]){
            dfs(v, k);
            appear_on_tour[u].push_back(k);
            tour[k++] = u;
        }
    }
    
    void build_euler_tour(){
        tour.resize(n * 2 - 1);
        appear_on_tour.resize(n);
        int k = 0;
        dfs(r, k);
    }
    
    void build_lca(){
        for(l = 1; l <= n; l++){
            if((1 << (l - 1)) >= n) break;
        }
        anc.resize(l);
        for(int j = 0; j < l; j++) anc[j].resize(n);
        for(int i = 0; i < n; i++) anc[0][i] = par[i];
        for(int j = 1; j < l; j++){
            for(int i = 0; i < n; i++){
                if(anc[j - 1][i] == -1) anc[j][i] = -1;
                else anc[j][i] = anc[j - 1][anc[j - 1][i]];
            }
        }
    }
    
    int lca(int u, int v){
        if(dpt[u] < dpt[v]) std::swap(u, v);
        int dpt_diff = dpt[u] - dpt[v];
        for(int j = l - 1; j >= 0; j--){
            if((dpt_diff >> j) & 1) u = anc[j][u];
        }
        if(u == v) return u;
        for(int j = l - 1; j >= 0; j--){
            if(anc[j][u] != anc[j][v]){
                u = anc[j][u];
                v = anc[j][v];
            }
        }
        return anc[0][u];
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[102], b[102];
        for(int i = 0; i < n - 1; i++){
            cin >> a[i] >> b[i];
            a[i]--; b[i]--;
        }
        if(k == 2){
            cout << n * (n - 1) / 2 << endl;
            continue;
        }
        ll ans = 0;
        for(int r = 0; r < n; r++){
            Tree t(n);
            for(int i = 0; i < n - 1; i++) t.add_edge(a[i], b[i]);
            t.build(r);
            ll d[102][102];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++) d[i][j] = 0;
            }
            for(int u = 0; u < n; u++){
                if(u == r) continue;
                int v = u;
                while(t.par[v] != r) v = t.par[v];
                d[v][t.dpt[u]]++;
            }
            for(int dpt = 1; dpt < n; dpt++){
                vector<int> p;
                for(int u = 0; u < n; u++){
                    if(d[u][dpt]) p.push_back(u);
                }
                if((int)p.size() < k) break;
                ll dp[102]{0};
                dp[0] = 1;
                for(int u : p){
                    ll dp2[102]{0};
                    for(int i = 0; i <= k; i++) dp2[i] = dp[i];
                    for(int i = 1; i <= k; i++) dp2[i] = (dp2[i] + dp[i - 1] * d[u][dpt]) % MOD;
                    swap(dp, dp2);
                }
                ans = (ans + dp[k]) % MOD;
            }
        }
        cout << ans << endl;
    }
}