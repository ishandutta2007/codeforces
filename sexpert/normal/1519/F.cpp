#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
int cost[7][7], a[7], b[7];
int n, m, dp[16000][5], tdp[16000][5], p5[7];

void chmin(int &x, int y) {
    x = min(x, y);
}

string rep(int x) {
    string res;
    while(x) {
        res += (char)('0' + (x % 5));
        x /= 5;
    }
    while(res.size() < n)
        res += '0';
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p5[0] = 1;
    for(int i = 1; i < 7; i++)
        p5[i] = 5 * p5[i - 1];

    cin >> n >> m;

    for(int i = 0; i < p5[n]; i++)
        for(int k = 0; k < 5; k++)
            dp[i][k] = INF;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> cost[i][j];

    dp[0][0] = 0;

    for(int j = 0; j < m; j++) {
        for(int ms = 0; ms < p5[n]; ms++) {
            tdp[ms][0] = dp[ms][0];
            for(int k = 1; k < 5; k++)
                tdp[ms][k] = INF;
        }

        for(int i = 0; i < n; i++) {
            for(int ms = 0; ms < p5[n]; ms++) {
                for(int used = 0; used <= b[j]; used++) {
                    int tot = tdp[ms][used] + cost[i][j];
                    int sat = (ms / p5[i]) % 5;
                    for(int add = 1; add + used <= b[j]; add++) {
                        if(sat + add > a[i])
                            continue;
                        chmin(tdp[ms + add * p5[i]][used + add], tot);
                    }
                }
            }
        }

        /*for(int ms = 0; ms < p5[n]; ms++) {
            cout << rep(ms) << '\n';
            for(int k = 0; k <= b[j]; k++)
                cout << tdp[ms][k] << " ";
            cout << '\n';
        }*/

        for(int ms = 0; ms < p5[n]; ms++)
            for(int k = 1; k <= b[j]; k++)
                chmin(dp[ms][0], tdp[ms][k]);
    }

    int ini_p = 0;
    for(int i = 0; i < n; i++)
        ini_p += a[i];

    int ans = INF;

    for(int ms = 0; ms < p5[n]; ms++) {
        int su = 0;
        for(int i = 0; i < n; i++)
            su += (ms / p5[i]) % 5;
        if(su < ini_p)
            continue;
        chmin(ans, dp[ms][0]);
    }

    if(ans == INF)
        cout << "-1\n";
    else
        cout << ans << '\n';
}