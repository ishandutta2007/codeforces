#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){
        i++;
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
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

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<int> par;
    vector<int> dpt;
    vector<int> tour;
    
    void init(Graph &g, int root_){
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
            for(int ch : g.g[pa]){
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(Graph &g, int root_){
        init(g, root_);
    }
    
    void dfs(int u){
        tour.push_back(u);
        for(int v : t[u]){
            dfs(v);
            tour.push_back(u);
        }
    }
};

vector<P> p[300005];
ll ans[300005];

int main()
{
    ll n;
    cin >> n;
    Graph g(n);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        g.add_edge(x, y);
        g.add_edge(y, x);
    }
    Tree t(g, 0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int v;
        scanf("%d", &v);
        v--;
        ll d, x;
        scanf("%lld %lld", &d, &x);
        p[v].push_back(P(min(n - 1, d + t.dpt[v]), x));
    }
    t.dfs(0);
    BIT<ll> bit(n);
    for(int k = 0; k < (int)t.tour.size(); k++){
        int u = t.tour[k];
        int v = t.tour[k - 1];
        if(k == 0 || t.dpt[u] > t.dpt[v]){
            for(P pp : p[u]){
                bit.add(pp.first, pp.second);
            }
        }
        else{
            for(P pp : p[v]){
                bit.add(pp.first, -pp.second);
            }
        }
        ans[u] = bit.sum(n - 1) - bit.sum(t.dpt[u] - 1);
    }
    for(int i = 0; i < n; i++) printf("%lld ", ans[i]);
    cout << endl;
}