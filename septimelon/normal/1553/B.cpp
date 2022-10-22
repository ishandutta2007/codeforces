#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> status(n, -1); /// -1 - can't, 0 - right, 1 - left
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[0]) {
            status[i] = 0;
        }
    }

    for (int j = 1; j < m; ++j) {
        char c = t[j];
        vector<int> news(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == c && status[i + 1] >= 0) {
                news[i] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == c && status[i - 1] == 0) {
                news[i] = 0;
            }
        }
        status = move(news);
    }

    bool can{false};
    for (int i = 0; i < n; ++i) {
        if (status[i] >= 0) {
            can = true;
        }
    }

    can ? cout << "YES\n" : cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}