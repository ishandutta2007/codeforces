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
#include<unordered_set>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, k;
int a[10000];

bool read()
{
    if (!(cin >> n >> k))
        return false;
    forn (i, n)
        cin >> a[i];
    return true;
}

int dp[2010];

bool ok (li t)
{
    forn (i, n)
        dp[i] = i;
    forn (i, n)
        for (int j = i + 1; j < n; ++j)
        {
            if (abs(a[i] - a[j]) <= (j - i) * t)
                dp[j] = min(dp[j], dp[i] + j - i - 1);
        }

    forn (i, n) 
        if (n - i - 1 + dp[i] <= k)
            return true;

    return false;
}

void solve()
{
    li l = -1, r = 2e9;
    while (r - l > 1)
    {
        int m = (r + l) / 2;
        if (ok(m))
            r = m;
        else
            l = m;
    }
    cout << r << endl;
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