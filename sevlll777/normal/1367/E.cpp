#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (auto c : s) cnt[c - 'a']++;
        int ans = 0;
        vector<int> kek;
        for (int h = 1; h * h <= k; h++) {
            if (k % h == 0) {
                kek.pb(h);
                kek.pb(k / h);
            }
        }
        for (auto k_ : kek) {
            int l = 0;
            int r = 1e9;
            while (r - l > 1) {
                int m = (l + r) / 2;
                int g = 0;
                for (auto x : cnt) {
                    g += x / m;
                }
                if (g >= k_) {
                    l = m;
                } else {
                    r = m;
                }
            }
            ans = max(ans, l * k_);
        }
        cout << ans << '\n';
    }
}