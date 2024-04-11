#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
int disA[MAXN], disB[MAXN];
vector<int> adj[MAXN];

void dfs(int s, int* dis, int p = 0, int d = 0) {
    dis[s] = d;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, dis, s, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, disA);
    dfs(x, disB);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(disB[i] < disA[i])
            ans = max(ans, 2*disA[i]);
    }
    cout << ans << endl;
}