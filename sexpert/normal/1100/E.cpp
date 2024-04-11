    #include <bits/stdc++.h>
    using namespace std;
    typedef pair<int, int> ii;
     
    const int MAXN = 1e5 + 5;
    multiset<ii> out[MAXN], into[MAXN], wt;
    map<pair<ii, int>, vector<int>> conv;
     
    int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            conv[make_pair(ii{u, v}, w)].push_back(i);
            out[u].insert({-w, v});
            into[v].insert({-w, u});
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            if(out[i].empty()) {
                wt.insert({0, i});
                continue;
            }
            ii p = *out[i].begin();
            wt.insert({-p.first, i});
        }
        vector<pair<ii, int>> ans;
        while(!wt.empty()) {
            ii p = *wt.begin();
            wt.erase(wt.begin());
            int u = p.second;
            mx = max(mx, p.first);
            for(auto e : out[u]) {
                into[e.second].erase(into[e.second].find({e.first, u}));
                ans.emplace_back(ii{u, e.second}, -e.first);
            }
            for(auto e : into[u]) {
                int v = e.second;
                ii p = *out[v].begin();
                wt.erase(wt.find({-p.first, v}));
                out[v].erase(out[v].find({e.first, u}));
                if(out[v].empty()) {
                    wt.insert({0, v});
                    continue;
                }
                p = *out[v].begin();
                wt.insert({-p.first, v});
            }
        }
        cout << mx << " " << ans.size() << endl;
        for(auto p : ans) {
            cout << conv[p].back() << " ";
            conv[p].pop_back();
        }
        cout << endl;
    }