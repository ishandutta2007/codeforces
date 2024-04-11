#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
    register char c = getchar();
    register int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return x * f;
}

vector <pair <int, int> > ans;
int n, fa[105], dis[105][105];
char mp[105][105][105];
bool vis[105];
bitset <105> tmp[105][105];
vector <int> g[105];

inline void Read() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) cin >> mp[i][j] + 1;
    }
}

inline void Dfs(int u, int fa, int rt) {
    for (int x : g[u]) {
        if (x != fa) {
            dis[rt][x] = dis[rt][u] + 1;
            Dfs(x, u, rt);
        }
    }
}

inline void Solve() {
    ans.clear();
    for (int i = 2;i <= n;i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1;j <= n;j++) g[j].clear();
        ans.clear();
        queue <int> que;
        que.push(1);
        que.push(i);
        fa[1] = i; fa[i] = 1;
        vis[1] = vis[i] = 1;
        bool ok = 1;
        while (!que.empty()) {
            int u = que.front();
            if (u > 1) {
                ans.push_back(make_pair(fa[u], u));
                g[fa[u]].push_back(u);
                g[u].push_back(fa[u]);
            }
            que.pop();
            for (int i = 1;i <= n;i++) {
                if (mp[min(fa[u], i)][max(fa[u], i)][u] - '0' && i != fa[u]) {
                    if (vis[i]) {
                        ok = 0;
                        break;
                    }
                    vis[i] = 1;
                    fa[i] = u;
                    que.push(i);
                }
            }
        }
        if (ans.size() < n - 1) ok = 0;
        if (!ok) continue;
        for (int i = 1;i <= n;i++) {
            dis[i][i] = 0;
            Dfs(i, -1, i);
        }
        for (int i = 1;i <= n;i++) {
            for (int j = i + 1;j <= n;j++) {
                for (int k = 1;k <= n;k++) {
                    if ((dis[i][k] == dis[j][k]) != (mp[i][j][k] - '0')) {
                        ok = 0;
                        goto done;
                    }
                }
            }
        }
        done:;
        if (ok) {
            cout << "Yes\n";
            for (pair <int, int> x : ans) cout << x.first << " " << x.second << endl;
            return;
        }
    }
    cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        Read();
        Solve();
    }
    return 0;
}