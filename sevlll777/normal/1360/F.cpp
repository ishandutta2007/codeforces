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
        int n, m;
        cin >> n >> m;
        vector<string> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        string ans = "";
        for (auto s2 : A) {
            if (!ans.empty()) break;
            for (int pos = 0; pos < m; pos++) {
                if (!ans.empty()) break;
                for (char kek = 'a'; kek <= 'z'; kek++) {
                    string sos = s2;
                    sos[pos] = kek;
                    bool ok = true;
                    for (auto pp : A) {
                        int cnt = 0;
                        for (int j = 0; j < m; j++) {
                            cnt += (sos[j] != pp[j]);
                        }
                        if (cnt > 1) ok = false;
                    }
                    if (ok) {
                        ans = sos;
                        break;
                    }
                }
            }
        }
        if (ans.empty()) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }

    }
}