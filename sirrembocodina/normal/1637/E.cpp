#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct pair_hash {
    inline size_t operator()(const pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};

bool cmp(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - a.second) > abs(b.first - b.second);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        set<int> cnts;
        for (auto kv: cnt) {
            cnts.insert(kv.second);
        }
        vector<int> unmap;
        map<int, int> mapping;
        for (int x: cnts) {
            mapping[x] = unmap.size();
            unmap.push_back(x);
        }
        vector<vector<int>> gr(unmap.size());
        for (auto kv: cnt) {
            gr[mapping[kv.second]].push_back(kv.first);
        }
        unordered_set<pair<int, int>, pair_hash> bad;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            bad.insert({x, y});
            bad.insert({y, x});
        }
        int ans = -2e18;
        for (auto kv: cnt) {
            int x = kv.first;
            for (int i = 0; i < gr.size(); i++) {
                int cur = int(gr[i].size()) - 1;
                while (cur >= 0 && (gr[i][cur] == x || bad.find({gr[i][cur], x}) != bad.end())) {
                    cur--;
                }
                if (cur >= 0) {
                    int y = gr[i][cur];
                    ans = max(ans, (x + y) * (kv.second + unmap[i]));
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}