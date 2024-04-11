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
        int n;
        cin >> n;
        vector<int> X(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        sort(X.begin(), X.end());
        set<int> kek = {X[0]};
        for (int i = 1; i < n; i++) {
            if (kek.find(X[i]) != kek.end()) {
                kek.insert(X[i] + 1);
            } else {
                kek.insert(X[i]);
            }
        }
        cout << kek.size();
        cout << '\n';
    }
}