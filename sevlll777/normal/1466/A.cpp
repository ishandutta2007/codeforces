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
        set<int> k;
        for (auto x : X) {
            for (auto y : X) {
                k.insert(abs(x-y));
            }
        }
        cout << k.size()-1;
        cout << '\n';
    }
}