#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

struct UnionFind
{
    std::vector<int> par, sz, rt;
    std::vector<int> p;
    int k;
    
    UnionFind(int n){
        k = n;
        par.resize(n);
        sz.resize(n);
        rt.resize(n);
        p.resize(n * 2 - 1);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
            rt[i] = i;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    void unite(int i, int j, int a[][502], int *ans){
        i = find(i), j = find(j);
        if(i == j) return;
        if(sz[i] < sz[j]) std::swap(i, j);
        par[j] = i;
        sz[i] += sz[j];
        int u = rt[i], v = rt[j];
        if(a[i][j] == ans[u]){
            p[v] = u;
        }
        else if(a[i][j] == ans[v]){
            p[u] = v;
            rt[i] = v;
        }
        else{
            p[u] = k;
            p[v] = k;
            rt[i] = k;
            ans[k++] = a[i][j];
        }
    }
    
    int size(int i){
        return sz[find(i)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    PP p[300000];
    int a[502][502];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            p[i * n + j] = PP(a[i][j], P(i, j));
        }
    }
    sort(p, p + n * n);
    UnionFind uf(n);
    int ans[1002]{0};
    for(int i = 0; i < n * n; i++){
        int u = p[i].second.first, v = p[i].second.second;
        if(u == v) ans[u] = a[u][v];
        uf.unite(u, v, a, ans);
    }
    cout << uf.k << "\n";
    for(int i = 0; i < uf.k; i++) cout << ans[i] << " ";
    cout << endl;
    cout << uf.k << "\n";
    for(int i = 0; i < uf.k - 1; i++) cout << i + 1 << " " << uf.p[i] + 1 << endl;
}