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
    int n, c;
    cin >> n >> c;
    vector<int> A(n + 1);
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
    }
    multiset<int> zhzh;
    for (int i = 1; i <= c; i++) zhzh.insert(A[i]);
    vector<int> v_okoshke;
    for (int i = c+1; i <= n; i++) {
        int x;
        for (auto y : zhzh) {
            x = y;
            break;
        }
        v_okoshke.pb(x);
        zhzh.insert(A[i]);
        zhzh.erase(zhzh.find(A[i - c]));
    }
    int x;
    for (auto y : zhzh) {
        x = y;
        break;
    }
    v_okoshke.pb(x);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i < c) {
            dp[i] = dp[i - 1] + A[i];
        } else {
            int mim = v_okoshke[i - c];
            dp[i] = min(dp[i - 1] + A[i], dp[i - c] + P[i] - P[i - c] - mim);
        }
    }
    cout << dp[n] << '\n';
}