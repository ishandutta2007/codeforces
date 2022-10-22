#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> sp(n, vector<pii>());
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        r = n - r;
        --c;
        sp[r].push_back({c, i});
    }

    priority_queue<pii> spo;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sp[i].size(); ++j) {
            spo.push({INF - sp[i][j].first, sp[i][j].second});
        }
        while (!spo.empty() && INF - spo.top().first < i) {
            spo.pop();
        }
        if (!spo.empty()) {
            ans.push_back(spo.top().second + 1);
            spo.pop();
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}