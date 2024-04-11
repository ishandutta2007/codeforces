#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9;

int n, m;
string s;
int asum[2][N], bsum[2][N], qsum[N];

int mx[N];
int dp[N][2];

bool check(int i) {
    int r = i + m - 1, l = i - 1;
    return bsum[i % 2][r] - bsum[i % 2][l] == 0 &&
            asum[(i + 1) % 2][r] - asum[(i + 1) % 2][l] == 0;
}

int cost(int i) {
    int r = i + m - 1, l = i - 1;
    return qsum[r] - qsum[l];
}

int main() {
    cin >> n >> s >> m;
    s = " " + s;
    for(int j = 1; j <= n; j++) {
        for(int i = 0; i < 2; i++) {
            asum[i][j] = asum[i][j-1];
            bsum[i][j] = bsum[i][j-1];
            if(j % 2 == i) {
                asum[i][j] += s[j] == 'a';
                bsum[i][j] += s[j] == 'b';
            }
        }
        qsum[j] = qsum[j-1] + (s[j] == '?');
    }
    for(int i = 1; i <= n; i++) {
        mx[i] = mx[i-1];
        if(i >= m && check(i - m + 1)) mx[i] = mx[i-m] + 1;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i >= m && check(i - m + 1)) {
            dp[i][0] = min(dp[i][0], dp[i - m][0] + cost(i - m + 1));
            dp[i][1] = min(dp[i][1], dp[i - m][1] + cost(i - m + 1));
        }
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                int cur = mx[i] - j, la = mx[i-1] - k;
                if(cur == la) dp[i][j] = min(dp[i][j], dp[i-1][k]);
            }
        }
    }
    cout << dp[n][0] << endl;

}