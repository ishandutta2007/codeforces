#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<ll> arr) {
    int n = arr.size();
    sort(begin(arr), end(arr));
    ll ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        ans = max(ans, arr[n-1] + arr[i+1] - 2 * arr[i]);
    }
    for (int i = 2; i < n; ++i) {
        ans = max(ans, 2 * arr[i] - arr[i-1] - arr[0]);
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<ll> arr(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }
        printf("%lld\n", solve(arr));
    }
}