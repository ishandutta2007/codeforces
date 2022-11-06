#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool ans = a[0] < a[n - 1];
        for (int i = 1; i + 1 < n; i++) ans |= a[i] > a[0] && a[i] < a[n - 1];
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}