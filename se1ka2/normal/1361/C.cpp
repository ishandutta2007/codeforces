#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> par, rank;
    
    UnionFind(int n){
        par.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    void unite(int i, int j){
        if(same(i, j)) return;
        i = find(i), j = find(j);
        if(rank[i] < rank[j]) par[i] = j;
        else{
            par[j] = i;
            if(rank[i] == rank[j]) rank[i]++;
        }
    }
};

int a[500005], b[500005];
int d[1200005];
int s[1200005];
int nx[1200005];
vector<int> v[1200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
    int t;
    for(t = 20; t >= 0; t--){
        for(int i = 0; i < (1 << t); i++) d[i] = 0;
        UnionFind uf(1 << t);
        for(int i = 0; i < n; i++){
            d[a[i] & ((1 << t) - 1)]++;
            d[b[i] & ((1 << t) - 1)]++;
            uf.unite(a[i] & ((1 << t) - 1), b[i] & ((1 << t) - 1));
        }
        int c = 0;
        bool f = true;
        for(int i = 0; i < (1 << t); i++){
            if(d[i] % 2) f = false;
            if(uf.find(i) == i && d[i] != 0) c++;
        }
        if(c == 1 && f){
            break;
        }
    }
    cout << t << endl;
    for(int i = 0; i < (1 << t); i++) s[i] = -1;
    UnionFind uf(n * 2);
    for(int i = 0; i < n; i++){
        uf.unite(i * 2, i * 2 + 1);
        v[a[i] & ((1 << t) - 1)].push_back(i * 2);
        if(s[a[i] & ((1 << t) - 1)] != -1){
            nx[i * 2] = s[a[i] & ((1 << t) - 1)];
            nx[s[a[i] & ((1 << t) - 1)]] = i * 2;
            uf.unite(s[a[i] & ((1 << t) - 1)], i * 2);
            s[a[i] & ((1 << t) - 1)] = -1;
        }
        else{
            s[a[i] & ((1 << t) - 1)] = i * 2;
        }
        v[b[i] & ((1 << t) - 1)].push_back(i * 2 + 1);
        if(s[b[i] & ((1 << t) - 1)] != -1){
            nx[i * 2 + 1] = s[b[i] & ((1 << t) - 1)];
            nx[s[b[i] & ((1 << t) - 1)]] = i * 2 + 1;
            uf.unite(s[b[i] & ((1 << t) - 1)], i * 2 + 1);
            s[b[i] & ((1 << t) - 1)] = -1;
        }
        else{
            s[b[i] & ((1 << t) - 1)] = i * 2 + 1;
        }
    }
    for(int i = 0; i < (1 << t); i++){
        if((int)v[i].size() == 0) continue;
        int u = v[i][0];
        for(int w : v[i]){
            if(!uf.same(u, w)){
                int x = nx[u], y = nx[w];
                nx[u] = w;
                nx[w] = u;
                nx[x] = y;
                nx[y] = x;
                uf.unite(x, y);
            }
        }
    }
    int u = 0;
    for(int i = 0; i < n; i++){
        cout << u + 1 << " ";
        if(u % 2) u--;
        else u++;
        cout << u + 1 << " ";
        u = nx[u];
    }
    cout << endl;
}