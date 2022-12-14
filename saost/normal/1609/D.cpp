#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
int n, q, res, d[N], cnt[N*4], sum[N*4];

int DD(int u) {
    if (d[u] < 0) return u;
    return d[u] = DD(d[u]);
}

void update(int x, int val, int l = 1, int r = n, int pos = 1) {
    cnt[pos] += val;
    sum[pos] += x * val;
    if (l == r) return;
    int mid = (l+r) / 2;
    if (x <= mid) update(x, val, l, mid, pos*2);
    else update(x, val, mid+1, r, pos*2+1);
}

int query(int &all, int l = 1, int r = n, int pos = 1) {
    if (all <= 0) return 0;
    if (all >= cnt[pos]) {
        all -= cnt[pos];
        return sum[pos];
    }
    if (l == r) {
        int ans = sum[pos] / cnt[pos] * all;
        all = 0;
        return ans;
    }
    int mid = (l+r) / 2;
    int vx = query(all, mid+1, r, pos*2+1);
    int vy = query(all, l, mid, pos*2);
    return vx + vy;
}

void Union(int u, int v) {
    if (d[u] > d[v]) swap(u, v);
    update(-d[u], -1);
    update(-d[v], -1);
    d[u] += d[v];
    d[v] = u;
    update(-d[u], 1);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) d[i] = -1, update(1, 1);
    int u, v, ALL = 1;
    while (q--) {
        cin >> u >> v;
        u = DD(u), v = DD(v);
        if (u != v) Union(u, v);
        else ++ALL;
        int a2 = ALL;
        cout << query(a2) - 1 << '\n';
    }
}