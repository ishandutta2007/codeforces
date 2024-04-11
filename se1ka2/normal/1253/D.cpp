#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UnionFind
{
    int par[200002], rank[200002], lar[200002];
    
public:
    UnionFind(int n){
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
            lar[i] = i;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return par[i] == par[j];
    }
    
    void unite(int i, int j){
        if(same(i, j)) return;
        i = find(i), j = find(j);
        lar[i] = max(lar[i], lar[j]);
        lar[j] = max(lar[j], lar[i]);
        if(rank[i] < rank[j]) par[i] = j;
        else{
            par[j] = i;
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
    
    int largest(int i){
        return lar[find(i)];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.unite(u, v);
    }
    int bf = 0;
    for(int i = 0; i < n; i++) if(uf.find(i) == i) bf++;
    int l = -1;
    for(int i = 0; i < n; i++){
        l = uf.largest(i);
        for(int j = i + 1; j <= l; j++){
            uf.unite(i, j);
            l = uf.largest(i);
        }
        i = l;
    }
    int af = 0;
    for(int i = 0; i < n; i++) if(uf.find(i) == i) af++;
    cout << bf - af << endl;
}