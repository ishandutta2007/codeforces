#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, m, a[N], L[N], R[N], f[N];

void update(int x, int v) {
    for(; x < N; x += x & -x) f[x] = max(f[x], v);
}

int query(int x) {
    int r = 0;
    for(; x; x &= x - 1) r = max(r, f[x]);
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        a[x] ++, a[y+1] --;
    }
    a[0] = 1;
    for(int i = 1; i <= m; i ++) a[i] += a[i-1];
    for(int i = 1; i <= m; i ++) {
        L[i] = query(a[i]) + 1;
        update(a[i], L[i]);
    }
    memset(f, 0, sizeof f);
    for(int i = m; i; i --) {
        R[i] = query(a[i]) + 1;
        update(a[i], R[i]);
    }
    int ans = 0;
    for(int i = 1; i <= m; i ++) ans = max(ans, L[i]+R[i]-1);
    cout << ans << endl;
}