#include <bits/stdc++.h>
using namespace std;

int animal[50][20000], pref[50][20000], dp[50][20000], st[80000], lazy[80000];

void push(int p, int l, int r) {
    if (lazy[p]) {
        st[p] += lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int i, int j, int val) {
    push(p, l, r);
    if (i > r || j < l)
        return;
    if (i <= l && r <= j) {
        st[p] += val;
        if (l != r) {
            lazy[2*p] += val;
            lazy[2*p+1] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update(2*p, l, m, i, j, val);
    update(2*p+1, m+1, r, i, j, val);
    st[p] = max(st[2*p], st[2*p+1]);
}

int query(int i, int j, int k) {
    return pref[i][k] - (j > 0 ? pref[i][j-1] : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> animal[i][j];
            pref[i][j] = (j > 0 ? pref[i][j-1] : 0) + animal[i][j];
        }

    for (int j=0; j<=m-k; j++)
        dp[0][j] = query(0, j, j + k - 1) + query(1, j, j + k - 1);
    for (int i=1; i<n; i++) {
        memset(st, 0, sizeof(st));
        memset(lazy, 0, sizeof(lazy));
        for (int j=0; j<=m-k; j++)
            update(1, 0, m-k, j, j, dp[i-1][j]);
        for (int j=0; j<k; j++)
            update(1, 0, m-k, 0, j, -animal[i][j]);
        for (int j=0; j<=m-k; j++) {
            dp[i][j] = st[1] + query(i, j, j + k - 1) + (i < n - 1 ? query(i + 1, j, j + k - 1) : 0);
            if (j < m - k) {
                update(1, 0, m-k, max(0, j-k+1), j, animal[i][j]);
                update(1, 0, m-k, j+1, min(m-k, j+k), -animal[i][j+k]);
            }
        }
    }

    cout << *max_element(dp[n-1], dp[n-1] + m - k + 1) << "\n";

    return 0;
}