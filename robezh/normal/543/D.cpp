#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500, mod = (int)1e9 + 7;
typedef long long ll;

int n,a;
vector<int> G[N];
ll dp[N];
ll res[N], pro[N];
bool vis[N];

void dfs(int v) {
    vis[v] = true;
    dp[v] = 1;
    vector<int> V;
    for (int nxt : G[v]) {
        if (!vis[nxt]) {
            dfs(nxt);
            V.push_back(nxt);
            pro[nxt] = dp[v];
            dp[v] *= (dp[nxt] + 1);
            dp[v] %= mod;
        }
    }
    reverse(V.begin(), V.end());
    ll p = 1;
    for (int nxt : V) {
        pro[nxt] *= p;
        p *= (dp[nxt] + 1);
        pro[nxt] %= mod, p %= mod;
    }
}
void dfs2(ll p0, int v) {
    vis[v] = true;
    p0 = (p0 + 1) % mod;
    for (int nxt : G[v]) {
        if (!vis[nxt]) {
            dfs2(pro[nxt] * p0 % mod, nxt);
        }
    }
    res[v] = p0 * dp[v] % mod;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a;
        a--;
        G[a].push_back(i);
        G[i].push_back(a);
    }
    fill(vis, vis+n, false);
    dfs(0);
    fill(vis, vis+n, false);
    dfs2(0, 0);

    for(int i = 0; i < n; i++) printf("%I64d ", res[i]);
}