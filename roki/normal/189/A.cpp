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

int n, a, b, c;

bool read()
{
    if (!(cin >> n >> a >> b >> c))
        return false;
    return true;
}

void solve()    
{
    int dp[10000];
    forn (i, 10000)
        dp[i] = -1e9;
    dp[0] = 0;
    forn (i, n)
    {
        dp[i + a] = max (dp[i + a], dp[i] + 1);
        dp[i + b] = max (dp[i + b], dp[i] + 1);
        dp[i + c] = max (dp[i + c], dp[i] + 1);
    }
    cout << dp[n] << endl;
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