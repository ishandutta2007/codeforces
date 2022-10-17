#include <bits/stdc++.h>
using namespace std;

const int MAXN = 512;
const int MOD = 1e9 + 7;

int N, M;
char grid[MAXN][MAXN];
int dp[2][MAXN][MAXN];

bool valid(int r, int c) {
    if(r < 0 || c < 0) return false;
    if(r >= N || c >= M) return false;
    return true;
}

bool match(int sum, int v1, int v2) {
    int r1 = v1, c1 = sum - v1;
    int r2 = N-1-v2, c2 = M-1-(sum-v2);
    if(!valid(r1, c2) || !valid(r2, c2)) return false;
    return grid[r1][c1] == grid[r2][c2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for (int sum = 0; sum <= (N+M-2)/2; sum++) {
        for (int v1 = 0; v1 <= sum; v1++) {
            for (int v2 = 0; v2 <= sum; v2++) {
                dp[sum&1][v1][v2] = 0;
                if(!match(sum, v1, v2)) {
                    continue;
                }

                if(sum == 0) dp[sum&1][v1][v2] = 1;
                else {
                    int &res = dp[sum&1][v1][v2];
                    if(match(sum-1, v1-1, v2-1)) res = (res + dp[(sum-1)&1][v1-1][v2-1]) % MOD;
                    if(match(sum-1, v1, v2-1)) res = (res + dp[(sum-1)&1][v1][v2-1]) % MOD;
                    if(match(sum-1, v1-1, v2)) res = (res + dp[(sum-1)&1][v1-1][v2]) % MOD;
                    if(match(sum-1, v1, v2)) res = (res + dp[(sum-1)&1][v1][v2]) % MOD;
                }
            }
        }
    }

    if((N + M) % 2 == 0) {
        int idx = (N + M - 2) / 2;
        int ans = 0;
        for (int v1 = 0; v1 <= idx; v1++)
            if(N-1-v1 >= 0) ans = (ans + dp[idx&1][v1][N-1-v1]) % MOD;
        cout << ans << endl;
    } else {
        int idx = (N + M - 2) / 2;
        int ans = 0;
        for (int v1 = 0; v1 <= idx; v1++) {
            if(match(idx, v1, N-1-v1)) ans = (ans + dp[idx&1][v1][N-1-v1]) % MOD;
            if(match(idx, v1, N-2-v1)) ans = (ans + dp[idx&1][v1][N-2-v1]) % MOD;
        }
        cout << ans << endl;
    }
}