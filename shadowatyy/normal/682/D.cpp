#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000LL
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PIC pair<int, char>
#define VI vector<int>
#define VLL vector<ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
using namespace std;

int n, m, k;

int dp[1007][1007][11][2];

string s1, s2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> k >> s1 >> s2;

    s1 = '#' + s1;
    s2 = '#' + s2;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            for(int l = 1; l <= k; ++l)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j][l][1] = max(dp[i-1][j-1][l][1]+1, dp[i-1][j-1][l-1][0]+1);
                }

                dp[i][j][l][0] = max(max(dp[i-1][j][l][0], dp[i][j-1][l][0]), max(dp[i-1][j][l][1], dp[i][j-1][l][1]));
            }
        }
    }

    cout << max(dp[n][m][k][0], dp[n][m][k][1]);
}