#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int n, m;

ll p[sz];

vector <int> g[sz];

int dis[3][sz], s[3];

void bfs(int id)
{
    int b = s[id];
    for(int i=1; i<=n; i++) dis[id][i] = sz;
    dis[id][b] = 0;
    queue <int> q;
    q.push(b);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(dis[id][v] ^ sz) continue;
            dis[id][v] = dis[id][u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i=0; i<3; i++) scanf("%d", &s[i]);
        for(int i=1; i<=n; i++) g[i].clear();

        for(int i=1; i<=m; i++) scanf("%lld", &p[i]);
        for(int i=1; i<=m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i=0; i<3; i++) bfs(i);

        sort(p+1, p+m+1);
        for(int i=1; i<=m; i++) p[i] += p[i-1];

        ll ans = 1e18;
        for(int i=1; i<=n; i++) {
            int x = dis[0][i], y = dis[2][i];
            int z = dis[1][i];
            int tot = x + y + z;

            if(tot > m) continue;

            ll now = p[z] << 1;
            now += p[tot] - p[z];

            ans = min(ans, now);
        }

        printf("%lld\n", ans);
    }
}