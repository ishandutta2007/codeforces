#include<bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cnt[sum]++;
    }
    int ans = n - 1;
    for (auto [key, val] : cnt) ans = min(ans, n - val);
    cout << ans;
    return 0;
}