#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<int> C(n);
        int f = 0;
        for (int i = 0; i < n; i++) cin >> C[i];
        for (int i = 0; i < n; i++) {
            if (C[i] >= (w + 1) / 2 && C[i] <= w) {
                f = 1;
                cout << "1\n" << i + 1;
                break;
            }
        }
        if (!f) {
            vector<pair<int, int>> X;
            for (int i = 0; i < n; i++) X.pb({C[i], i});
            sort(X.begin(), X.end());
            int s = 0;
            for (int i = 0; i < n; i++) {
                s += X[i].first;
                if (f == 0 && s <= w && s >= (w + 1) / 2) {
                    cout << i + 1 << '\n';
                    for (int j = 0; j <= i; j++) cout << X[j].second + 1 << ' ';
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            cout << "-1";
        }
        cout << '\n';
    }
}