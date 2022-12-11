#include <bits/stdc++.h>
using namespace std;

bool D = false;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    vector<vector<int>> es(n);
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        int mn = -1;
        for (int j = 0; j < n; j++) {
            if (r[j] > r[i] && (mn == -1 || r[j] < r[mn]) &&
                r[j] + 1e-9 > r[i] + sqrtl((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])))
                mn = j;
        }
        if (mn == -1)
            roots.push_back(i);
        else
            es[mn].push_back(i);
    }

    vector<pair<ll, ll>> dp11(n), dp00(n), dp10(n);
    long long ans = 0;

    auto add = [](pair<ll, ll> &a, const pair<ll, ll> &b) { a.first += b.first; a.second += b.second; };

    function<void(int)> dfs = [&](int v) {
        if (es[v].empty()) {
            dp11[v] = dp10[v] = dp00[v] = {r[v] * r[v], 0};
            return;
        }
        pair<ll, ll> sum11, sum10, sum00;
        for (int w : es[v]) {
            dfs(w);
            add(sum11, dp11[w]);
            add(sum10, dp10[w]);
            add(sum00, dp00[w]);
        }
        ll my = r[v] * r[v];
        dp11[v] = make_pair(sum10.first, my - sum10.second);
        dp00[v] = make_pair(my - sum10.first, sum10.second);

        auto a10 = make_pair(my - sum00.first, sum00.second);
        auto b10 = make_pair(sum11.first, my - sum11.second);
        dp10[v] = (a10.first - a10.second > b10.first - b10.second ? a10 : b10);
    };

    for (int root : roots) {
        dfs(root);
        ans += dp11[root].first + dp11[root].second;
    }
    cout << setprecision(15) << fixed << ans * atan2l(0, -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
#ifdef SERT
    freopen("../a.in", "r", stdin);
    D = true;
    t = 2;
#endif
    while (t--)
        solve();
}