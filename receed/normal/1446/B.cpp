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
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    string s, t;
    cin >> n >> m >> s >> t;
    rep(i, n)
        rep(j, m) {
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            if (s[i] == t[j])
                dp[i][j] = max(dp[i][j], 2 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0));
            ans = max(ans, dp[i][j]);
        }
    cout << ans;
}