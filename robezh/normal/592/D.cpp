#include <bits/stdc++.h>
using namespace std;

const int N = 123456 + 50;
const int INF = (int)1e9;
typedef pair<int, int> P;

int n, m;
set<int> G[N];
int dis[N];
bool in[N];
bool at[N];

P bfs(int v) {
    fill(dis, dis + n, INF);
    queue<int> que;
    dis[v] = 0;
    que.push(v);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int nxt : G[u]) {
            if(dis[nxt] > dis[u] + 1) {
                dis[nxt] = dis[u] + 1;
                que.push(nxt);
            }
        }
    }
    int res = -1, u = -1;
    for(int i = 0; i < n; i++) {
        if(dis[i] != INF) {
            if(dis[i] > res){
                res = dis[i];
                u = i;
            }
            else if(dis[i] == res) {
                if(i < u) u = i;
            }
        }
    }
    return {res, u};
}

P get_diameter() {
    int u = -1;
    for(int i = 0; i < n; i++) if(in[i]) {u = i; break;}
    P p = bfs(u);
    P p2 = bfs(p.second);
    return {p2.first, min(p.second, p2.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    fill(in, in + n, true);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i = 0; i < m; i++) {
        int a; cin >> a; a--;
        at[a] = true;
    }
    queue<int> que;
    int cnt = n - 1;
    for(int i = 0; i < n; i++) if(G[i].size() == 1 && !at[i]) que.push(i);
    while(!que.empty()) {
        cnt --;
        int x = que.front(); que.pop();
        in[x] = false;
        for(int nxt : G[x]) {
            G[nxt].erase(x);
            if(!at[nxt] && G[nxt].size() == 1) {
                que.push(nxt);
            }
        }
        G[x].clear();
    }
    P res = get_diameter();
    cout << res.second + 1 << endl << cnt * 2 - res.first << endl;


}