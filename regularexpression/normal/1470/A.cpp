#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        --k[i];
    }
    vector<ll> c(m);
    for (int i = 0; i < m; ++i)
        cin >> c[i];

    sort(k.begin(), k.end());
    int l = 0, r = min(n, m) + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        bool ok = true;
        for (int i = 0; i < mid; ++i)
            ok &= i <= k[n - i - 1];

        if (ok)
            l = mid;
        else
            r = mid;
    }

    ll answer = 0ll;
    for (int i = 0; i < l; ++i)
        answer += c[i];
    for (int i = 0; i < n - l; ++i)
        answer += c[k[i]];

    cout << answer << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}