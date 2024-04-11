#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int N = 205, INF = (int)1e9;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};


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

int n, m;
int a[N], b[N];
int res[N][N];

int main() {
    cin >> n >> m;
    int suma = 0, sumb = 0;
    for(int i = 0; i < n; i++) cin >> a[i], suma += a[i];
    for(int i = 0; i < n; i++) cin >> b[i], sumb += b[i];
    if(suma != sumb) return cout << "NO" << endl, 0;

    int s = 2 * n, t = s + 1;
    for(int i = 0; i < n; i++) flow.add_edge(i, i + n, a[i]);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        flow.add_edge(u + n, v, INF);
        flow.add_edge(v + n, u, INF);
    }
    int difsum = 0;
    for(int i = 0; i < n; i++) {
        int dif = b[i] - a[i];
        if(dif > 0) flow.add_edge(i, t, dif), difsum += dif;
        else if(dif < 0) flow.add_edge(s, i, -dif);
    }
    int f = flow.max_flow(s, t);

    if(f != difsum) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(auto &e : flow.G[i]) {
            if(e.to != i + n) res[e.to - n][i] = e.cap;
        }
        for(auto &e : flow.G[i + n]) {
            if(e.to == i) res[i][i] = a[i] - e.cap;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << res[i][j] << " ";
        cout << endl;
    }
}