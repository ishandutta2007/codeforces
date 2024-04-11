#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 80;
const int INF = 1e9 + 10;
int dp[MAX][MAX][MAX][3], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            for(int k = 0; k < MAX; k++)
                dp[i][j][k][0] = dp[i][j][k][1] = dp[i][j][k][2] = INF;

    string s;
    cin >> n >> s;
    for(auto &c : s) {
        if(c == 'V')
            c = '0';
        else if(c == 'K')
            c = '1';
        else
            c = '2';
    }

    dp[0][0][0][2] = 0;

    for(int len = 0; len < n; len++) {
        for(int i = 0; i <= len; i++) {
            for(int j = 0; i + j <= len; j++) {
                int k = len - i - j;
                int ci = i, cj = j, ck = k;
                string filtered;
                for(auto c : s) {
                    if(c == '0') {
                        if(ci)
                            ci--;
                        else
                            filtered.push_back('0');
                    }
                    if(c == '1') {
                        if(cj)
                            cj--;
                        else
                            filtered.push_back('1');
                    }
                    if(c == '2') {
                        if(ck)
                            ck--;
                        else
                            filtered.push_back('2');
                    }
                }
                if(ci > 0 || cj > 0 || ck > 0)
                    continue;
                for(int prv = 0; prv < 3; prv++) {
                    //cout << i << " " << j << " " << k << " " << prv << " " << dp[i][j][k][prv] << '\n';
                    //cout << filtered << '\n';
                    for(int nxt = 0; nxt < 3; nxt++) {
                        int c0 = (nxt == 0);
                        int c1 = (nxt == 1);
                        int c2 = (nxt == 2);
                        if(prv == 0 && nxt == 1)
                            continue;
                        for(int w = 0; w < filtered.size(); w++) {
                            if(filtered[w] - '0' == nxt) {
                                dp[i + c0][j + c1][k + c2][nxt] = min(dp[i + c0][j + c1][k + c2][nxt], dp[i][j][k][prv] + w);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; i + j <= n; j++) {
            int k = n - i - j;
            ans = min(ans, dp[i][j][k][0]);
            ans = min(ans, dp[i][j][k][1]);
            ans = min(ans, dp[i][j][k][2]);
        }
    }

    cout << ans << '\n';
}