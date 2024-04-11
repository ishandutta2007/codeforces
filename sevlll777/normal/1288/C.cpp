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
const int M = 1000000007;
int dp[1001][21];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int j = 0; j <= n; j++) {
        dp[j][1] = j;
    }
    for (int i = 2; i <= 2 * m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int first = 1; first <= j; first++) {
                dp[j][i] += dp[j - first + 1][i - 1];
                dp[j][i] %= M;
            }
        }
    }
    cout << dp[n][2 * m];
}