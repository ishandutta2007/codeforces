#define __GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int long long
#define dbl long double
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++) cin >> A[i];
        vector<vector<int>> prefs(201, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int c = 1; c <= 200; c++) {
                if (c == A[i]) {
                    prefs[c][i] = prefs[c][i - 1] + 1;
                } else {
                    prefs[c][i] = prefs[c][i - 1];
                }
            }
        }
        int ans = 1;
        for (int c = 1; c <= 200; c++) {
            vector<int> B;
            for (int i = 1; i <= n; i++) {
                if (A[i] == c) {
                    B.pb(i);
                }
            }
            for (int S = 1; S <= B.size() / 2; S++) {
                int x1 = B[S-1] + 1;
                int x2 = B[B.size() - S] - 1;
                for (int cc = 1; cc <= 200; cc++) {
                    if (x2+1 > x1-1) {
                        ans = max(ans, 2 * S + prefs[cc][x2] - prefs[cc][x1 - 1]);
                    }
                }
                if (x2+1>x1-1) {
                    ans=max(ans,2*S);
                }
            }

        }
        cout << min(ans,n) << '\n';

    }
}