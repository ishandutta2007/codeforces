#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50;

int n;
vector<int> G[N];
vector<int> ds[N];

void dfs(int v, int rt, int p, int d) {
    if(G[v].size() == 1) ds[rt].push_back(d);
    for(int nxt : G[v]) {
        if(nxt != p) dfs(nxt, rt, v, d + 1);
    }
}

int solve(vector<int> &V) {
    int mx = 0;
    sort(V.begin(), V.end());
    for(int x : V) mx = max(mx + 1, x);
    return mx;
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int res = 0;
    for(int nxt : G[0]) {
        dfs(nxt, nxt, 0, 1);
        res = max(res, solve(ds[nxt]));
    }
    cout << res << endl;

}