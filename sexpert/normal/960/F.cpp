#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 5;
set<ii> dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        dp[i].insert({-1, 0});
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        auto ins = --dp[u].upper_bound({w, -1});
        auto ers = --dp[v].upper_bound({w + 1, -1});
        int tot = ins->second + 1;
        if(ers->second > tot)
            continue;

        ++ers;
        while(ers != dp[v].end() && ers->second <= tot) {
            //cout << "kill " << ers->first << " " << ers->second << " from " << v << endl;
            ers = dp[v].erase(ers);
        }

        dp[v].insert({w, tot});
        //cout << "add " << w << " " << tot << " to " << v << endl;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        auto it = --dp[i].end();
        ans = max(ans, it->second);
    }
    cout << ans << '\n';
}