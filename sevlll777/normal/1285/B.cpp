#pragma GCC optimize("unroll-loops")

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
#define int long long
#define pii pair<int, int>
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        int pref = 0;
        int suf = 0;
        str ans = "YES";
        for (int i = 0; i < n - 1; i++) {
            pref += A[i];
            if (pref <= 0) {
                ans = "NO";
            }
        }
        for (int i = n - 1; i > 0; i--) {
            suf += A[i];
            if (suf <= 0) {
                ans = "NO";
            }
        }
        cout << ans + '\n';
    }
}