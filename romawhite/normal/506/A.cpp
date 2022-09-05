#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000100000;
const int MAX = 30007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

int a[MAX];
int dp[MAX][600];

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt" , "w" , stdout);
    #endif

    int n, d;
    cin >> n >> d;
    FOR(i,0,n)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    FILL(dp, -1);
    dp[d][300] = a[d];
    int res = 0;
    FOR(i,d,MAX)
    {
        FOR(j,0,600)
        {
            res = max(res , dp[i][j]);
            if (dp[i][j] != -1)
            {
                int len = d - 300 + j;
                if (i + len < MAX)
                {
                    dp[i + len][j] = max(dp[i + len][j] , dp[i][j] + a[i + len]);
                }
                if (i + len + 1 < MAX)
                {
                    dp[i + len + 1][j + 1] = max(dp[i + len + 1][j + 1] , dp[i][j] + a[i + len + 1]);
                }
                if (i + len - 1 < MAX && len - 1 > 0)
                {
                    dp[i + len - 1][j - 1] = max(dp[i + len - 1][j - 1] , dp[i][j] + a[i + len - 1]);
                }
            }
        }
    }
    //cout << dp[19][299] << endl;
    cout << res << endl;

    return 0;
}