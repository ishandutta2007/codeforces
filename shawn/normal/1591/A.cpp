#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, die = 0;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        for (int i = 1; i < n; i += 1)
            if (not a[i] and not a[i - 1]) die = 1;
        if (die) {
            cout << "-1\n";
            continue;
        }
        int ans = 1;
        for (int i = 0; i < n; i += 1) if (a[i]) {
            ans += 1;
            if (i and a[i - 1]) ans += 4;
        }
        cout << ans << "\n";
    }
    return 0;
}