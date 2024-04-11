#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        vector<int> compress = a;
        sort(all(compress));
        compress.resize(unique(all(compress)) - compress.begin());
        for (auto& i : a) i = lower_bound(all(compress), i) - compress.begin();
        vector<int> cnt(compress.size());
        for (auto i : a) cnt[i]++;
        sort(all(cnt));
        vector<int> pref = cnt;
        n = compress.size();
        for (int i = 1; i < n; ++i) {
            pref[i] += pref[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            chkmin(ans, (i > 0 ? pref[i - 1] : 0) + (i + 1 < n ? pref.back() - pref[i] - (n - i - 1) * cnt[i] : 0));
        }
        cout << ans << '\n';
    }
    return 0;
}