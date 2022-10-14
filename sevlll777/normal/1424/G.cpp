#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> evs;
    for (int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        evs.emplace_back(b, 1);
        evs.emplace_back(d, -1);
    }
    sort(evs.begin(), evs.end());
    pair<int, int> res = {0, -1};
    int cnt = 0;
    for (auto pp : evs) {
        int x = pp.first, t = pp.second;
        if (t == -1) {
            cnt--;
        } else {
            cnt++;
            res = max(res, make_pair(cnt, -x));
        }
    }
    cout << -res.second << " " << res.first << '\n';
}