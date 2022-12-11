#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> arr(n);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll a, b; scanf("%lld %lld", &a, &b);
            if (a < b) swap(a, b); // WLOG a >= b
            arr[i] = a;
            ans += 2 * (a + b);
        }
        sort(begin(arr), end(arr));
        for (int i = 0; i + 1 < n; ++i) {
            ans -= 2 * min(arr[i], arr[i+1]);
        }
        printf("%lld\n", ans);
    }
}