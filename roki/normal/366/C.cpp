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

int n, k;

int a[100], b[100];

bool read()
{
    if (!(cin >> n >> k))
        return false;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
    {
        cin >> b[i];
        b[i] *= k;
    }
    return true;
}

int dp[20001];

void solve()    
{
    forn (i, 20001)
        dp[i] = -1;
    dp[10000] = 0;
    forn (i, n)
    {
        vector<int> ndp(20001, -1e9);
        forn (j, 20001)
        {
            if (dp[j] < 0)
                continue;
            int nt = j + a[i] - b[i];
            if (nt >= 0 && nt <= 20000)
                ndp[nt] = max(ndp[nt], a[i] + dp[j]);
        }
        forn (j, 20001)
            dp[j] = max(dp[j], ndp[j]);
    }
    if (dp[10000] <= 0)
        dp[10000] = -1;
    cout << dp[10000];
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