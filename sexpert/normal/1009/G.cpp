#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int INF = 1e9;

struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void addEdge(int u, int v, int cap, int rcap = 0) {
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, rcap};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int dis[MAXN], ptr[MAXN], mask[100005], s, t;

bool bfs() {
    queue<int> q({s});
    memset(dis, -1, sizeof dis);
    dis[s] = 0;
    while(!q.empty() && dis[t] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            if(e.f < e.cap && dis[e.to] == -1) {
                dis[e.to] = dis[u] + 1;
                q.push(e.to);
            }
        }
    }
    return dis[t] != -1;
}

int dfs(int u, int f) {
    if(u == t || !f)
        return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1)
            continue;
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

int maxflow() {
    int res = 0;
    while(bfs()) {
        memset(ptr, 0, sizeof ptr);
        while(int df = dfs(s, INF))
            res += df;
    }
    return res;
}

int main() {
    s = 70;
    t = 71;
    for(int i = 0; i < 6; i++)
        addEdge(s, i, 0);
    for(int j = 6; j < 70; j++)
        addEdge(j, t, 0);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 64; j++) {
            if(((1 << i)&j) == (1 << i))
                addEdge(i, j + 6, INF);
        }
    }
    string str;
    cin >> str;
    for(auto c : str)
        adj[s][c - 'a'].cap++;
    int m, rest;
    cin >> m;
    rest = m;
    while(m--) {
        int p;
        string tr;
        cin >> p >> tr;
        p--;
        int ms = 0;
        for(auto c : tr)
            ms |= (1 << (c - 'a'));
        mask[p] = ms;
        adj[ms + 6][0].cap++;
    }
    string res;
    for(int i = 0; i < str.size(); i++) {
        bool can = false;
        if(mask[i]) {
            adj[6 + mask[i]][0].cap--;
            rest--;
        }
        for(int j = 0; j < 6; j++) {
            if(adj[s][j].cap == 0)
                continue;
            if(mask[i] && ((mask[i]&(1<<j)) == 0))
                continue;
            //cout << i << " " << j << endl;
            adj[s][j].cap--;
            int x = maxflow();
            adj[s][j].cap++;
            for(int i = 0; i <= 71; i++)
                for(auto &e : adj[i]) e.f = 0;
            if(x == rest) {
                can = true;
                res += ('a' + j);
                adj[s][j].cap--;
                break;
            }
        }
        if(!can)
            break;

        //cout << res << '\n';
    }
    if(res.size() < str.size())
        cout << "Impossible\n";
    else
        cout << res << '\n';
}