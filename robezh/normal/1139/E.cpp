#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 5005, INF = (int)1e9;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

int n,m,d;
int p[N], c[N];
vector<edge> G[N];
bool used[N];
int quit[N];
bool in[N];
int res[N];

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) cin >> c[i], c[i]--;
    cin >> d;
    fill(in, in + N, true);
    for(int i = 0; i < d; i++) {
        cin >> quit[i];
        quit[i]--;
        in[quit[i]] = false;
    }
    int s = m + 5005, t = s + 1;
    int cur_mx = -1;
    int cur_match = 0;
    for(int i = 0; i < m; i++) add_edge(s, i, 1);
    for(int i = 0; i < n; i++) {
        if(in[i]) add_edge(c[i], m + p[i], 1);
    }
    for(int i = d - 1; i >= 0; i--) {
        while(cur_mx < 5001 && cur_match == cur_mx + 1) {
            cur_mx ++;
            add_edge(m + cur_mx, t, 1);
            cur_match += max_flow(s, t);
        }

        res[i] = cur_mx;

        add_edge(c[quit[i]], m + p[quit[i]], 1);
        cur_match += max_flow(s, t);
    }
    for(int i = 0; i < d; i++) cout << res[i] << "\n";
}