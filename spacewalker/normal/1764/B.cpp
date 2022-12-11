#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int &v : arr) cin >> v;
        int g = 0;
        for (int v : arr) g = gcd(g, v);
        int ans = 0;
        for (int v : arr) ans = max(ans, v/g);
        cout << ans << "\n";
    }
}