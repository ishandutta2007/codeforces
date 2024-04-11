#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 228;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int dp[108][1008];

vector<int> a[107];

int main()
{
      //freopen("in.txt","r",stdin);
 //   freopen("C:/output.txt" , "w" , stdout);

    int n , T;
    cin >> n >> T;
    FOR(i,0,n)
    {
        int t , q;
        cin >> t >> q;
        a[t].push_back(q);
    }

    FOR(i,0,T + 1)
    {
        sort(ALL(a[i]));
        reverse(ALL(a[i]));
    }

    FOR(i,0,107)
        FOR(j,0,1007)
        {
            dp[i][j] = -INF;
        }

    dp[T][1] = 0;
    RFOR(i,T + 1,1)
    {
        FOR(j,0,1007)
        {
            if (dp[i][j] >= 0)
            {
                //cout << dp[i][j] << ' ' << i << ' '  << j << endl;
                int sum = 0;
                FOR(k,1,min((int)a[i].size(), j) + 1)
                {
                    sum += a[i][k - 1];
                    //cout << i << ' '  << j - k << ' ' << sum <<  ' ' << dp[i][j - k] << endl;
                    dp[i][j - k] = max(dp[i][j - k] , dp[i][j] + sum);
                }
            }
        }
        FOR(j,0,1007)
        {
            dp[i - 1][min(2 * j, 1000)] = max(dp[i - 1][min(2 * j, 1000)], dp[i][j]);
        }
    }

    int res = 0;
    FOR(i,0,107)
    {
        FOR(j,0,1007)
        {
            res = max(res , dp[i][j]);
        }
    }

    cout << res << endl;

    return 0;
}