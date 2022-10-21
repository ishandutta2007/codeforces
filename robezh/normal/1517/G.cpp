#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int N = 2050;
const ll INF = (int)1e18;


struct edge{
    int to;
    ll cap;
    int rev;
    edge(int _to, ll _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};


struct Dinic {
    vector<edge> G[N];
    int level[N], iter[N];

    void add_edge(int from, int to, ll cap){
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
            for(int i = 0; i < G[v].size(); i++){
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }


    ll dfs(int v, int t, ll f){
        if(v == t) return f;

        for(int &i = iter[v]; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                ll d = dfs(e.to, t, min(e.cap, f));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }


    ll max_flow(int s, int t){
        ll flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            ll f;
            while((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
    }
} dinic;


int n;
pii p[N];
map<pii, int> mp;
int tp[2][2] = {{1, 0}, {2, 3}};

int gettype(int i) {
    return tp[(p[i].first % 2 + 2) % 2][(p[i].second % 2 + 2) % 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;
    ll sum = 0;
    int ds = 2 * n + 1, dt = 2 * n + 2;
    rep(i, 1, n + 1) {
        int w;
        cin >> p[i].first >> p[i].second >> w;
        swap(p[i].first, p[i].second);
        sum += w;
        dinic.add_edge(i, i + n, w);
        mp[p[i]] = i;
    }
    rep(i, 1, n + 1) {
        if(p[i].first % 2 == 0 && p[i].second % 2 == 0) {
            for(int x = 0; x <= 1; x++) {
                for(int y0 = 0; y0 <= 1; y0++) {
                    rep(y1, 0, 2) {
                        int idx1 = mp[{p[i].first + (x - 1), p[i].second + (y0 - 1)}];
                        int idx2 = mp[{p[i].first + (x - 1), p[i].second + y0}];
                        int idx3 = mp[{p[i].first + x, p[i].second + (y1 - 1)}];
                        int idx4 = mp[{p[i].first + x, p[i].second + y1}];
                        if(idx1 && idx2 && idx3 && idx4) {
                            vi vs = {idx1, idx2, idx3, idx4};
                            sort(all(vs), [](const int i, const int j) {
                                return gettype(i) < gettype(j);
                            });
//                            rep(i, 0, 4) assert(gettype(vs[i]) == i);
                            int la = ds;
                            for(int v : vs) {
                                dinic.add_edge(la, v, INF);
                                la = v + n;
                            }
                            dinic.add_edge(la, dt, INF);
                        }
                    }
                }
            }
        }
    }
    cout << sum - dinic.max_flow(ds, dt) << '\n';



}