#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

struct qry {
    int k, id;
};

int n, q;
vector<int> G[N];
int S[N], sz = 0;
vector<qry> qr[N], nqr[N];
map<int, int> mp[N];
int idx[N];
int res[N], dep[N];

int unite(int i, int j) {
    if(mp[i].size() > mp[j].size()) swap(i, j);
    for(auto p : mp[i]) mp[j][p.first] += p.second;
    return j;
}
void dfs(int v, int d) {
    S[sz++] = v;
    dep[v] = d;
    mp[v][d] ++;
    for(int nxt : G[v]) {
        dfs(nxt, d + 1);
        idx[v] = unite(idx[v], idx[nxt]);
    }
    for(auto qy : nqr[v]) {
        res[qy.id] = mp[idx[v]][dep[qy.k]] - 1;
    }
    for(auto qy : qr[v]) {
        if(sz - 1 - qy.k >= 0) nqr[S[sz - 1 - qy.k]].push_back({v, qy.id});
        else res[qy.id] = 0;
    }
    sz--;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> rts;
    for(int i = 0; i < n; i++) {
        int v; cin >> v; v--;
        if(v != -1) G[v].push_back(i);
        else rts.push_back(i);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        int v, p; cin >> v >> p; v--;
        qr[v].push_back({p, i});
    }
    for(int i = 0; i < n; i++) idx[i] = i;
    for(int rt : rts) dfs(rt, -1);
    for(int i = 0; i < q; i++) cout << res[i] << " ";
}