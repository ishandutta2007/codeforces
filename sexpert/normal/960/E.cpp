#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll col[MAXN], sz0[MAXN], sz1[MAXN];
ll val[MAXN], ans;
vector<int> adj[MAXN];

void dfs(int s, int p = 0, int c = 0) {
    col[s] = c;
    sz0[s] = (c == 0);
    sz1[s] = (c == 1);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s, 1 - c);
        sz0[s] += sz0[v];
        sz1[s] += sz1[v];
    }
}

void calc(int s, int p = 0) {
    //cout << s << " " << sz0[s] << " " << sz1[s] << endl;
    ll sum0 = 0, sum1 = 0;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        sum0 += sz0[v];
        sum1 += sz1[v];
    }
    ll ex0 = sz0[1] - sum0 - (col[s] == 0), ex1 = sz1[1] - sum1 - (col[s] == 1);
    ll pos = 0, neg = 0;
    if(col[s] == 0) {
        pos = sz0[1]*sz0[1];
        neg = sz1[1]*sz1[1];
        for(auto v : adj[s]) {
            if(v == p)
                continue;
            pos -= sz0[v] * sz0[v];
            neg -= sz1[v] * sz1[v];
        }
        pos -= ex0 * ex0;
        neg -= ex1 * ex1;
    }    
    else {
        pos = sz1[1]*sz1[1];
        neg = sz0[1]*sz0[1];
        for(auto v : adj[s]) {
            if(v == p)
                continue;
            pos -= sz1[v] * sz1[v];
            neg -= sz0[v] * sz0[v];
        }
        pos -= ex1 * ex1;
        neg -= ex0 * ex0;
    }
    //cout << s << " " << pos << " " << neg << endl;
    pos %= MOD;
    neg %= MOD;
    ans = (ans + pos * val[s]) % MOD;
    ans = (ans - neg * val[s]) % MOD;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        calc(v, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    calc(1);
    if(ans < 0)
        ans += MOD;
    cout << ans << '\n';
}