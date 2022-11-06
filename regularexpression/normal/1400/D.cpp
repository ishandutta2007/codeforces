#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        vector<vector<int>> cnt(n, vector<int>(n, 0));
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) ++cnt[a[i]][a[j]];
            int k = i - 1;
            for (int j = k - 1; j >= 0; --j) ans += cnt[a[j]][a[k]];
        }
        cout << ans << '\n';
    }
    return 0;
}