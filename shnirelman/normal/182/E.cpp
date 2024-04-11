#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void upd(int& a) {
    if(a >= M)
        a -= M;
}

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n), b(n);
    vector<bool> is(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        is[i] = (a[i] != b[i]);
    }

    vector<vector<vector<int>>> dp(l + 1, vector<vector<int>>(n, vector<int>(2, 0)));
    for(int i = 0; i < n; i++) {
        if(a[i] <= l)
            dp[a[i]][i][0] = 1;
        if(is[i] && b[i] <= l)
            dp[b[i]][i][1] = 1;
        //cout << i << ' ' << a[i] << ' ' << b[i] << ' ' << dp[a[i]][i][0] << ' ' << dp[b[i]][i][1] << endl;
    }

    //cout << dp[3][1][1] << endl;

    for(int l1 = 0; l1 <= l; l1++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= 1; j++) {
                if(!is[i] && j)
                    continue;

                int a1 = a[i];
                int b1 = b[i];

                if(j == 1)
                    swap(a1, b1);

                if(l1 - a1 < 0)
                    continue;

                for(int k = 0; k < n; k++)
                    if(k != i) {
                        if(b[k] == a1) {
                            dp[l1][i][j] += dp[l1 - a1][k][0];
                            upd(dp[l1][i][j]);
                        }

                        if(is[k] && a[k] == a1) {
                            dp[l1][i][j] += dp[l1 - a1][k][1];
                            upd(dp[l1][i][j]);
                        }
                    }
                //cout << l1 << ' ' << i << ' ' << j << ' ' << dp[l1][i][j] << endl;
            }

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++) {
            ans += dp[l][i][j];
            upd(ans);
        }

    cout << ans;
}