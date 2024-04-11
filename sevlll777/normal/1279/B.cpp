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
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> P = {0}, M = {0}, I = {0};
        for (int i = 0; i < n; i++) {
            P.pb(A[i] + P.back());
            if (M.back() < A[i]) {
                M.pb(A[i]);
                I.pb(i + 1);
            } else {
                M.pb(M.back());
                I.pb(I.back());
            }
        }
        if (P.back() <= s) {
            cout << "0\n";
        } else {
            pii ans = {0, 0};
            for (int i = 1; i <= n; i++) {
                if (P[i] - M[i] <= s) {
                    ans = max(ans, {i - 1, I[i]});
                }
                if (P[i] <= s) {
                    ans = max(ans, {i, n});
                }
            }
            cout << ans.second << '\n';
        }

    }
}