#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to, id;
    bool rev;
    edge(int _to, int _id, bool _rev){
        to = _to, id = _id, rev = _rev;
    }
};

const int N = (int)2e5 + 500;

int n,m;
vector<edge> G[N];
int val[N], res[N];
bool vis[N];

void dfs(int v){
    vis[v] = true;
    for(auto e : G[v]){
        if(!vis[e.to]){
            dfs(e.to);
            int flow = val[e.to];
            res[e.id] = (e.rev ? -flow : flow);
            val[v] += flow;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++) cin >> val[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(edge(b, i, false));
        G[b].push_back(edge(a, i, true));
    }
    int sum = 0;
    for(int i = 0; i < n; i++) sum += val[i];
    if(sum != 0) return cout << "Impossible" << endl, 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i);
    }
    cout << "Possible" << endl;
    for(int i = 0; i < m; i++) cout << res[i] << endl;
}