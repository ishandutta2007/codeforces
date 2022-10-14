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
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t0;
    cin >> t0;
    while (t0--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> ans;
        int gg = n * n;
        for (int _ = 0; _ < n*n+1; _++) {
            for (int i = 0; i < n - 2; i++) {
                int m = min({A[i], A[i + 1], A[i + 2]});
                while (A[i] != m && gg) {
                    int kek = A[i];
                    A[i] = A[i + 2];
                    A[i + 2] = A[i + 1];
                    A[i + 1] = kek;
                    ans.pb(i + 1);
                    gg--;
                }
            }
            for (int i = n - 3; i >= 0; i--) {
                int m = max({A[i], A[i + 1], A[i + 2]});
                while (A[i+2] != m && gg) {
                    int kek = A[i];
                    A[i] = A[i + 2];
                    A[i + 2] = A[i + 1];
                    A[i + 1] = kek;
                    ans.pb(i + 1);
                    gg--;
                }
            }
        }
        vector<int> B = A;
        sort(B.begin(), B.end());
        if (A == B) {
            cout << ans.size() << '\n';
            for (auto x : ans) cout << x << ' ';
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

}