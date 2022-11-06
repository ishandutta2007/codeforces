#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        multiset<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.insert(x);
        }
        while (k--) {
            auto it1 = a.begin();
            auto it2 = prev(b.end());
            if (*it1 >= *it2) break;
            int bb = *it1;
            int aa = *it2;
            a.erase(it1);
            b.erase(it2);
            a.insert(aa);
            b.insert(bb);
        }
        int ans = 0;
        for (auto x : a) ans += x;
        cout << ans << '\n';
    }
    return 0;
}