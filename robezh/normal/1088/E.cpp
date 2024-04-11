#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;
const ll INF = (ll)1e18;

int n;
int a[N];
vector<int> G[N];
ll res = -INF, cnt = 0;

bool vis[N];

ll dfs(int v, int p) {
    ll sum = a[v];
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        sum += max(0LL, dfs(nxt, v));
    }
    if(sum > res) res = sum, cnt = 0;
    if(sum == res) cnt ++;
    return sum;
}

int tcnt = 0;

ll dfs2(int v, int p) {
    ll sum = a[v];
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        sum += max(0LL, dfs2(nxt, v));
    }
    if(sum == res) {
        tcnt ++;
        return 0;
    }
    else return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1);
    cout << res * tcnt << " " << tcnt << endl;
}