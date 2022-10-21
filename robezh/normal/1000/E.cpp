#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 500;
typedef pair<int, int> P;

vector<int> G[N], G2[N];
int n, m;
bool visited[N];
int tin[N], fup[N];
int timer;
int d[N], f[N];
set<int> Bri[N];

int find(int u){return f[u] == u ? u : f[u] = find(f[u]);}
void unite(int u, int v){int fu = find(u), fv = find(v); f[fu] = fv;}

void IS_BRIDGE(int u, int v){
    Bri[u].insert(v);
    Bri[v].insert(u);
}


void dfs(int x, int par = -1)
{
    tin[x] = timer++;
    fup[x] = tin[x];
    for(auto nxt : G[x])
    {
        if(tin[nxt] > 0)
        {
            if(par != nxt)
                fup[x] = min(fup[x], tin[nxt]);
        }
        else
        {
            dfs(nxt, x);
            fup[x] = min(fup[x], fup[nxt]);
            if(fup[nxt] > tin[x])
                IS_BRIDGE(x, nxt);
            else
                unite(x, nxt);
        }
    }
}


void find_bridges() {
    timer = 1;
    fill(visited, visited + n, false);
    fill(tin, tin + n, 0);
    fill(fup, fup + n, 0);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

P bfs(int v){
    for(int i = 0; i < n; i++) d[i] = n+1;
    d[v] = 0;

    int u = 0;
    queue<int> que;
    que.push(v);
    while(!que.empty()){
        u = que.front();
        que.pop();
        for(int nxt : G2[u]){
            if(d[nxt] > d[u] + 1){
                d[nxt] = d[u] + 1;
                que.push(nxt);
            }
        }
    }
    return {u, d[u]};
}


int main(){
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) f[i] = i;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    find_bridges();
    for(int i = 0; i < n; i++){
        for(int nxt : Bri[i]){
            G2[find(i)].push_back(find(nxt));
        }
    }
    int v;

    for(int i = 0; i < n; i++) if(G2[i].size()!= 0){v = i; break;}
    P p1 = bfs(v);
    P p2 = bfs(p1.first);
    printf("%d", p2.second);
}