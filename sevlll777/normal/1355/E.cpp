#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, r, m;
    cin >> n >> a >> r >> m;
    int S = 0;
    vector <pair<int, int>> H(n);
    vector<int> H2;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        S += h;
        H[i] = {h, 0};
        H2.pb(h);
    }
    sort(H2.begin(), H2.end());
    H.pb({S / n, 1});
    if ((S + n - 1) / n >= 0) {
        H.pb({(S + n - 1) / n, 1});
    }
    sort(H.begin(), H.end());
    int cnt_lower = 0;
    int cnt_higher = n;
    int sum_lower = 0;
    int sum_higher = S;
    int last = 0;
    int ans = 1e18;
    for (auto P : H) {
        int x = P.first, lolw = P.second;
        sum_lower += (x - last) * cnt_lower;
        cnt_lower += (1 - lolw);
        sum_higher -= (cnt_higher) * (x - last);
        cnt_higher -= (1 - lolw);
        last = x;
        ans = min({ans, a * sum_lower + r * sum_higher,
                   m * min(sum_lower, sum_higher) + a * (sum_lower - min(sum_lower, sum_higher)) +
                   r * (sum_higher - min(sum_lower, sum_higher))});
    }
    cout << ans;


}