    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> ii;
     
    const int MAXN = 2e5 + 10;
    ii dp[MAXN], udp[MAXN];
    vector<int> adj[MAXN];
     
    void dfs(int s, int p = 0) {
        dp[s] = {0, s};
        for(auto v : adj[s]) {
            if(v == p)
                continue;
            dfs(v, s);
            if(dp[v].first + 1 > dp[s].first)
                dp[s] = {dp[v].first + 1, dp[v].second};
        }
        for(auto &v : adj[s])
            if(v == p)
                swap(v, adj[s][adj[s].size() - 1]);
    }
     
    void dfs2(int s, int p = 0) {
        int sz = adj[s].size();
        vector<ii> pmax(sz + 1 - (s != 1)), smax(sz + 1 - (s != 1));
        for(int i = 1; i <= sz - (s != 1); i++) {
            auto p = dp[adj[s][i - 1]];
            p.first++;
            pmax[i] = max(pmax[i - 1], p);
        }
        for(int i = sz - 1 - (s != 1); i >= 0; i--) {
            auto p = dp[adj[s][i]];
            p.first++;
            smax[i] = max(smax[i + 1], p);
        }
        if(sz - (s != 1) == 1) {
            if(s == 1)
                udp[adj[s][0]] = {1, 1};
            else {
                udp[adj[s][0]] = udp[s];
                udp[adj[s][0]].first++;
            }
        }
        else {
            for(int i = 1; i <= sz - (s != 1); i++) {
                if(s == 1) {
                    udp[adj[s][i - 1]] = max(pmax[i - 1], smax[i]);
                    udp[adj[s][i - 1]].first++;
                }
                else {
                    udp[adj[s][i - 1]] = max(pmax[i - 1], smax[i]);
                    udp[adj[s][i - 1]] = max(udp[adj[s][i - 1]], udp[s]);
                    udp[adj[s][i - 1]].first++;
                }
            }
        }
        for(auto v : adj[s]) {
            if(v != p)
                dfs2(v, s);
        }
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        dfs2(1);
        bool path = true;
        for(int i = 1; i <= n; i++)
            path &= (adj[i].size() < 3);
        if(path) {
            cout << n - 1 << '\n';
            for(int i = 1; i <= n; i++)
                if(adj[i].size() == 1)
                    cout << i << " ";
            for(int i = 1; i <= n; i++) {
                if(adj[i].size() != 1) {
                    cout << i << '\n';
                    break;
                }
            }
            return 0;
        }
        array<int, 4> ans;
        ans[0] = 0;
        for(int u = 1; u <= n; u++) {
            if(adj[u].size() < 3)
                continue;
            vector<ii> poss;
            for(int i = 0; i < adj[u].size() - (u != 1); i++) {
                auto p = dp[adj[u][i]];
                p.first++;
                poss.push_back(p);
            }
            if(u > 1)
                poss.push_back(udp[u]);
            sort(poss.begin(), poss.end(), greater<ii>());
            int d = poss[0].first + poss[1].first + poss[2].first;
            if(d > ans[0]) {
                ans[0] = d;
                ans[1] = poss[0].second;
                ans[2] = poss[1].second;
                ans[3] = poss[2].second;
            }
        }
        cout << ans[0] << '\n' << ans[1] << " " << ans[2] << " " << ans[3] << '\n';
    }