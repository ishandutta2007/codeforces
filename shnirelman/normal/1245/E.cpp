#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;

int main() {
    /*
    ld s = 0;
    ld p = ld(5) / 6;
    ld r = 1;
    for(int i = 1; i < 100; i++) {
        s += i * r;
        r *= p;
    }

    s /= 6;
    cout << setprecision(20) << fixed << s;*/

    int n = 10;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<ld>> dp(n, vector<ld>(n, 0));
    dp[0][0] = 0;
    //dp[0][1] = 6;
    //dp[0][2] =
    for(int i = 1; i <= 6; i++) {
        //ld x = ld(6) / i / i;
        //dp[0][i] = i * x;
        dp[0][i] = ld(6);// / i;
        for(int j = 0; j < i; j++)
            dp[0][i] += dp[0][j];

        dp[0][i] /= i;

        //cout << 0 << ' ' << i << ' ' << dp[0][i] << endl;
    }

    //cout << "db" << endl;

    for(int i = 0; i < n; i++) {
        int j = (i % 2 == 0 ? 0 : n - 1);
        int d = (i % 2 == 0 ? -1 : 1);
        for(; j < n && j >= 0; j -= d) {
            //cout << endl << i << ' ' << j << endl;

            if(i == 0 && j <= 6)
                continue;


            for(int l = 1; l <= 6; l++) {
                int j1 = j + l * d;
                int i1 = i;
                if(j1 >= 10) {
                    //j1 -= 10;
                    j1 = 19 - j1;
                    i1--;
                } else if(j1 < 0) {
                    //j1 += 10;
                    j1 = -j1 - 1;
                    i1--;
                }

                //cout << i1 << ' ' << j1 << endl;
                dp[i][j] += min(dp[i1][j1], dp[i1 - a[i1][j1]][j1]);
            }

            dp[i][j] = dp[i][j] / 6 + 1;

            //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }


    cout << setprecision(20) << fixed << dp[9][0];
 }