#include<bits/stdc++.h>
using namespace std;

#define N 300010

vector <int> adj[N];
bool vis[N];
int d[N], f[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector <int> ans, v;
    v.push_back(1);
    vis[1] = 1, d[1] = 0;
    for(int i = 0; i < v.size(); i ++) {
        int x = v[i];
        for(int j = 0; j < adj[x].size(); j ++) {
            int y = adj[x][j];
            if(vis[y]) continue;
            vis[y] = 1;
            d[y] = d[x] + 1;
            f[y] = x;
            v.push_back(y);
        }
    }
    if(vis[n]) {
        for(int x = n; x; x = f[x]) ans.push_back(x);
        reverse(ans.begin(), ans.end());
    }
    for(int i = 1; i <= n; i ++) if(d[i] == 2) {
        vector <int> cur = {1, f[i], i, 1, n};
        if(ans.size() == 0 || cur.size() < ans.size()) ans = cur;
        printf("%d\n", ans.size()-1);
        for(int j = 0; j < ans.size(); j ++) printf("%d ", ans[j]);
        puts("");
        return 0;
    }
    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);
    sort(adj[1].begin(), adj[1].end(), [&](int i, int j){return adj[i].size() < adj[j].size();});
    vis[1] = 1;
    for(int i = 0; i < adj[1].size(); i ++) {
        int x = adj[1][i];
        if(vis[x]) continue;
        vis[x] = 1;
        for(int j = 0; j < adj[x].size(); j ++) vis[adj[x][j]] = 1;
        for(int j = 0; j < adj[x].size(); j ++) {
            int y = adj[x][j];
            if(y == 1) continue;
            for(int k = 0; k < adj[y].size(); k ++) {
                int z = adj[y][k];
                if(vis[z] == 0) {
                    vector <int> cur;
                    cur = {1, x, y, z, x, n};
                    if(ans.size() == 0 || cur.size() < ans.size()) ans = cur;
                    printf("%d\n", ans.size()-1);
                    for(int h = 0; h < ans.size(); h ++) printf("%d ", ans[h]);
                    puts("");
                    return 0;
                }
            }
        }
    }
    if(ans.size() == 0) {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans.size()-1);
    for(int i = 0; i < ans.size(); i ++) printf("%d ", ans[i]);
    puts("");
}