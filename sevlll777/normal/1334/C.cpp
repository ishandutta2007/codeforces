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
        int n;
        cin >> n;
        vector<pair<int, int>> mon(n);
        for (int i = 0; i < n; i++) cin >> mon[i].first >> mon[i].second;
        mon.pb(mon[0]);
        int ans = 0;
        for (int h = 1; h <= n; h++) {
            if (mon[h].first > mon[h-1].second) {
                ans += (mon[h].first - mon[h-1].second);
                mon[h].first = mon[h-1].second;
            }
        }
        int mim = 1e18;
        for (auto p : mon) {
            mim = min(mim, p.first);
        }
        ans += mim;
        cout << ans << '\n';
    }
}