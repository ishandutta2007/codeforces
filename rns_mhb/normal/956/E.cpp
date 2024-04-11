#include<bits/stdc++.h>
using namespace std;

#define N 10010

int f[N], g[N];
pair <int, int> a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i ++) cin >> a[i].second;
    for(int i = 1; i <= n; i ++) cin >> a[i].first, a[i].first *= -1;
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    int m = 0;
    for(int i = 1; i <= n; i ++) m += a[i].second;
    for(int i = 0; i <= m; i ++) f[i] = g[i] = -(1e9);
    f[0] = 0;
    for(int i = 1, s = 0; i <= n; i ++) {
        s += a[i].second;
        for(int j = 0; j <= s; j ++) {
            g[j] = f[j];
            if(a[i].first && l <= (m-s+j) && (m-s+j) <= r) g[j] ++;
        }
        for(int j = a[i].second; j <= s; j ++) {
            g[j] = max(g[j], f[j-a[i].second]);
            if(a[i].first && l <= (j-a[i].second) && (j-a[i].second) <= r) g[j] = max(g[j], f[j-a[i].second]+1);
        }
        swap(f, g);
    }
    int ans = 0;
    for(int i = 0; i <= m; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
}