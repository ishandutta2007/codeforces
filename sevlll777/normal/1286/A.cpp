#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
#define str string
#define pb push_back
#define pii pair<int, int>

using namespace std;

int dp[101][101][101][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            dp[0][i][j][0] = 1e9;
            dp[0][i][j][1] = 1e9;
        }
    }
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int od = 0; od <= 100; od++) {
            for (int ev = 0; ev <= 100; ev++) {
                dp[i][od][ev][0] = 1e9;
                dp[i][od][ev][1] = 1e9;
                if (P[i] == 0) {
                    if (ev > 0) {
                        dp[i][od][ev][0] = min(dp[i - 1][od][ev - 1][0], 1 + dp[i - 1][od][ev - 1][1]);
                    }
                    if (od > 0) {
                        dp[i][od][ev][1] = min(dp[i - 1][od - 1][ev][1], 1 + dp[i - 1][od - 1][ev][0]);
                    }
                } else {
                    if (P[i] % 2) {
                        if (od > 0) {
                            dp[i][od][ev][1] = min(dp[i - 1][od - 1][ev][1], 1 + dp[i - 1][od - 1][ev][0]);
                        }
                    } else {
                        if (ev > 0) {
                            dp[i][od][ev][0] = min(dp[i - 1][od][ev - 1][0], 1 + dp[i - 1][od][ev - 1][1]);
                        }
                    }
                }
            }
        }
    }
    cout << min(dp[n][(n + 1) / 2][n / 2][0], dp[n][(n + 1) / 2][n / 2][1]);


}