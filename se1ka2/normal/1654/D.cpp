#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, P> PP;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n & 1) res = res * r % MOD;
        r = r * r % MOD;
        n >>= 1;
    }
    return res;
}

struct PrimeDecomposition
{
    int n;
    vector<bool> p;
    vector<int> prime;
    vector<int> d;
    
    PrimeDecomposition(int n) : n(n){
        p.resize(n + 1);
        d.resize(n + 1);
        d[1] = 1;
        for(int i = 2; i <= n; i++){
            if(!p[i]){
                prime.push_back(i);
                for(int j = i; j <= n; j += i){
                    if(!p[j]) d[j] = i;
                    p[j] = true;
                }
            }
        }
    }
    
    vector<int> decomposition(int x){
        vector<int> res;
        while(x > 1){
            res.push_back(d[x]);
            x /= d[x];
        }
        return res;
    }
};

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedTree
{
    int n;
    int r;
    int l;
    std::vector<std::vector<Edge<T>>> prit;
    std::vector<std::vector<Edge<T>>> t;
    std::vector<Edge<T>> par;
    std::vector<int> dpt;
    std::vector<Edge<T>> tour;
    std::vector<std::vector<int>> appear_on_tour;
    std::vector<std::vector<int>> anc;
    
    WeightedTree(){}
    
    WeightedTree(int n) : n(n){
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
    }
    
    void add_edge(int u, int v, T cost){
        prit[u].push_back(Edge<T>{v, cost});
        prit[v].push_back(Edge<T>{u, cost});
    }
    
    void build(int r_){
        r = r_;
        for(int i = 0; i < n; i++) dpt[i] = -1;
        std::queue<int> que;
        par[r].to = -1;
        dpt[r] = 0;
        que.push(r);
        while(que.size()){
            int u = que.front();
            que.pop();
            for(Edge<T> &e : prit[u]){
                int v = e.to;
                if(dpt[v] == -1){
                    t[u].push_back(e);
                    par[v] = Edge<T>{u, e.cost};
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
        for(Edge<T> &e : t[u]){
            appear_on_tour[u].push_back(k);
            tour[k++] = e;
            dfs(e.to, k);
        }
        appear_on_tour[u].push_back(k);
        tour[k++] = par[u];
    }
    
    void build_euler_tour(){
        tour.resize(n * 2 - 1);
        appear_on_tour.resize(n);
        int k = 0;
        dfs(0, k);
    }
    
    void build_lca(){
        for(l = 1; l <= n; l++){
            if((1 << (l - 1)) >= n) break;
        }
        anc.resize(l);
        for(int j = 0; j < l; j++) anc[j].resize(n);
        for(int i = 0; i < n; i++) anc[0][i] = par[i].to;
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

void dfs(int u, int *d, int *l, WeightedTree<PP> &t, PrimeDecomposition &pd){
    for(Edge<PP> e : t.t[u]){
        int v = e.to;
        int x = e.cost.first.second, y = e.cost.second.second;
        if(e.cost.first.first == v) swap(x, y);
        vector<int> a = pd.decomposition(x);
        vector<int> b = pd.decomposition(y);
        for(int p : b) d[p]++;
        for(int p : a){
            d[p]--;
            l[p] = min(l[p], d[p]);
        }
        dfs(v, d, l, t, pd);
        for(int p : a) d[p]++;
        for(int p : b) d[p]--;
    }
}

ll dfs2(int u, int *d, ll &s, WeightedTree<PP> &t, PrimeDecomposition &pd){
    ll res = s;
    for(Edge<PP> e : t.t[u]){
        int v = e.to;
        int x = e.cost.first.second, y = e.cost.second.second;
        if(e.cost.first.first == v) swap(x, y);
        vector<int> a = pd.decomposition(x);
        vector<int> b = pd.decomposition(y);
        for(int p : b){
            d[p]++;
            s = s * p % MOD;
        }
        for(int p : a){
            d[p]--;
            s = s * modpow(p, MOD - 2) % MOD;
        }
        res = (res + dfs2(v, d, s, t, pd)) % MOD;
        for(int p : a){
            d[p]++;
            s = s * p % MOD;
        }
        for(int p : b){
            d[p]--;
            s = s * modpow(p, MOD - 2) % MOD;
        }
    }
    return res;
}

int main()
{
    PrimeDecomposition pd(200000);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        WeightedTree<PP> t(n);
        for(int i = 0; i < n - 1; i++){
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            u--; v--;
            t.add_edge(u, v, PP(P(u, x), P(v, y)));
        }
        t.build(0);
        int d[200005], l[200005];
        for(int i = 0; i <= n; i++) d[i] = l[i] = 0;
        dfs(0, d, l, t, pd);
        ll s = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < -l[i]; j++) s = s * i % MOD;
        }
        cout << dfs2(0, d, s, t, pd) << endl;
    }
}