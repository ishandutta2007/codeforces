#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const long long INF = 1e18;

long long base[4 * MAXN], st[4 * MAXN], lazy[4 * MAXN];

void build(int p, int l, int r, const vector<long long> &a) {
    if (l == r) {
        base[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m, a);
    build(2 * p + 1, m + 1, r, a);
    base[p] = max(base[2*p], base[2*p+1]);
}

void push(int p, bool leaf) {
    st[p] = max(st[p], base[p] + lazy[p]);
    if (!leaf) {
        lazy[2*p] = max(lazy[2*p], lazy[p]);
        lazy[2*p+1] = max(lazy[2*p+1], lazy[p]);
    }
    lazy[p] = -INF;
}

long long query(int p, int l, int r, int i, int j) {
    push(p, l == r);
    if (i > r || j < l)
        return -INF;
    if (i <= l && r <= j)
        return st[p];
    int m = (l + r) / 2;
    return max(query(2 * p, l, m, i, j), query(2 * p + 1, m + 1, r, i, j));
}

void update(int p, int l, int r, int i, int j, long long v) {
    push(p, l == r);
    if (i > r || j < l)
        return;
    if (i <= l && r <= j) {
        lazy[p] = v;
        push(p, l == r);
        return;
    }
    int m = (l + r) / 2;
    update(2 * p, l, m, i, j, v);
    update(2 * p + 1, m + 1, r, i, j, v);
    st[p] = max(st[2*p], st[2*p+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(3, vector<int>(n + 1));
    for (int i=0; i<3; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    vector<vector<pair<int, int>>> intervals(n + 1);
    for (int i=0; i<q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        intervals[r].emplace_back(l, k);
    }
    
    vector<long long> pref(n + 1), sum(n + 1), suff(n + 2);
    for (int i=1; i<=n; i++) {
        pref[i] = a[0][i] + pref[i-1];
        sum[i] = a[1][i] + sum[i-1];
    }
    for (int i=n; i>0; i--)
        suff[i] = a[2][i] + suff[i+1];
    
    memset(st, 0xc0, sizeof(st));
    memset(lazy, 0xc0, sizeof(lazy));
    vector<long long> dp(n + 1, -INF);
    for (int i=1; i<=n; i++) {
        update(1, 1, n, i, i, max(dp[i-1], pref[i]) - sum[i-1]);
        for (auto [l, k] : intervals[i])
            dp[i] = max(dp[i], query(1, 1, n, l, i) + sum[i] - k);
    }
    
    vector<long long> it(n + 1);
    for (int i=1; i<=n; i++)
        it[i] = max(dp[i-1], pref[i]) - sum[i-1];
    
    memset(st, 0xc0, sizeof(st));
    memset(lazy, 0xc0, sizeof(lazy));
    build(1, 1, n, it);
    long long ret = -INF;
    for (int i=1; i<=n; i++) {
        update(1, 1, n, 1, i, sum[i] + suff[i]);
        for (auto [l, k] : intervals[i])
            ret = max(ret, query(1, 1, n, l, i) - k);
    }
    cout << ret << "\n";
    
    return 0;
}