#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int dp[102][102][12][12];

int main()
{
    
    dp[0][0][0][0] = 1;
    int mod = 1e8;

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    forn (i, n1 + 1)
        forn (j, n2 + 1)
        {
            forn (q, k1 + 1)
            {
                if(q != 0)
                dp[i + 1][j][q + 1][0] += dp[i][j][q][0];
                dp[i + 1][j][q + 1][0] %= mod;
                dp[i][j + 1][0][1] += dp[i][j][q][0];
                dp[i][j + 1][0][1] %= mod;
            }
            forn (w, k2 + 1)
            {
                dp[i + 1][j][1][0] += dp[i][j][0][w];
                dp[i + 1][j][1][0] %= mod;
                if(w != 0)
                dp[i][j + 1][0][w + 1] += dp[i][j][0][w];
                dp[i][j + 1][0][w + 1] %= mod;
            }
        }
    int ans = 0;
    forn (i, k1 + 1)
        forn (j, k2 + 1)
        {
            ans += dp[n1][n2][i][j];
            ans %= mod;
        }
    cout << ans << endl;
    return 0;
}