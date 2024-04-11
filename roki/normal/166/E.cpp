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
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;

bool read()
{
    if (!(cin >> n))
        return false;
    return true;
}

int dp[10000001][4];

void solve()    
{
    int mod = 1e9 + 7;
    dp[0][3] = 1;
    forn (i, n)
    {
        int sum = 0;
        forn (j, 4)
            sum = (sum + dp[i][j]) % mod;
        forn (j, 4)
            dp[i + 1][j] += (sum + mod - dp[i][j]) % mod;
    }
    cout << dp[n][3] << endl;
}
    
int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    
    return 0;
}