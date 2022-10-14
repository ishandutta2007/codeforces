// #define _GLIBCXX_DEBUG
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
#define str string
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
        int ans = 0;
        if (k % 2 == 1) {
            map<char, int> cnt;
            for (int i = k / 2; i < n; i += k) {
                cnt[s[i]]++;
            }
            int mx = 0;
            for (auto p : cnt) mx = max(mx, p.second);
            ans += (n / k) - mx;
        }
        for (int s1 = 0; s1 < k / 2; s1++) {
            map<char, int> cnt;
            for (int i = s1; i < n; i += k) {
                cnt[s[i]]++;
            }
            for (int i = k - s1 - 1; i < n; i += k) {
                cnt[s[i]]++;
            }
            int mx = 0;
            for (auto p : cnt) mx = max(mx, p.second);
            ans += 2 * (n / k) - mx;
        }
        cout << ans << '\n';

    }
}