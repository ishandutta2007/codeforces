#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        for (int i = n - 1, j = a.back(); i >= 0; i -= 1)
            if (a[i] > j) {
                ans += 1;
                j = a[i];
            }
        cout << ans << "\n";
    }
    return 0;
}