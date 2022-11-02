#include<bits/stdc++.h>
using namespace std;

#define N 100010

int u[N], v[N], w[N];
vector <int> a[N], f[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> u[i] >> v[i] >> w[i];
        a[u[i]].push_back(w[i]);
        a[v[i]].push_back(w[i]);
    }
    for(int i = 1; i <= n; i ++) {
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        f[i].resize(a[i].size()+1);
        for(int j = 0; j < f[i].size(); j ++) f[i][j] = 0;
    }
    for(int i = 1; i <= m; i ++) {
        int x = u[i], y = v[i];
        int ix = lower_bound(a[x].begin(), a[x].end(), w[i])-a[x].begin()+1;
        int iy = lower_bound(a[y].begin(), a[y].end(), w[i])-a[y].begin()+1;
        int vx = 0;
        for(int j = ix-1; j; j &= j-1) vx = max(vx, f[x][j]);
        for(int j = iy; j < f[y].size(); j += j & -j) f[y][j] = max(f[y][j], vx+1);
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) for(int j = f[i].size()-1; j; j &= j-1) ans = max(ans, f[i][j]);
    cout << ans << endl;
}