#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5 + 7;

int ind[4 * N], a[N], dp[N];

int f(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return a[x] > a[y] ? x : y;
}

void build(int v, int tl, int tr) {
    if (tr - tl == 1) ind[v] = tl; else {
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid, tr);
        ind[v] = f(ind[2 * v], ind[2 * v + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) return -1;
    if (tl >= l && tr <= r) return ind[v];
    int mid = (tl + tr) / 2;
    return f(query(2 * v, tl, mid, l, r), query(2 * v + 1, mid, tr, l, r));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n--;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    //return 0;
    build(1, 0, n);
    //return 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int to = a[i] == n ? n : query(1, 0, n, i + 1, a[i] + 1);
        dp[i] = dp[to] + n - a[i] + to - i;
        //cout << "to = " << to << " " << "dp = " << dp[i] << endl;
    }
    for (int i = 0; i < n; i++) ans += dp[i];
    cout << ans;
    return 0;
}