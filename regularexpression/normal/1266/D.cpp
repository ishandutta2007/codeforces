#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> bal(n, 0);
    while (m--) {
        int v, u, d;
        cin >> v >> u >> d;
        v--;
        u--;
        bal[v] -= d;
        bal[u] += d;
    }
    vector<int> pos, neg;
    for (int i = 0; i < n; ++i) {
        if (bal[i] < 0)
            neg.push_back(i);
        if (bal[i] > 0)
            pos.push_back(i);
    }
    vector<pair<pair<int, int>, int>> ans;
    int ptr = 0;
    for (int i = 0; i < pos.size(); ++i) {
        while (bal[pos[i]] > 0) {
            while (bal[neg[ptr]] == 0)
                ++ptr;
            int d = min(bal[pos[i]], -bal[neg[ptr]]);
            ans.push_back({{neg[ptr], pos[i]}, d});
            bal[neg[ptr]] += d;
            bal[pos[i]] -= d;
        }
    }
    cout << ans.size() << '\n';
    for (auto elem : ans) cout << elem.first.first + 1 << " " << elem.first.second + 1 << " " << elem.second << '\n';
    return 0;
}