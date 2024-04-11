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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<tuple<int, int, int>> kek;
        vector<int> ans(n+1);
        int x = 1;
        kek.push({n, -1, n});
        for (int _ = 0; _ < n; _++) {
            tuple<int, int, int> lol = kek.top();
            kek.pop();
            int len = get<0> (lol), l = -get<1> (lol), r = get<2> (lol);
            if (len % 2 == 1) {
                ans[(l + r) / 2] = x++;
                if (len > 1) {
                    kek.push({(l + r) / 2 - l, -l, (l + r) / 2 - 1});
                    kek.push({r - (l + r) / 2, -(l + r) / 2 - 1, r});
                }
            } else {
                ans[(l + r - 1) / 2] = x++;
                if (len > 0) {
                    kek.push({(l + r - 1) / 2 - l, -l, (l + r - 1) / 2 - 1});
                    kek.push({r - (l + r - 1) / 2, -(l + r - 1) / 2 - 1, r});
                }
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }


}