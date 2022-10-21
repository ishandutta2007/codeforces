#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n;
vector<int> nG[N], G[N];
int sub[N], dep[N];
int par[N];
int dep_now, root;

int sdfs(int v, int p, int d) {
    dep[v] = d;
    par[v] = p;
    for(int nxt : nG[v]) {
        if(nxt == p) continue;
        sdfs(nxt, v, d + 1);
        G[v].push_back(nxt);
    }
}

int dis(int x) {
    cout << "d " << x + 1 << endl;
    fflush(stdout);
    int res; cin >> res;
    return res;
}

int next(int x) {
    cout << "s " << x + 1 << endl;
    fflush(stdout);
    int res; cin >> res;
    return res - 1;
}

void dfs(int v) {
    if(dep_now == dep[v]) {
        sub[v] = 1;
        return ;
    }
    sub[v] = 0;
    for(int &nxt : G[v]) {
        dfs(nxt);
        sub[v] += sub[nxt];
        if(sub[nxt] > sub[G[v][0]]) swap(nxt, G[v][0]);
    }
}

void answer(int v) {
    cout << "! " << v + 1 << endl;
    fflush(stdout);
    exit(0);
}
int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        nG[u].push_back(v);
        nG[v].push_back(u);
    }
    sdfs(0, -1, 0);
    root = 0;
    int d = dis(root);
    dep_now = d;
    dfs(0);
    for(int i = 0; i < 36; i++) {
        int cur = root, pa = -1;
        while(!G[cur].empty() && 2 * sub[G[cur][0]] >= sub[root]) {
            pa = cur;
            cur = G[cur][0];
        }
        if(dep[cur] + dis(cur) != d) {
            G[pa].erase(G[pa].begin());
            dfs(root);
        }
        else {
            if(dep[cur] == d) answer(cur);
            root = next(cur);
        }
    }
    assert(false);

}