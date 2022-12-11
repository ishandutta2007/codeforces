#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v1, v2, c;
    explicit Edge(int v1 = 0, int v2 = 0, int c = 0): v1(v1), v2(v2), c(c) {}
};

void solve(int L = -1, int R = -1) {
    if (L == -1) cin >> L;
    if (R == -1) cin >> R;
    cout << "YES\n";

    if (L == R) {
        cout << "2 1\n1 2 " << R << "\n";
        return;
    }

    bool kek = false;
    if (L == 1) { kek = true; L = 2; }

    vector<Edge> ans;

    int X = R - L;
    int b = 20;

    while ((X & (1 << b)) == 0) b--;

    int k = b + 1;

    vector<pair<int, int>> divs = {{b, 1}};
    for (int i = b - 1; i >= 0; i--) {
        if ((X & (1 << i)) == 0) continue;
        if (divs.back().first - divs.back().second == i) divs.back().second++;
        else divs.emplace_back(i, 1);
    }

    int x = (int)divs.size() + 1;
    ans.emplace_back(x - 1, x + k, L);
    for (int i = 0; i < (int)divs.size(); i++) {
        int sum = (((1 << divs[i].second) - 1) << (divs[i].first - divs[i].second + 1));
        ans.emplace_back(i, i + 1, sum);

        int pos = x + k - 1 - divs[i].first;
        ans.emplace_back(i, pos, 1);

        int kek = 0;
        for (int j = 1; j < divs[i].second; j++) {
            kek += (1 << (divs[i].first - j + 1));
            pos++;
            ans.emplace_back(i, pos, kek + 1);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            ans.emplace_back(x + i, x + j, (1 << max(0, k - 1 - j)));
        }
        ans.emplace_back(x + i, x + k, L - 1);
    }
    if (kek) ans.emplace_back(0, x + k, 1);

    cout << x + k + 1 << " " << ans.size() << "\n";
    for (const auto &[v1, v2, c] : ans) cout << v1 + 1 << " " << v2 + 1 << " " << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef SERT
    solve(5, 32);
#else
    solve();
#endif
}