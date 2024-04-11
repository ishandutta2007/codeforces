#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll g = 0;
        for (int i = 1; i < n; i++)
            g = gcd(g, a[i] - a[i - 1]);
        bool ans = false;
        for (int i = 0; i < n; i++)
            ans |= (a[i] - k) % g == 0;
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}