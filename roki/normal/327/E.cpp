#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
int a[25];
int m;
int b[2];

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
        cin >> a[i];
    cin >> m;
    forn (i, m)
        cin >> b[i];
    return true;
}

li dp[1 << 24];

void solve()
{
    int mod = 1e9 + 7;
    forn (i, 1 << n)
        forn (j, n)
            if(i & (1 << j))
            {
                dp[i] = dp[i ^ (1 << j)] + a[j];
                break;
            }
    forn (i, 1 << n)
        forn (j, m)
        if(dp[i] == b[j])
            dp[i] = -1;
    dp[0] = 1;
    for (int i = 1; i < (1 << n); ++i)
        if(dp[i] == -1)
            dp[i] = 0;
        else
        {
            dp[i] = 0;
            forn (j, n)
                if(i & (1 << j))
                    dp[i] += dp[i ^ (1 << j)];
            dp[i] %= mod;
        }
    cout << dp[(1 << n) - 1] << endl;
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