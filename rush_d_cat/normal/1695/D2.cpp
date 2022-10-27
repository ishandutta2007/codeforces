#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 200000 + 10;
vector<int> g[N];
int n, isleaf[N];
void dfs(int u, int p) {
    int son = 0;
    for (auto v: g[u]) {
        if (v == p) continue;
        son ++;
    }
    if (son == 0) {
        isleaf[u] = 1; return;
    }
    for (auto v: g[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (son == 1 and isleaf[v]) {
            isleaf[u] = 1;
        }        
        
    }
}
int ans = 0;
void dfs2(int u, int p) {
    int tmp = 0;
    for (auto v: g[u]) {
        if (v == p) continue;

        if (isleaf[v]) {
            if (u == 1) {
               // cout << "!" << v << "\n";
            }
            tmp ++;
        } else {
            dfs2(v, u);
        }
    }
    if (!isleaf[u] and tmp >= 1) {
        //cout << "u = " << u << " tmp = " << tmp << "\n";
        ans += tmp - 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) g[i].clear();
        for (int i = 1; i < n; i ++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (n == 1) {
            cout << 0 << "\n"; continue;
        } 
        int mx = 0, rt = 0;
        for (int i = 1; i <= n; i ++) {
            if (g[i].size() > mx) {
                mx = g[i].size(); rt = i;
            }
        }

        if (g[rt].size() <= 2) {
            cout << 1 << "\n"; continue;
        }
        //cout << "Rt = " << rt << "\n";
        for (int i = 1; i <= n; i ++) isleaf[i] = 0;
        ans = 0;
        dfs(rt, rt);
        for (int i = 1; i <= n; i ++) {
            //cout << i << " " << isleaf[i] << "\n";
        }

        dfs2(rt, rt);
        cout << ans << "\n";
    }
}