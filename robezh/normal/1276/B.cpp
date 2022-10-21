#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n, m;
vector<int> G[N];
int s[2];
int vis[N][2];
int cnt[2];

void dfs(int v, int tp) {
    cnt[tp]++;
    vis[v][tp] = 1;
    for(int nxt : G[v]) {
        if(nxt != s[tp] && !vis[nxt][tp]) dfs(nxt, tp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m >> s[0] >> s[1]; s[0]--, s[1]--;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i = 0; i < n; i++) vis[i][0] = vis[i][1] = 0;
        cnt[0] = cnt[1] = 0;
        dfs(s[0], 1);
        dfs(s[1], 0);
        ll res = 1LL * (n - cnt[0] - 1) * (n - cnt[1] - 1);
        cout << res << '\n';
    }

}