#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    vector<int> f(s.size() + 1);
    for (int i = 1; i < s.size(); i++) {
        int cand = f[i];
        while (cand > 0 && s[cand] != s[i]) {
            cand = f[cand];
        }
        if (s[cand] != s[i]) {
            f[i + 1] = 0;
        } else {
            f[i + 1] = cand + 1;
        }
    }
    vector<int> sz(s.size() + 1, 1);
    for (int i = s.size(); i > 0; i--) {
        sz[f[i]] += sz[i];
    }
    vector<pair<int, int>> ans;
    int cand = s.size();
    while (cand > 0) {
        ans.push_back({cand, sz[cand]});
        cand = f[cand];
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto elem: ans) {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}