#include<cstdio>
#include<iostream>
#include<vector>
#include <cstring>

using namespace std;

typedef long long ll;
const int N = 2005, INF = (int)1e9, E3 = 1005;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

int n,m,s,b,k,h;

struct Ford {
    vector<edge> G[N];
    bool used[N];

    void add_edge(int from, int to, int cap){
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size() - 1));
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        used[v] = true;

        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
                int d = dfs(e.to, t, min(e.cap, f));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int f = 0;
        for(;;){
            fill(used, used + N, false);
            int d = dfs(s, t, INF);
            if(d == 0) return f;
            f += d;
        }
    }
} flow;

struct Ship {
    int x, a, f;

    void read() {
        cin >> x >> a >> f;
        x--;
    }
} sps[E3];

struct Base {
    int x, d;

    void read() {
        cin >> x >> d;
        x--;
    }
} bss[E3];

int dis[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        dis[a][b] = dis[b][a] = 1;
    }
    for(int i = 0; i < n; i++) dis[i][i] = 0;
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
//    cout << dis[0][0] << endl;
    cin >> s >> b >> k >> h;
    int f_s = s + b, f_t = f_s + 1;
    for(int i = 0; i < s; i++) {
        sps[i].read();
        flow.add_edge(f_s, i, 1);
    }
    for(int i = 0; i < b; i++) {
        bss[i].read();
        flow.add_edge(i + s, f_t, 1);
    }
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < b; j++) {
            if(sps[i].a >= bss[j].d && sps[i].f >= dis[sps[i].x][bss[j].x])
                flow.add_edge(i, j + s, 1);
        }
    }
    int max_flow = flow.max_flow(f_s, f_t);
//    cout << max_flow << endl;
    ll res = (ll)1e18;
    for(int i = 0; i <= s; i++) {
        int rem = min(max_flow, s - i);
        res = min(res, 1LL * rem * k + 1LL * i * h);
    }
    cout << res << "\n";

}