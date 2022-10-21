#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 40005 * 2, INF = (int)1e9;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

// Finding max flow in O(V^2 * E)
struct Dinic {
    vector<edge> G[N];
    int level[N], iter[N];

    void add_edge(int from, int to, int cap){
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size() - 1));
    }

    void bfs(int s){
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int i = 0; i < sz(G[v]); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }


    int dfs(int v, int t, int f){
        if(v == t) return f;

        for(int &i = iter[v]; i < (int)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
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
        int flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
    }
} dinic;

//typedef pair<pii, int> piii;
int n, m;
string str[N];

int getid(int i, int j, int v) {
    return v * n * m + i * m + j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int tcnt = 0;
    int s = 2 * n * m, t = s + 1;
    int nnodes = 0;
    rep(i, 0, n) {
        cin >> str[i];

    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(str[i][j] == '#') {
                tcnt++;
                if(i + 1 < n && str[i + 1][j] == '#') nnodes++, dinic.add_edge(s, getid(i, j, 0), 1);
                if(j + 1 < m && str[i][j + 1] == '#') nnodes++, dinic.add_edge(getid(i, j, 1), t, 1);
            }
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            if(str[i][j] != '#') continue;
            vi vs, hs;
            if(i > 0 && str[i - 1][j] == '#') vs.push_back(getid(i - 1, j, 0));
            if(i + 1 < n && str[i + 1][j] == '#') vs.push_back(getid(i, j, 0));
            if(j > 0 && str[i][j - 1] == '#') hs.push_back(getid(i, j - 1, 1));
            if(j + 1 < m && str[i][j + 1] == '#') hs.push_back(getid(i, j, 1));
            for(int v : vs) {
                for(int h : hs) dinic.add_edge(v, h, 1);
            }
        }
    }
//    cout << nnodes << " " << dinic.max_flow(s, t) << " " << tcnt << endl;
    int mx_id_set = nnodes - dinic.max_flow(s, t);
    cout << tcnt - mx_id_set << '\n';

}