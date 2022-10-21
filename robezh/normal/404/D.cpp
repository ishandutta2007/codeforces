#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 5, mod = (int)1e9 + 7;

string str;


bool valid(int a, int b, int c) {
    if(b == 3) return true;
    return b == (a == 3) + (c == 3);
}

int n;
int dp[N][4][4];
int ch[256];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ch['*'] = 3, ch['0'] = 0, ch['1'] = 1, ch['2'] = 2;

    cin >> str;
    n = str.length();
    if(str[0] == '?') for(int i = 0; i < 4; i++) dp[0][0][i] = 1;
    else dp[0][0][ch[str[0]]] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                int l = (str[i] == '?' ? 0 : ch[str[i]]);
                int r = (str[i] == '?' ? 3 : ch[str[i]]);
                for(int t = l; t <= r; t++) {
                    if(valid(j, k, t)) {
                        dp[i][k][t] += dp[i-1][j][k];
                        if(dp[i][k][t] >= mod) dp[i][k][t] -= mod;
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(valid(i, j, 0)) {
                res += dp[n-1][i][j];
                if(res >= mod) res -= mod;
            }
        }
    }
    cout << res << endl;

}