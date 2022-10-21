#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50, INF = (int)1e9;

int n, x;
int a[N];
int mx[N], mn[N];
int suf_rmn[N];
bool vis[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    fill(mx, mx + x + 1, -INF);
    fill(mn, mn + x + 1, INF);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = true;
        mx[a[i]] = max(mx[a[i]], i);
        mn[a[i]] = min(mn[a[i]], i);
    }
    n = x;
    int l = 1, lmx = mx[1];
    while(l + 1 <= n && (!vis[l+1] || lmx < mn[l+1])) {
        if(vis[l+1]) lmx = mx[l+1];
        l++;
    }
    int r = n, rmn = mn[n];
    suf_rmn[n] = rmn;
    while(r - 1 >= 1 && (!vis[r-1] || mx[r-1] < rmn)) {
        if(vis[r-1]) rmn = mn[r-1];
        r--;
        suf_rmn[r] = rmn;
    }

    if(l == n) return cout << 1LL * n * (n+1) / 2 << endl, 0;
    int nr = r;
    ll res = (n + 1) - r + 1;
    lmx = -INF;
    for(int i = 1; i <= l; i++) {
        if(vis[i]) lmx = mx[i];
        while(nr <= n && suf_rmn[nr] < lmx) nr++;
        res += (n + 1) - nr + 1;
    }
    cout << res << endl;
}