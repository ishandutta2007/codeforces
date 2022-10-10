#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int> b;
        for (auto kv: cnt) {
            if (kv.second >= k) {
                b.push_back(kv.first);
            }
        }
        if (b.size() == 0) {
            cout << "-1\n";
            continue;
        }
        vector<pair<int, int>> gr;
        for (int i = 0; i < b.size(); i++) {
            if (gr.size() > 0 && gr.back().first + gr.back().second == b[i]) {
                gr.back().second++;
            } else {
                gr.push_back({b[i], 1});
            }
        }
        int ans = 0;
        for (int i = 1; i < gr.size(); i++) {
            if (gr[ans].second < gr[i].second) {
                ans = i;
            }
        }
        cout << gr[ans].first << ' ' << gr[ans].first + gr[ans].second - 1 << '\n';
    }
}