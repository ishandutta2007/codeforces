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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

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
        int l = 0;
        for (auto c : s) l += (c == 'L');
        if (l <= k) {
            cout << n + n - 1;
        } else if (l == n) {
            cout << max(0LL, k + k - 1);
        } else {
            int ans = 2 * (n - l + k);
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'W' && s[i + 1] == 'L') ans--;
            }
            if (s[n - 1] == 'W') ans--;
            int g = 0;
            vector<int> kek;
            bool wasf = false;
            if (s[0] == 'W') wasf = true;
            for (int i = 1; i < n; i++) {
                if (s[i] == 'L' && s[i - 1] == 'W') {
                    g = 1;
                } else if (s[i] == 'L') {
                    if (wasf) g++;
                } else {
                    wasf = true;
                    if (g) {
                        kek.pb(g);
                    }
                    g = 0;
                }
            }
            sort(kek.begin(), kek.end());
            for (auto c : kek) {
                if (k >= c) {
                    k -= c;
                    ans++;
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
}