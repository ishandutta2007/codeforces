#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<set>
#include<ctime>
#include<memory.h>
#include<vector>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

li dp[51][51][111][2];
li mod = 1e9 + 7;
li c[150][150];

int main()
{
    for (int i = 0; i <= 100; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    int n, k;
    cin >> n >> k;
    k /= 50;
    vector<int> a(n);
    int q = 0, w = 0;
    forn (i, n)
    {
        cin >> a[i];
        a[i] /= 50;
        if(a[i] == 1)
            q++;
        else
            w++;
    }
    dp[0][0][0][0] = 1;
    forn (t, 210)
    {
        for (int i = 0; i <= q; ++i)
        {
            for (int j = 0; j <= w; ++j)
            {
                for (int p = 0; p <= q - i; ++p)
                    for (int r = 0; r <= w - j; ++r)
                    {
                        if(r == 0 && p == 0)
                            continue;
                        if(p + 2 * r > k)
                            break;
                        dp[i + p][r + j][t + 1][1] = (dp[i][j][t][0] * (c[q - i][p] * c[w - j][r] % mod) % mod + dp[i + p][r + j][t + 1][1]) % mod;
                    }
                for (int p = 0; p <= i; ++p)
                    for (int r = 0; r <= j; ++r)
                    {
                        if(r == 0 && p == 0)
                            continue;
                        if(p + 2 * r > k)
                            break;
                        dp[i - p][j - r][t + 1][0] = (dp[i][j][t][1] * (c[i][p] * c[j][r] % mod) % mod + dp[i - p][j - r][t + 1][0]) % mod;
                    }
            }   
        }
        if(dp[q][w][t][1] != 0)
        {
            cout << t << endl << dp[q][w][t][1] << endl;
            return 0;
        }
    }
    cout << -1 << endl << 0 << endl;
    return 0;
}