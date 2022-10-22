#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    int l = 0;
    int cur = n;
    int r = n;
    int ans = 0;
    for (cur = n - 1; cur >= l; --cur) {
        if (cur + e[cur] == r) {
            r = cur;
            ++ans;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    return 0;
}