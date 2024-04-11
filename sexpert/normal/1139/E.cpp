#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 10;
const int INF = 1e9;

struct edge {
    int to, rev, f, cap;
};
vector<edge> adj[MAXN];

void addEdge(int u, int v, int cap = 1) {
    edge a = {v, (int)adj[v].size(), 0, cap};
    edge b = {u, (int)adj[u].size(), 0, 0};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int ptr[MAXN], dis[MAXN], src, dst;

bool bfs() {
    fill(dis, dis + MAXN, -1);
    queue<int> q({src});
    dis[src] = 0;
    while(!q.empty() && dis[dst] == -1) {
        int u = q.front(); q.pop();
        for(auto e : adj[u]) {
            int v = e.to;
            if(dis[v] == -1 && e.f < e.cap) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[dst] != -1;
}

int dfs(int u, int f) {
    if(u == dst || !f) return f;
    for(int &i = ptr[u]; i < adj[u].size(); i++) {
        edge &e = adj[u][i];
        int v = e.to;
        if(dis[v] != dis[u] + 1) continue;
        if(int df = dfs(v, min(f, e.cap - e.f))) {
            e.f += df;
            adj[v][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

int mf() {
    int res = 0;
    while(bfs()) {
        fill(ptr, ptr + MAXN, 0);
        while(int df = dfs(src, INF)) res += df;
    }
    return res;
}

int pot[5005], club[5005], take[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    src = 10004, dst = 10005;
    int m, n;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> pot[i];
    for(int i = 1; i <= n; i++) {
        cin >> club[i];
        club[i]--;
    }
    for(int i = 0; i < m; i++)
        addEdge(src, i);
    int d;
    cin >> d;
    vector<int> enter(d);
    for(int i = 0; i < d; i++) {
        cin >> enter[i];
        take[enter[i]] = 1;
    }
    reverse(enter.begin(), enter.end());
    for(int i = 1; i <= n; i++) {
        if(take[i]) continue;
        addEdge(club[i], m + pot[i]);
    }
    vector<int> answers;
    int pt = m, ans = 0, cur = 0;
    addEdge(pt++, dst);
    while(cur < d) {
        while(mf()) {
            addEdge(pt++, dst);
            ans++;
        }
        answers.push_back(ans);
        int x = enter[cur];
        addEdge(club[x], m + pot[x]);
        cur++;
    }
    reverse(answers.begin(), answers.end());
    for(auto a : answers)
        cout << a << '\n';
}