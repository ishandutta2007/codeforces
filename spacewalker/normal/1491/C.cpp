#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve() {
    int n; scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    ll ans = 0;
    vector<ll> passesThrough(n);
    for (int i = 0; i < n; ++i) {
        ll passesToPush = passesThrough[i];
        if (passesToPush < arr[i] - 1) {
            ans += (arr[i] - 1) - passesToPush;
            passesToPush = arr[i] - 1;
        }
        ll target = i + arr[i];
        if (target >= n) {
            passesToPush -= (target - n + 1);
            target = n - 1;
        }
        for (; target > i + 1; --target) {
            ++passesThrough[target];
            --passesToPush;
        }
        if (i + 1 < n) passesThrough[i + 1] += passesToPush;
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%lld\n", solve());
    return 0;
}