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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t0;
    cin >> t0;
    while (t0--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> cnt(n + 2), B(n);
        for (int i = 0; i < n; i++) {
            cin >> B[i];
            cnt[B[i]]++;
        }
        vector<int> YLIVE(n + 2);
        int sh = 1;
        while (cnt[sh]) sh++;
        int shuffled = n - x;
        int need = y - x;
        int base = shuffled - (1 + need) / 2;
        for (int d = 1; d <= 1 + n; d++) {
            int taked = min({shuffled, base, cnt[d]});
            YLIVE[d] = cnt[d] - taked;
            shuffled -= taked;
        }
        if (shuffled) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> ans(n + 1);
        vector<pair<int, int>> need_rotate;
        for (int i = 0; i < n; i++) {
            if (YLIVE[B[i]] > 0) {
                YLIVE[B[i]]--;
                ans[i] = B[i];
            } else {
                ans[i] = sh;
                need_rotate.pb({B[i], i});
            }
        }
        sort(need_rotate.begin(), need_rotate.end());
        vector<int> V;
        for (auto p : need_rotate) V.pb(p.first);
        for (int i = 0; i < V.size(); i++) {
            if (need_rotate[i].first != V[(i + (n - x) / 2) % V.size()] && need) {
                ans[need_rotate[i].second] = V[(i + (n - x) / 2) % V.size()];
                need--;
            }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

}