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
// #define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        bool heh = true;
        for (int i = 0; i < n - 1; i++) {
            if (!heh) break;
            for (int j = 0; j < n - 1; j++) {
                if (A[i][j] == '1') {
                    if (A[i + 1][j] == '0' && A[i][j + 1] == '0') {
                        heh = false;
                        break;
                    }
                }
            }
        }
        if (heh) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}