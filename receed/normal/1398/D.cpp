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

const int N = 202;
ll dp[N][N][N], n[3];

void rel(ll &x, ll y) {
    if (y > x)
        x = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rep(i, 3)
        cin >> n[i];
    vector<vector<int>> a(3);
    rep(i, 3) {
        a[i].resize(n[i]);
        rep(j, n[i])
            cin >> a[i][j];
        sort(rall(a[i]));
    }
    ll ans = 0;
    rep(i, n[0] + 1)
        rep(j, n[1] + 1)
            rep(k, n[2] + 1) {
                rel(ans, dp[i][j][k]);
                rel(dp[i + 1][j + 1][k], dp[i][j][k] + a[0][i] * a[1][j]);
                rel(dp[i + 1][j][k + 1], dp[i][j][k] + a[0][i] * a[2][k]);
                rel(dp[i][j + 1][k + 1], dp[i][j][k] + a[1][j] * a[2][k]);
            }
    cout << ans;
}