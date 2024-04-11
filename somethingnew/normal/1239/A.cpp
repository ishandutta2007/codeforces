#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
int mod = ((int)1e9) + 7;
int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> dp(100005);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 100005; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
    int n, m;
    cin >> n >> m;
    cout << ((dp[n] - 1 + dp[m]) * 2) % mod;
}