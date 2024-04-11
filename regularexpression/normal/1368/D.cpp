#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cnt(25, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < 25; j++) {
            if ((a >> j) & 1)
                cnt[j]++;
        }
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < 25; i++) {
        pref[0] += (1LL << i);
        pref[cnt[i]] -= (1LL << i);
    }
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += pref[i];
        ans += cur * cur;
    }
    cout << ans;
    return 0;
}