#include <bits/stdc++.h>
using namespace std;

#define N 200200
typedef pair <int, int> pii;

char s[N], t[N], temps[N], tempt[N];

vector <pii> ans, rlt;
int len[2][N], sum[2][N], tmp[2][30];
int dp[30][30];
pii wa[30][30];
void solve(int n, int m) {
    rlt.clear();
    while (n >= 8 || m >= 8) {
        if (n >= 8) {
            if (m == 0) {
                m ++;
                sum[1][m] = len[1][m] = 0;
            }
            rlt.push_back(pii(sum[0][n-2], sum[1][m]));
            rlt.push_back(pii(sum[1][m] + len[0][n-1] + len[0][n], sum[0][n-3]));
            len[1][m] += len[0][n-1], sum[1][m] += len[0][n-1]; n -= 4;
        }
        else {
            if (n == 0) {
                n ++;
                sum[0][n] = len[0][n] = 0;
            }
            rlt.push_back(pii(sum[0][n], sum[1][m-2]));
            rlt.push_back(pii(sum[1][m-3], sum[0][n] + len[1][m-1] + len[1][m]));
            len[0][n] += len[1][m-1], sum[0][n] += len[1][m-1]; m -= 4;
        }
    }
    while (n || m) {
        int k = wa[n][m].first, l = wa[n][m].second;
        rlt.push_back(pii(sum[0][k], sum[1][l]));
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 30; j ++) tmp[i][j] = len[i][j];
        for (int i = 1; i <= k; i ++) len[1][i] = tmp[0][i];
        for (int i = 1; i <= l; i ++) len[0][i] = tmp[1][i];
        int a = (n - k) & 1;
        int b = (m - l) & 1;
        int x = n - k + l, y = m - l + k;
        for (int i = l + 1; i <= x; i ++) len[0][i] = tmp[0][i-l+k];
        for (int i = k + 1; i <= y; i ++) len[1][i] = tmp[1][i-k+l];
        if (a == b) {
            if (l) {
                x --, len[0][l] += tmp[0][k+1];
                for (int i = l + 1; i <= x; i ++) len[0][i] = tmp[0][i+1-l+k];
            }
            if (k) {
                y --, len[1][k] += tmp[1][l+1];
                for (int i = k + 1; i <= y; i ++) len[1][i] = tmp[1][i+1-k+l];
            }
        }
        for (int i = 1; i <= x; i ++) sum[0][i] = sum[0][i-1] + len[0][i];
        for (int i = 1; i <= y; i ++) sum[1][i] = sum[1][i-1] + len[1][i];
        n = x, m = y;
    }
}

int main() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int x = 0; x < 1000; x ++) {
        for (int i = 0; i < 8; i ++) {
            for (int j = 0; j < 8; j ++) {
                if (i == 0 && j == 0) continue;
                for (int k = 0; k <= i; k ++) {
                    for (int l = 0; l <= j; l ++) {
                        if (k == 0 && l == 0) continue;
                        int a = (i - k) & 1;
                        int b = (j - l) & 1;
                        int x = i - k + l, y = j - l + k;
                        if (a == b) {
                            if (l) x --;
                            if (k) y --;
                        }
                        if (x < 8 && y < 8 && dp[i][j] > dp[x][y] + 1) dp[i][j] = dp[x][y] + 1, wa[i][j] = pii(k, l);
                    }
                }
            }
        }
    }
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    vector <int> vec;
    vec.clear();
    for (int i = 1; i <= n; i ++) {
        if (s[i] != s[i-1]) vec.push_back(i - 1);
    }
    vec.push_back(n);
    int cn = vec.size() - 1;
    for (int i = 1; i <= cn; i ++) len[0][i] = vec[i] - vec[i-1], sum[0][i] = vec[i];
    vec.clear();
    for (int i = 1; i <= m; i ++) {
        if (t[i] != t[i-1]) vec.push_back(i - 1);
    }
    vec.push_back(m);
    int cm = vec.size() - 1;
    for (int i = 1; i <= cm; i ++) len[1][i] = vec[i] - vec[i-1], sum[1][i] = vec[i];
    if (s[n] == 'a') cn --;
    if (t[m] == 'b') cm --;
    solve(cn, cm);
    ans = rlt;
    vec.clear();
    for (int i = 1; i <= n; i ++) {
        if (s[i] != s[i-1]) vec.push_back(i - 1);
    }
    vec.push_back(n);
    cn = vec.size() - 1;
    for (int i = 1; i <= cn; i ++) len[0][i] = vec[i] - vec[i-1], sum[0][i] = vec[i];
    vec.clear();
    for (int i = 1; i <= m; i ++) {
        if (t[i] != t[i-1]) vec.push_back(i - 1);
    }
    vec.push_back(m);
    cm = vec.size() - 1;
    for (int i = 1; i <= cm; i ++) len[1][i] = vec[i] - vec[i-1], sum[1][i] = vec[i];
    if (s[n] == 'b') cn --;
    if (t[m] == 'a') cm --;
    solve(cn, cm);
    if (ans.size() > rlt.size()) ans = rlt;
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i ++) printf("%d %d\n", ans[i].first, ans[i].second);
}