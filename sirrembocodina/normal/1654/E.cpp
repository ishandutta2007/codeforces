#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int K = 1000;
        int KK = 100100 / K;
        unordered_map<pair<int, int>, int, my_hash> cnt;
        for (int i = 0; i < n; i++) {
            vector<int> ks;
            for (int j = max(i - K, 0ll); j < min(i + K + 1, n); j++) {
                if (i == j) {
                    continue;
                }
                if (abs(a[i] - a[j]) % abs(i - j)) {
                    continue;
                }
                int k = (a[i] - a[j]) / (i - j);
                if (abs(k) <= KK) {
                    continue;
                }
                ks.push_back(k);
            }
            sort(ks.begin(), ks.end());
            for (int j = 0; j < ks.size(); j++) {
                if (j > 0 && ks[j] == ks[j - 1]) {
                    continue;
                }
                int k = ks[j];
                cnt[{k, a[i] - k * i}]++;
            }
        }
        int ans = 1;
        for (auto kv: cnt) {
            ans = max(ans, kv.second);
        }
        cnt.clear();
        for (int k = -KK; k <= KK; k++) {
            vector<int> asdf;
            for (int i = 0; i < n; i++) {
                asdf.push_back(a[i] - k * i);
            }
            sort(asdf.begin(), asdf.end());
            int mx = 0;
            int cur = 0;
            for (int j = 0; j < asdf.size(); j++) {
                if (j == 0 || asdf[j - 1] != asdf[j]) {
                    cur = 1;
                } else {
                    cur++;
                }
                mx = max(mx, cur);
            }
            ans = max(mx, ans);
        }
        cout << n - ans << '\n';
    }
    return 0;
}