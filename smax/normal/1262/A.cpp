#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, L = INT_MAX, R = INT_MIN;
        cin >> n;
        for (int i=0; i<n; i++) {
            int l, r;
            cin >> l >> r;
            L = min(L, r);
            R = max(R, l);
        }
        cout << max(R - L, 0) << "\n";
    }

    return 0;
}