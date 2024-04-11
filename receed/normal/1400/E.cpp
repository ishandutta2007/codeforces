#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 5001;
ll a[N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, ans = 0;
    cin >> n;
    rep(i, n + 1)
        rep(j, n + 1)
            dp[i][j] = n;
    rep(i, n + 1)
        dp[0][i] = i;
    rep(i, n) {
        cin >> a[i];
        rep(j, min(a[i], n) + 1)
            dp[i + 1][j] = dp[i][j] + (a[i] > j);
        rep(j, n)
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + 1);
        for (int j = n - 1; j >= 0; j--)
            dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
    cout << dp[n][0];
}