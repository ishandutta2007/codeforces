#include <bits/stdc++.h>

using namespace std;

const int NN = 2e5 + 10;
vector<int> adj[NN];

int sum, cnt;

int dfs(int u, int fa = 0) {
    int son = 0;
    for(int i = 0; i < adj[u].size(); i ++) {
        int v = adj[u][i];
        if(v == fa) continue;
        if(!dfs(v, u)) son ++;;
    }
    if(son && u != 1) {
        sum += son;
        cnt ++;
    }
    return son;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T; cin >> T;
    while(T --) {
        int n; scanf("%d", &n);
        for(int i = 1; i < n; i ++) {
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cnt = 0, sum = 0;
        int root = dfs(1);
        int ans = 0;
        if(root) {
            ans += root;
            if(cnt) ans --;
        }
        ans += sum;
        if(cnt) ans -= cnt - 1;
        printf("%d\n", ans);
        for(int i = 1; i <= n; i ++) adj[i].clear();
    }
    return 0;
}