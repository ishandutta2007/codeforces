#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, mod = (int)1e9 + 7;

struct edge {
    int to, c;
};

int n, m;
vector<edge> G[N];
int fval[N];
bool vis[N];

void dfs(int v, int val) {
    fval[v] = val;
    vis[v] = true;
    for(const auto &e : G[v]) {
        if(vis[e.to]) {
            if(fval[e.to] != val ^ (!e.c)) {
                cout << "0" << endl;
                exit(0);
            }
        }
        else {
            dfs(e.to, val ^ (!e.c));
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, 0);
        }
    }
    int res = 1;
    for(int i = 0; i < cnt - 1; i++) res *= 2, res %= mod;
    cout << res << endl;
}