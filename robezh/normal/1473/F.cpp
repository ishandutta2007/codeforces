#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

const int N = 3005, INF = (int)1e9 + 50;

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

        for(int &i = iter[v]; i < sz(G[v]); i++){
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


int n;
int la[N];
int a[N], b[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int s = n, t = s + 1;
    fill(la, la + 105, -1);
    rep(i, 0, n) {
        cin >> a[i];
        for(int j = 1; j <= a[i]; j++) {
            if(a[i] % j == 0 && la[j] != -1) {
                dinic.add_edge(la[j], i, INF);
            }
        }
        la[a[i]] = i;
    }
    int sum = 0;
    rep(i, 0, n) {
        cin >> b[i];
        if(b[i] > 0) {
            sum += b[i];
            dinic.add_edge(i, t, b[i]);
        } else {
            dinic.add_edge(s, i, -b[i]);
        }
    }
    cout << sum - dinic.max_flow(s, t) << '\n';



}