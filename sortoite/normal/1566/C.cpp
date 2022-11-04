#include <bits/stdc++.h>

using namespace std;

const int NN = 1e5 + 10;
int dp[NN];
char s[2][NN];

int mex(int n, int len) {
    int a = 0, b = 0;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < len; j ++) {
            if(s[i][n - j] == '0') a ++;
            else b ++;
        }
    }
    if(!a) return 0;
    if(!b) return 1;
    return 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T; cin >> T;
    while(T --) {
        int n; scanf("%d", &n);
        scanf("%s %s", s[0] + 1, s[1] + 1);
        for(int i = 1; i <= n; i ++) {
            dp[i] = 0;
            for(int j = 1; j <= 2; j ++) {
                if(j <= i) dp[i] = max(dp[i], dp[i - j] + mex(i, j));
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}