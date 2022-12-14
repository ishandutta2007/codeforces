// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = 105, mod = 0;

int dp[N][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    memset(dp, 63, sizeof dp);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x & 1) dp[i][0] = min(dp[i - 1][1], dp[i][0]);
        if (x & 2) dp[i][1] = min(dp[i - 1][0], dp[i][1]);
        for (int j = 0; j < 2; ++j)
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i - 1][j ^ 1] + 1, dp[i][j]));
    }
    cout << min(dp[n][0], dp[n][1]) << endl;





}