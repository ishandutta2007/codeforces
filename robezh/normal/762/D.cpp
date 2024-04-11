#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

int n;
int val[3][N];
ll dp[2][6][(1 << 6) + 5];
int di[6] = {0, 1, 2, 0, 1, 2}, dj[6] = {0, 0, 0, 1, 1, 1};
int good[6][6];

int main() {
    ios::sync_with_stdio(false);
    for(int i = 0; i < 2; i++) for(int j = 0; j < 6; j++) fill(dp[i][j], dp[i][j] + (1 << 6) + 5, -INF);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            good[i][j] = (abs(di[i] - di[j]) + abs(dj[i] - dj[j])) == 1;
        }
    }
    cin >> n;
    for(int i = 0; i < 3; i++) for(int j = 0; j < n; j++) cin >> val[i][j];
    if(n == 1) return cout << 1LL * val[0][0] + val[1][0] + val[2][0] << endl, 0;
    int nw = 1, la = 0;
//    dp[0][0][1] = val[0][0];
    for(int j = 0; j < n; j++){
        swap(nw, la);
        for(int i = 0; i < 6; i++) fill(dp[nw][i], dp[nw][i] + (1 << 6) + 5, -INF);
        if(j == 0) dp[nw][0][1] = val[0][0];
        for(int mask = 1; mask < (1 << 6); mask++) {
            for(int i = 3; i < 6; i++) {
                if(dp[la][i][mask] == -INF) continue;
                dp[nw][i-3][mask >> 3] = max(dp[nw][i-3][mask >> 3], dp[la][i][mask]);
            }
        }
        for(int mask = 1; mask < (1 << 6); mask++) {
            for (int i = 0; i < 6; i++) {
                if (dp[nw][i][mask] == -INF) continue;
                for (int nxt = 0; nxt < 6; nxt++) {
                    if (good[i][nxt] && !((mask >> nxt) & 1)) {
                        dp[nw][nxt][mask | (1 << nxt)] =
                                max(dp[nw][nxt][mask | (1 << nxt)], dp[nw][i][mask] + val[nxt % 3][j + nxt / 3]);
                    }
                }
            }
        }
    }
    ll res = -INF;
    for(int mask = 1; mask < (1 << 6); mask++) {
        bool inval = false;
        for(int j = 3; j < 6; j++) if((mask >> j) & 1) inval = true;
        if(!inval) res = max(res, dp[nw][2][mask]);
    }
    cout << res << endl;

}