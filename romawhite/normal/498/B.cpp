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

const int INF = 1000000000;
const int MAX = 50007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

double dp[2][5007];
double P[5007];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif

    dp[0][0] = 1;
    int prev = 0;
    int next = 1;

    int n, T;
    cin >> n >> T;
    double res = 0;
    FOR(it,0,n)
    {
        int pp, t;
        cin >> pp >> t;
        double p = 0.01 * pp;
        if (t == 1)
        {
            dp[next][0] = 0;
            FOR(i,1,T + 1)
            {
                dp[next][i] = dp[prev][i - 1];
                res += dp[next][i];
            }
            swap(prev, next);
            continue;

        }
        else
        {
            double ss = 0;
            P[0] = p;
            ss += P[0];
            FOR(i,1,t - 1)
            {
                P[i] = P[i - 1] * (1 - p);
                ss += P[i];
            }
            P[t - 1] = 1 - ss;
        }
        dp[next][0] = 0;
        FOR(i,1,T + 1)
        {
            dp[next][i] = dp[next][i - 1];
            if (i - 1 >= t)
            {
                dp[next][i] -= dp[prev][i - 1 - t] * P[t - 1];
            }
            if (i >= t)
            {
                dp[next][i] -= dp[prev][i - t] * P[t - 2];
            }
            dp[next][i] *= (1 - p);
            if (i >= t)
            {
                dp[next][i] += dp[prev][i - t] * P[t - 1];
            }
            dp[next][i] += dp[prev][i - 1] * p;
            if (dp[next][i] < 1e-12) dp[next][i] = 0;
            res += dp[next][i];
        }

        swap(prev, next);

    }

    printf("%.10f\n" , res);

    return 0;
}