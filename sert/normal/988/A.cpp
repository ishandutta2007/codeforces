//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    a.push_back({INF, -1});

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i].first != a[i + 1].first) {
            ans.push_back(a[i].second);
        }
    }

    if ((int)ans.size() < k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < k; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    solve();
    solve();
#endif
    solve();
    return 0;
}