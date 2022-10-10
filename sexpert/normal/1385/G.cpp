#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<vector<ii>> adj;
vector<int> mark, seen, used;
vector<ii> cyc;

void dfs(int s) {
    seen[s] = 1;
    for(auto e : adj[s]) {
        int v = e.first;
        if(v == s) {
            cyc.push_back({s, e.second});
            return;
        }
        if(used[e.second])
            continue;
        cyc.push_back({s, e.second});
        used[e.second] = 1;
        if(!seen[v])
            dfs(v);
    }
} 

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1), ps(n + 1);
    adj.resize(n + 1);
    mark.assign(n + 1, 0);
    seen.assign(n + 1, 0);
    used.assign(n + 1, 0);
    for(int i = 1; i <= n; i++)
        adj[i].clear();
    
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        ps[x] ^= 1;
        a[i] = x;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        ps[x] ^= 2;
        adj[x].push_back({a[i], i});
        adj[a[i]].push_back({x, i});
    }
    for(int i = 1; i <= n; i++) {
        if(cnt[i] != 2) {
            cout << "-1\n";
            return;
        }
        if(ps[i] == 0)
            mark[i] = 1;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(seen[i])
            continue;
        cyc.clear();
        dfs(i);
        int open = 0;
        vector<int> opt1, opt2;
        for(int j = 0; j < cyc.size(); j++) {
            int s = cyc[j].first, id = cyc[j].second;
            if(mark[s])
                open ^= 1;
            if(open)
                opt1.push_back(id);
            else
                opt2.push_back(id);
        }
        if(opt1.size() <= opt2.size())
            for(auto id : opt1)
                ans.push_back(id);
        else
            for(auto id : opt2)
                ans.push_back(id);
    }
    cout << ans.size() << '\n';
    for(auto id : ans)
        cout << id << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}