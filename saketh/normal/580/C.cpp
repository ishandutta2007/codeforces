#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

int N, M;
bool cat[MAXN];
vector<int> adj[MAXN];

int ans = 0;

void solve(int loc = 0, int par = 0, int cur = 0, int lng = 0) {
    if (cat[loc]) cur++;
    else cur = 0;
    lng = max(lng, cur);

    if (adj[loc].size() == 1 && loc!=par && lng <= M) ans++;

    for (int nbr : adj[loc]) {
        if(nbr == par) continue;
        solve(nbr, loc, cur, lng);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> cat[i];
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    solve();
    cout << ans << endl;
}