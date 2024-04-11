#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int d[55], ma[55][55], po[55], st[55], en[55];
vector<pii> edges;
map<pii, int> edc;

const int INF = numeric_limits<int>::max() / 4;
typedef vector<int> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;

    MCMF(int N) :
        N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
        seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }

    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; ll di;

        __gnu_pbds::priority_queue<pair<int, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});

        auto relax = [&](int i, int cap, int cost, int dir) {
            int val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };

        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pi[s];
            trav(i, ed[s]) if (!seen[i])
                relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            trav(i, red[s]) if (!seen[i])
                relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
    }

    pair<int, int> maxflow(int s, int t) {
        int totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            int fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }

    // If some costs can be negative, call this before maxflow:
    void setpi(int s) { // (otherwise, leave this out)
        fill(all(pi), INF); pi[s] = 0;
        int it = N, ch = 1; ll v;
        while (ch-- && it--)
            rep(i,0,N) if (pi[i] != INF)
                trav(to, ed[i]) if (cap[i][to])
                    if ((v = pi[i] + cost[i][to]) < pi[to])
                        pi[to] = v, ch = 1;
        assert(it >= 0); // negative cost cycle
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ma[u][v] = 1;
        d[u]++;
    }
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(ma[i][j] + ma[j][i] > 0)
                continue;
            edc[{i, j}] = cur++;
            edges.push_back({i, j});
        }
    }
    MCMF mcmf(4000);
    int MI = 2700;
    int src = MI - 2, dst = MI - 1;
    mcmf.addEdge(src, 0, n*(n - 1)/2 - m, 0);
    cur = 1;
    for(int v = 1; v <= n; v++) {
        int pos = cur;
        st[v] = pos + 1;
        po[v] = cur;
        mcmf.addEdge(0, cur, n - 1, 0);
        for(int j = d[v]; j <= n - 2; j++)
            mcmf.addEdge(pos, ++cur, 1, 2*j + 1);
        en[v] = cur;
        cur++;
        for(int j = st[v]; j <= en[v]; j++)
            mcmf.addEdge(j, cur, 1, 0);
        for(auto e : edges) {
            if(e.first != v && e.second != v)
                continue;
            //cout << v << " " << e.first << " " << e.second << endl;
            mcmf.addEdge(cur, MI + edc[e], 1, 0);
        }
        cur++;
    }
    for(auto e : edges)
        mcmf.addEdge(MI + edc[e], dst, 1, 0);
    auto p = mcmf.maxflow(src, dst);
    for(int v = 1; v <= n; v++) {
        int p = en[v] + 1;
        for(auto e : edges) {
            if(mcmf.cap[p][MI + edc[e]] == 1 && mcmf.flow[p][MI + edc[e]] == 1)
                ma[v][e.first + e.second - v] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ma[i][j];
        }
        cout << '\n';
    }
}