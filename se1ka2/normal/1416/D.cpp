#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> P;

int p[200005];
int z[200005];      // z[p[u]] = u
int a[300005], b[300005];
int t[500005], r[500005];
bool f[300005];     // f[i] -> e[i] : removed
int sz[200005];
int par[200005];    // par[u] : parent u on UF
int mx[200005];     // mx[u] : max value on subtree of u
set<int, greater<int>> ch[200005];  // ch[u] : set of mx[v] s.t. v is child of u

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        z[p[i]] = i;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a[i], &b[i]);
        a[i]--; b[i]--;
    }
    for(int i = 0; i < q; i++){
        scanf("%d %d", &t[i], &r[i]);
        r[i]--;
        if(t[i] == 2) f[r[i]] = true;   // remove e[i]
    }
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        par[i] = i;
        mx[i] = p[i];
    }
    for(int i = 0; i < m; i++){
        if(f[i]) continue;      // add only not removed edges
        int u = a[i], v = b[i];
        /* find roots */
        while(par[u] != u) u = par[u];
        while(par[v] != v) v = par[v];
        if(u == v) continue;
        /* unite vertexes */
        if(sz[u] < sz[v]){
            par[u] = v;
            ch[v].insert(mx[u]);
            mx[v] = max(mx[v], mx[u]);
            sz[v] += sz[u];
        }
        else{
            par[v] = u;
            ch[u].insert(mx[v]);
            mx[u] = max(mx[u], mx[v]);
            sz[u] += sz[v];
        }
    }
    vector<int> add;
    vector<P> addp;
    for(int i = q - 1; i >= 0; i--){
        if(t[i] == 1) continue;     // add removed edges
        int u = a[r[i]], v = b[r[i]];
        while(par[u] != u) u = par[u];
        while(par[v] != v) v = par[v];
        if(u == v) continue;
        add.push_back(i);
        addp.push_back(P(u, v));
        if(sz[u] < sz[v]){
            par[u] = v;
            ch[v].insert(mx[u]);
            mx[v] = max(mx[v], mx[u]);
            sz[v] += sz[u];
        }
        else{
            par[v] = u;
            ch[u].insert(mx[v]);
            mx[u] = max(mx[u], mx[v]);
            sz[u] += sz[v];
        }
    }
    reverse(add.begin(), add.end());
    reverse(addp.begin(), addp.end());
    int c = 0;
    for(int i = 0; i < q; i++){
        if(c < (int)add.size() && add[c] == i){
            int u = addp[c].first, v = addp[c].second;
            c++;
            if(par[u] == v) swap(u, v);
            ch[u].erase(mx[v]);
            par[v] = v;
            int temp = mx[u];
            mx[u] = p[u];
            if(ch[u].size()) mx[u] = max(mx[u], *ch[u].begin());
            if(mx[u] == temp) continue;
            while(par[u] != u){
                ch[par[u]].erase(temp);
                ch[par[u]].insert(mx[u]);
                temp = mx[par[u]];
                mx[par[u]] = max(p[par[u]], *ch[par[u]].begin());
                if(mx[par[u]] == temp) break;
                u = par[u];
            }
        }
        else if(t[i] == 1){
            int u = r[i];
            while(par[u] != u) u = par[u];
            printf("%d\n", mx[u]);
            if(mx[u] == 0) continue;
            int v = z[mx[u]];
            p[v] = 0;
            mx[v] = 0;
            if(ch[v].size()) mx[v] = *ch[v].begin();
            while(par[v] != v){
                ch[par[v]].erase(mx[par[v]]);
                ch[par[v]].insert(mx[v]);
                mx[par[v]] = max(p[par[v]], *ch[par[v]].begin());
                v = par[v];
            }
        }
    }
}