#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
const int N = (int)4e5 + 50;

struct edge {
    int to, id;
};

struct edge_r {
    int u, v, id;
};

int n, m;
vector<edge> G[N];
set<int> nG[N];
int low[N], pre[N];
int ccnt = 0;
bool vis[N];
int cmp[N], sz[N];
stack<int> S;
int cnt = 0;
vector<edge_r> res;

void dfs(int v, int id) {
    pre[v] = low[v] = ++cnt;
    S.push(v);
    for(int j = 0; j < G[v].size(); j++) {
        edge e = G[v][j];
        if(e.id == id) continue;
        if(pre[e.to] == 0) {
            dfs(e.to, e.id);
            low[v] = min(low[v], low[e.to]);
        }
        else low[v] = min(low[v], pre[e.to]);
    }

    if(pre[v] == low[v]) {
        int cur;
        do {
            cur = S.top(); S.pop();
            cmp[cur] = ccnt;
            sz[ccnt] ++;
        } while(cur != v);
        ccnt++;
    }
}

void dfs2(int v, int out) {
    for(auto e : G[v]) {
        if(vis[e.id]) continue;
        vis[e.id] = true;
        int nxt_out = (cmp[e.to] != cmp[v] || out);
        res.push_back({e.to, v, e.id});
//        else res.push_back({v, e.to, e.id});
        dfs2(e.to, nxt_out);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    dfs(0, -1);
    int mxi = 0;
    for(int i = 0; i < ccnt; i++) {
        if(sz[i] > sz[mxi]) mxi = i;
    }
    int mx_sz = sz[mxi];
    int st = 0;
    for(int i = 0; i < n; i++) {
        if(cmp[i] == mxi) {
            st = i;
            break;
        }
    }
    dfs2(st, -1);
    cout << mx_sz << "\n";
    sort(res.begin(), res.end(), [](const edge_r &e1, const edge_r &e2) {
        return e1.id < e2.id;
    });
    for(auto p : res) cout << p.u + 1 << " " << p.v + 1 << "\n";
    assert(res.size() == m);


}