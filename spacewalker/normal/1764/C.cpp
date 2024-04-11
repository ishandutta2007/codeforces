#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int &v : arr) cin >> v;
        map<int, int> cts;
        for (int v : arr) ++cts[v];
        ll ans = 0;
        if (cts.size() == 1) { // edge case
            for (auto [e, c] : cts) ans += c/2;
        } else {
            vector<ll> comp;
            for (auto [e, c] : cts) comp.push_back(c);
            for (int i = 0; i + 1 < comp.size(); ++i) {
                comp[i+1] += comp[i];
            }
            for (int i = 0; i < comp.size(); ++i) {
                ans = max(ans, comp[i] * (n - comp[i]));
            }
        }
        cout << ans << "\n";
    }
}