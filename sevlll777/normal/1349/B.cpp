// #pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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
        int n, k;
        cin >> n >> k;
        vector<int> A(n+1);
        for (int i = 1; i <= n; i++) cin >> A[i];
        int cnt = 0;
        bool kekw = false;
        for (int i = 1; i <= n; i++) {
            if (A[i] == k) cnt++;
        }
        if (cnt == n) {
            cout << "yes\n";
        } else if (cnt == 0) {
            cout << "no\n";
        } else {
            string ans = "no\n";
            for (int i = 1; i < n; i++) {
                if (A[i] >= k && A[i+1] >= k) {
                    ans = "yes\n";
                    break;
                }
            }
            for (int i = 1; i < n-1; i++) {
                int c = 0;
                c += (A[i] >= k) + (A[i+1] >= k) + (A[i+2] >= k);
                if (c >= 2) {
                    ans = "yes\n";
                    break;
                }
            }
            cout << ans;
        }

    }


}