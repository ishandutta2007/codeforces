#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int maxi = -INF, mini = INF;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            maxi = max(maxi, a[i]);
            mini = min(mini, a[i]);
        }
        for (auto& i : a) i = maxi - i;
        maxi = maxi - mini;
        k--;
        if (k & 1) {
            for (int i = 0; i < n; ++i) a[i] = maxi - a[i];
        }
        for (auto i : a) cout << i << " ";
        cout << '\n';
    }
    return 0;
}