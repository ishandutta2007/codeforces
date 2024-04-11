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
    int to;
    ll cap;
    int rev;
    edge(int _to, ll _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

const ll INF = (ll)1e18 + 50;



// Finding max flow in O(V^2 * E)
struct Dinic {
    const static int N = (int)2e5 + 50;
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
            for(int i = 0; i < sz(G[v]); i++){
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


    ll max_flow(int s, int t) {
        ll flow = 0;
        for (;;) {
            bfs(s);
            if (level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            ll f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }

} dinic;

const int N = (int)1e5 + 50;
int xto[N], yto[N];
int cnt;
int n, q;
int s, t;
vector<pii> gin[N], gout[N];

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

int build_x(int x, int l, int r) {
    xto[x] = cnt++;
    if(l == r) {
        dinic.add_edge(s, xto[x], 1);
    } else {
        int mid = (l + r) / 2;
        dinic.add_edge(build_x(ls(x), l, mid), xto[x], INF);
        dinic.add_edge(build_x(rs(x), mid + 1, r), xto[x], INF);
    }
    return xto[x];
}

int build_y(int x, int l, int r) {
    yto[x] = cnt++;
    if(l == r) {
        dinic.add_edge(yto[x], t,1);
    } else {
        int mid = (l + r) / 2;
        dinic.add_edge(yto[x], build_y(ls(x), l, mid), INF);
        dinic.add_edge(yto[x], build_y(rs(x), mid + 1, r), INF);
    }
    return yto[x];
}

int la[N];
vi rg[2];

void make_range(int x, int l, int r, int a, int b, int idx) {
    if(a <= l && r <= b) {
        rg[idx].push_back(x);
        return ;
    }
    if(a > r || b < l) return ;
    int mid = (l + r) / 2;
    make_range(ls(x), l, mid, a, b, idx);
    make_range(rs(x), mid + 1, r, a, b, idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    s = 0, t = 1;
    cnt = 2;
    cin >> n >> q;
    gout[n].push_back({0, n});
    rep(i, 0, q) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; x1--, y1--, x2--;
        gout[x1].push_back({y1, y2});
        gin[x2 + 1].push_back({y1, y2});
    }
    build_x(0, 0, n - 1);
    build_y(0, 0, n - 1);

    fill(la, la + N, 0);
    rep(c, 0, n + 1) {
        for(auto &p : gin[c]) {
//            cout << p.first << " " << p.second << endl;
            fill(la + p.first, la + p.second, c);
        }
        for(auto &p : gout[c]) {
            int r = p.first;
            for(int i = p.first; i < p.second; i = r) {
                while(r < p.second && la[r] == la[i]) r++;
                rg[0].clear(); rg[1].clear();
                make_range(0, 0, n - 1, la[i], c - 1, 0);
                make_range(0, 0, n - 1, i, r - 1, 1);
                for(int xi : rg[0]) {
                    for(int yi : rg[1]) dinic.add_edge(xto[xi], yto[yi], INF);
                }
            }
        }
    }
    cout << dinic.max_flow(s, t) << '\n';
}