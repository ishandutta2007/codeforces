#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unrool-loops")
#pragma GCC optimize("no-stack-limit")

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
// #define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        if (k > m - 1) {
            k = m - 1;
        }
        int r = m - k - 1;
        int ans = 0;
        for (int f = 0; f <= k; f++) {
            int s = k - f;
            vector<int> B;
            for (int d = s; d < n - f; d++) {
                B.pb(A[d]);
            }
            int p = 1e9+1;
            for (int j = 0; j <= r; j++) {
                p = min(p, max(B[j], B[j + B.size() - r - 1]));
            }
            ans = max(ans, p);
        }
        cout << ans << '\n';
    }

}