#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
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
#include <complex>

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
#define y1 adsfadsfadfs

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 2007;
const int MAX2 = 15000000;

double dp[MAX][MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    int n , t;
    double p;
    cin >> n >> p >> t;

    dp[0][0] = 1;
    FOR(i,0,n + 1)
    {
        FOR(j,0,t)
        {
            if (dp[i][j] > 1e-12)
            {
                if (i == n) dp[i][j + 1] += dp[i][j];
                else
                {
                    dp[i + 1][j + 1] += p * dp[i][j];
                    dp[i][j + 1] += (1 - p) * dp[i][j];
                }
            }
        }
    }
    double res = 0.0;
    FOR(i,0,n + 1)
    {
        res += i * dp[i][t];
    }

    printf("%.10f\n" , res);

    return 0;
}