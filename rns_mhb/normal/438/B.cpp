#include <bits/stdc++.h>
using namespace std;
#define N 100010

int n, m, a[N], id[N], rt[N], hz[N];
vector <int> adj[N];

bool cmp(int i, int j) {
    if (a[i] == a[j]) return i < j;
    return a[i] > a[j];
}

void link(int x, int y) {
    rt[x] = y;
    hz[y] += hz[x];
}

int find_rt(int x) {
    return rt[x] == x ? x : rt[x] = find_rt(rt[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), id[i] = rt[i] = i, hz[i] = 1;
    sort(id + 1, id + n + 1, cmp);
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (cmp(x, y)) swap(x, y);
        adj[x].push_back(y);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        int sz = adj[id[i]].size();
        int sum = 0;
        for (int j = 0; j < sz; j ++) {
            int k = find_rt(adj[id[i]][j]);
            if (k == id[i]) continue;
            ans += 1ll * hz[k] * sum * a[id[i]];
            sum += hz[k], ans += 1ll * hz[k] * a[id[i]];
            link(k, id[i]);
        }
    }
    printf("%.6lf\n", 2.0 * ans / n / (n - 1));

    return 0;
}