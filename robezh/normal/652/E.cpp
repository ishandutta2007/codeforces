#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;

struct edge {
    int to;
    int art;
};

int n, m;
vector<edge> G[N], cG[N];
int low[N], pre[N];
int ccnt = 0;
int fs, ft;
int cmp[N], arti[N];
stack<int> S;
int cnt = 0;

void dfs(int v, int p) {
    pre[v] = low[v] = ++cnt;
    S.push(v);
    for(auto e : G[v]) {
        if(e.to == p) continue;
        if(pre[e.to] == 0) {
            dfs(e.to, v);
            low[v] = min(low[v], low[e.to]);
        }
        else low[v] = min(low[v], pre[e.to]);
    }
    
    if(pre[v] == low[v]) {
        int cur;
        do {
            cur = S.top(); S.pop();
            cmp[cur] = ccnt;
        } while(cur != v);
        ccnt++;
    }
}

int res = 0;
void find(int v, int p, int have) {
    have |= arti[v];
    if(cmp[ft] == v) res |= have;
    for(auto e : cG[v]) {
        if(e.to != p) find(e.to, v, have | e.art);
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    cin >> fs >> ft;
    fs--, ft--;
    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        for(auto e : G[i]) {
            if(cmp[i] != cmp[e.to]) cG[cmp[i]].push_back({cmp[e.to], e.art});
            else if(e.art) arti[cmp[i]] = 1;
        }
    }
    find(cmp[fs], -1, 0);
    cout << (res ? "YES" : "NO") << endl;


}