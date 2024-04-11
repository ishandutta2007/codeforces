#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 200000 + 10;

int n, m, c, q;
set<int> Neib[N];

int par[N];

int find(int x) {
    return par[x] == x ? par[x] : par[x] = find(par[x]);
}

void unite(int x,int y) {
    // printf("unite %d %d\n", x, y);
    x = find(x);
    y = find(y);
    // printf("# %d %d\n", x, y);
    if (x == y) return;
    if (Neib[x].size() < Neib[y].size()) swap(x, y);
    for (auto tmp: Neib[y]) Neib[x].insert(tmp);
    Neib[y].clear(), par[y] = x;
    return;
}
map<int,int> mp[N];

void add() {
    int u,v,w; 
    scanf("%d%d%d",&u,&v,&w);
    Neib[find(u)].insert(v); 
    Neib[find(v)].insert(u);
    
    if(mp[w][u]) unite(mp[w][u], v);
    else mp[w][u] = v;

    if(mp[w][v]) unite(mp[w][v], u);
    else mp[w][v] = u;
}

int main() {
    for (int i = 1; i < N; i ++) {
        par[i] = i; Neib[i].insert(i);
    }
    scanf("%d %d %d %d", &n, &m, &c, &q);
    while (m--) add();
    while (q--) {
        char op[2]; 
        scanf("%s",op);
        if (op[0] == '+') add();
        else {
            int u, v; 
            scanf("%d%d",&u,&v);
            if (Neib[find(u)].count(v)) 
                printf("Yes\n"); 
            else 
                printf("No\n");
        }
    }
}