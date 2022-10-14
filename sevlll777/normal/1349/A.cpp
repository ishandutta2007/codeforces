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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<bool> kekw(2e5+45, true);
    vector<int> lcd(2e5+45, 0);
    vector<int> pp;
    for (int x = 2; x < 2e5; x++) {
        if (kekw[x]) {
            pp.pb(x);
            lcd[x] = x;
        }
        for (auto p : pp) {
            if (p * x <= 2e5) {
                kekw[p * x] = false;
                lcd[p * x] = p;
            } else {
                break;
            }
        }
    }
    map<int, vector<int>> prims;
    for (auto x : A) {
        map<int, int> LOL;
        while (x != 1) {
            LOL[lcd[x]]++;
            x /= lcd[x];
        }
        for (auto p : LOL) {
            prims[p.first].pb(p.second);
        }
    }
    int ans = 1;
    for (auto p : prims) {
        sort(prims[p.first].begin(), prims[p.first].end());
        if (prims[p.first].size() == n) {
            for (int _ = 0; _ < prims[p.first][1]; _++) ans *= p.first;
        } else if (prims[p.first].size() == n - 1) {
            for (int _ = 0; _ < prims[p.first][0]; _++) ans *= p.first;
        }
    }
    cout << ans;


}