#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> H(n), W(n), ans(n, -2);
        set<array<int, 3>> p;
        for (int i = 0; i < n; i++) {
            cin >> H[i] >> W[i];
            if (H[i] > W[i]) {
                swap(H[i], W[i]);
            }
            p.insert({H[i], W[i], i});
        }
        int lasth = (*p.begin())[0];
        set<pair<int, int>> keku, kekw;
        for (auto tr : p) {
            if (lasth != tr[0]) {
                for (auto op : keku) {
                    kekw.insert(op);
                }
                keku = {};
            }
            if (!kekw.empty() && (*kekw.begin()).first < tr[1]) {
                ans[tr[2]] = (*kekw.begin()).second;
            }
            keku.insert({tr[1], tr[2]});
            lasth = tr[0];
        }
        for (auto x : ans) cout << x+1 << ' ';
        cout << '\n';
    }

}