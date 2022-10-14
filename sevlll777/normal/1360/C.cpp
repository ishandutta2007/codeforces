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
        vector<int> A(n), E, O;
        int ev = 0, od = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            if (A[i] % 2 == 0) {
                E.pb(A[i]);
                ev++;
            } else {
                O.pb(A[i]);
                od++;
            }
        }
        if (ev % 2 == 0 && od % 2 == 0) {
            cout << "YES\n";
        } else {
            string ans = "NO\n";
            for (auto p : E) {
                for (auto pp : O) {
                    if (abs(p - pp) == 1) {
                        ans = "YES\n";
                    }
                }
            }
            cout << ans;
        }


    }
}