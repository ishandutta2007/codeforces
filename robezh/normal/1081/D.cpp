#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)1e5 + 500;
typedef pair<int, P> edge;

int n,m,k;
vector<edge> E;
int f[N];
int sz[N];
int s[N];

int find(int u){return f[u] == u ? u : f[u] = find(f[u]);}
bool same(int u, int v){return find(u) == find(v);}
bool unite(int u, int v){
    u = find(u), v = find(v);
    sz[u] += sz[v];
    f[v] = u;
    return sz[u] == k;
}

int main(){
    for(int i = 0; i < N; i++) f[i] = i;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &s[i]);
        s[i]--;
        sz[s[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        a--, b--;
        E.push_back({w, {a, b}});
    }
    sort(E.begin(), E.end());
    for(edge e : E){
        P p = e.second;
        if(!same(p.first, p.second) && unite(p.first, p.second)){
            for(int i = 0; i < k; i++){
                printf("%d ", e.first);
            }
            break;
        }
    }
}