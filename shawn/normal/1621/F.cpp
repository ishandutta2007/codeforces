#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        LL a, b, c;
        cin >> n >> a >> b >> c >> s;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i += 1) {
            if (not vp.empty() and vp.back().first == s[i] - '0')
                vp.back().second += 1;
            else vp.emplace_back(s[i] - '0', 1);
        }
        vector<int> v;
        for (int i = 0; i + 2 < vp.size(); i += 1)
            if (vp[i].first == 1) v.push_back(vp[i + 1].second);
        ranges::sort(v);
        for (int i = 1; i < v.size(); i += 1) v[i] += v[i - 1];
        int cnt[2][2]{};
        for (int i = 0; i + 1 < n; i += 1) if (s[i] == s[i + 1]) cnt[0][s[i] - '0'] += 1;
        cnt[1][1] = max((int)ranges::count(s, '1') - 1, 0);
        cnt[1][0] = ranges::count(s, '0');
        LL ans = 0;
        for (int i = 0; i <= cnt[1][1]; i += 1)
            for (int j = max(i - 1, 0); j <= min(i + 1, cnt[1][0]); j += 1) {
                int x = max(i - cnt[0][1], 0);
                if (x and v[x - 1] > min(i, j)) continue;
                ans = max(ans, b * i + a * min(j - x, cnt[0][0]) + -c * (max(j - x - cnt[0][0], 0) + x));
            }
        cout << ans << "\n";
    }
    return 0;
}