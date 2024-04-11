#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

typedef long long li;
typedef double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int INF = int(1e9) + 6;
const li INF64 = li(1e18);
const ld EPS = 1e-9;

#define sqr(n) ((n) * (n))

const int N = 32000;

int cnt[N];
int n, d;

bool read() 
{
    if (scanf("%d%d", &n, &d) != 2)
        return false;
    forn (i, n)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
   return true;
}

const int M = 500;
int dp[N][M];

void solve() 
{
    forn (i, N)
        forn (j, M)
            dp[i][j] = -INF;
    dp[0][250] = 0;
    forn (i, N)
        forn (j, M)
        {
            if (dp[i][j] < 0)
                continue;
            int cd = d + j - 250;
            if (cd <= 0)
                continue;
            if (i + cd < N)
            {
                if (j)
                    dp[i + cd][j - 1] = max(dp[i + cd][j - 1], dp[i][j] + cnt[i + cd]);
                dp[i + cd][j] = max(dp[i + cd][j], dp[i][j] + cnt[i + cd]);
                if (j + 1 < M)
                    dp[i + cd][j + 1] = max(dp[i + cd][j + 1], dp[i][j] + cnt[i + cd]);

            }
                
        }
    int ans = 0;
    forn (i, N)
        forn (j, M)
        ans = max(ans, dp[i][j]);
    cout << ans << endl;
}

int main() 
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    while(read())   
        solve();

    return 0;
}