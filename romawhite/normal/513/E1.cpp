

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
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int CNT = 1000;

int n, k;
int a[407];
int dp[407][407][51];

int main()
{
    //freopen("in.txt", "r", stdin);

    cin >> n >> k;
    FOR(i,0,n)
    {
        cin >> a[i];
    }
    /*s[0] = 0;
    FOR(i,1,n + 1)
    {
        s[i] = s[i - 1] + a[i - 1];
    }*/
    FOR(i,0,n)
    {
        FOR(j,i,n)
        {
            dp[i][j][1] = 0;
        }
    }

    FOR(t,2,k + 1)
    {
        int mp = -INF;
        int mn = -INF;
        //if (t == 1) mp = mn = 0;
        FOR(l,0,n)
        {
            int sum = 0;
            FOR(r,l,n)
            {
                sum += a[r];
                dp[l][r][t] = max(mp - sum , mn + sum);
            }
            sum = 0;
            RFOR(prev,l + 1, 0)
            {
                sum += a[prev];
                //if (t != 1)
                {
                    mp = max(mp , dp[prev][l][t - 1] + sum);
                    mn = max(mn , dp[prev][l][t - 1] - sum);
                }
            }
        }
    }
    int res = 0;
    FOR(l,0,n)
    {
        FOR(r,l,n)
        {
            res = max(res , dp[l][r][k]);
        }
    }
    /*FOR(l,0,n)
    {
        FOR(r,0,n)
        {
            cout << dp[l][r][2] << ' ';
        }
        cout << endl;
    }*/


    cout << res << endl;


    return 0;
}