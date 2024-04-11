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
#define int long long
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
        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++) cin >> A[i];
        int sus = 0;
        for (auto x : A) {
            sus += x;
        }
        if (sus % n) {
            cout << "-1\n";
        } else {
            int Y = sus / n;
            vector<int> B(n + 1);
            for (int i = 1; i <= n; i++) {
                B[i] = (i - (A[i] % i)) % i;
            }
            vector<tuple<int, int, int>> ans;
            for (int i = 2; i<= n; i++) {
                ans.pb({1, i, B[i]});
                A[1] -= B[i];
                A[i] += B[i];
                ans.pb({i, 1, A[i] / i});
                A[1] += A[i];
                A[i] = 0;
            }
            for (int i = 2; i <= n; i++) {
                ans.pb({1, i, Y});
            }
            cout << ans.size() << '\n';
            for (auto p : ans) {
                cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
            }
        }
    }

}