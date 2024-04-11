#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 34;
int n, m, x, a[N], sf[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sf[n] = 2e9;
    for (int i = n - 1; i >= 0; i--)
        sf[i] = min(a[i], sf[i + 1]);

    int mx = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (mx <= sf[i + 1]) {
            ans++;
            mx = -1;
        }
    }
    cout << ans;
}