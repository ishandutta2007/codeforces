#include <bits/stdc++.h>

#define int int64_t

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int v[n], t[n];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mn = 0;
    multiset<int> lols;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        lols.insert(v[i] + mn);
        ans = 0;
        while(!lols.empty() && *begin(lols) - mn <= t[i]) {
            auto it = begin(lols);
            ans += *it - mn;
            lols.erase(it);
        }
        mn += t[i];
        ans += 1LL * lols.size() * t[i];
        cout << ans << ' ';
    }
    
    return 0;
}