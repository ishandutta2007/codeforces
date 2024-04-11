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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            A[i]--;
        }
        int on_pref[n][n];
        int on_suf[n][n];
        for (int el = 0; el < n; el++) {
            if (el == A[0]) {
                on_pref[0][el] = 1;
            } else {
                on_pref[0][el] = 0;
            }
            if (el == A[n - 1]) {
                on_suf[n - 1][el] = 1;
            } else {
                on_suf[n - 1][el] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int el = 0; el < n; el++) {
                on_pref[i][el] = on_pref[i - 1][el];
                if (A[i] == el) on_pref[i][el]++;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int el = 0; el < n; el++) {
                on_suf[i][el] = on_suf[i + 1][el];
                if (A[i] == el) on_suf[i][el]++;
            }
        }
        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            for (int k = j+1; k < n-1; k++) {
                ans += on_pref[j - 1][A[k]] * on_suf[k + 1][A[j]];
            }
        }
        cout << ans << '\n';
    }
}