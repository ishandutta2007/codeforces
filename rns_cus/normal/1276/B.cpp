#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n, m, a, b, rt[N], vis[N], x[N], y[N];
vector <int> vec[N];

int cnt[N];

int find_rt(int u) {
    return rt[u] == u ? u : rt[u] = find_rt(rt[u]);
}

void link(int u, int v) {
    u = find_rt(u), v = find_rt(v);
    if (u != v) rt[u] = v;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        typedef long long ll;
        for (int i = 1; i <= n; i ++) rt[i] = i, cnt[i] = 0, vec[i].clear();
        for (int i = 0; i < m; i ++) {
            int u, v;
            scanf("%d %d", &u, &v); x[i] = u, y[i] = v;
            if (u != a && v != a) link(u, v);
        }
        ll rlt = 1ll * (n - 2) * (n - 3) / 2;
        for (int i = 1; i <= n; i ++) if (i != a && i != b) vis[i] = find_rt(i), rlt -= cnt[vis[i]], cnt[vis[i]] ++;
        for (int i = 1; i <= n; i ++) rt[i] = i;
        for (int i = 0; i < m; i ++) {
            if (x[i] != b && y[i] != b) link(x[i], y[i]);
        }
        for (int i = 1; i <= n; i ++) if (i != a && i != b) vec[find_rt(i)].push_back(i);
        for (int i = 1; i <= n; i ++) cnt[i] = 0;
        for (int i = 1; i <= n; i ++) {
            int sz = vec[i].size();
            rlt -= 1ll * sz * (sz - 1) / 2;
            for (int j = 0; j < sz; j ++) {
                int u = vis[vec[i][j]];
                rlt += cnt[u];
                cnt[u] ++;
            }
            for (int j = 0; j < sz; j ++) cnt[vis[vec[i][j]]] = 0;
        }
        printf("%I64d\n", rlt);
    }

    return 0;
}