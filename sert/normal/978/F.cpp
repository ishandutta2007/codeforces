//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;

void solve() {
    int n, k, v1, v2;
    cin >> n >> k;
    vector<int> ans(n, 0);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < k; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        if (a[v1].first > a[v2].first) ans[v1]--;
        if (a[v2].first > a[v1].first) ans[v2]--;
    }
    sort(a.begin(), a.end());
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first != a[i - 1].first) {
            cur = i;
        }
        ans[a[i].second] += cur;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
#endif
    solve();
    return 0;
}