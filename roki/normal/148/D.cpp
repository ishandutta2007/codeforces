#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;

inline bool read()
{
    if(!(cin >> n >> m))
        return false;
    return true;
}

ld dp[2000][2000];

inline void solve()
{
    dp[0][0] = 1;
    int h = 0;
    ld ans = 0;
    forn (it, n + m)
    {
        for (int i = 0; i <= it; ++i)
        {
            int j = it - i;
            if(i > n || j > m)
                continue;
            if(h & 1)
            {
                dp[i + 1][j + 1] += dp[i][j] / (n - i + m - j) / (n - i + m - j - 1) * (m - j) * (n - i);
                dp[i][j + 2] += dp[i][j] / (n - i + m - j) / (n - i + m - j - 1) * (m - j) * (m - j - 1);
            }
            else
            {
                ans += dp[i][j] / (n - i + m - j) * (n - i);
                dp[i][j + 1] += dp[i][j] / (n - i + m - j) * (m - j);
            }
        }
        if(h & 1)
            it++;
        h++;
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main()
{
   
    while(read())
        solve();

    return 0;
}