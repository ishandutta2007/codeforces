#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
#define LL long long
const int NN = 2e5 + 10;
LL dp[NN][3], mn[3][3];
pair<int, int> p[NN];
int x[NN];
vector<int> vec[NN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T; cin >> T;
    while(T --) {
        int n, m; scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i ++) scanf("%d", x + i);
        sort(x + 1, x + n + 1);
        for(int i = 0; i < m; i ++) scanf("%d %d", &p[i].x, &p[i].y);
        sort(p, p + m);
        int t = 0;
        for(int i = 0; i < m; i ++) {
            while(t && p[t - 1].y >= p[i].y) t --;
            if(t && p[t - 1].x == p[i].x) continue;
            p[t ++] = p[i];
        }
        m = t; t = 0;
        for(int i = 1; i <= n; i ++) {
            while(t < m && p[t].y < x[i]) vec[i - 1].push_back(t ++);
            while(t < m && p[t].x <= x[i]) t ++;
        }
        while(t < m && p[t].x <= x[n]) t ++;
        while(t < m) vec[n].push_back(t ++);
        if(vec[0].empty()) dp[1][1] = dp[1][2] = 0;
        else dp[1][2] = 2ll * (dp[1][1] = x[1] - p[vec[0][0]].y);
        for(int i = 2; i <= n; i ++) {
            if(vec[i - 1].empty()) {
                dp[i][1] = dp[i][2] = dp[i - 1][1];
                continue;
            }
            memset(mn, 0x3f, sizeof mn);
            for(int j = 0; j <= vec[i - 1].size(); j ++) {
                LL L = 0, R = 0;
                if(j) L = p[vec[i - 1][j - 1]].x - x[i - 1];
                if(j < vec[i - 1].size()) R = x[i] - p[vec[i - 1][j]].y;
                for(int I = 1; I <= 2; I ++) for(int J = 1; J <= 2; J ++) mn[I][J] = min(mn[I][J], I * L + J * R);
            }
            for(int j = 1; j <= 2; j ++) {
                dp[i][j] = min(dp[i - 1][1] + mn[2][j], dp[i - 1][2] + mn[1][j]);
            }
        }
        if(vec[n].empty()) {
            printf("%I64d\n", min(dp[n][1], dp[n][2]));
        }
        else {
            LL R = p[vec[n].back()].x - x[n];
            printf("%I64d\n", min(dp[n][1] + 2 * R, dp[n][2] + R));
        }
        for(int i = 0; i <= n; i ++) vec[i].clear();
    }
    return 0;
}