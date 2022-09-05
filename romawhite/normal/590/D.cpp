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
#include <cassert>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 157;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int dp[2][MAX][MAX * MAX];

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int n , k , s;
    cin >> n >> k >> s;
    //n = 150;
    //k = 150;
    //s = n * (n - 1) / 2 - 1;
    vector<int> a(n);
    FOR(i,0,n)
        cin >> a[i];
    //  a[i] = rand() % 1000000;

    if (s >= n * (n - 1) / 2)
    {
        sort(ALL(a));
        int res = 0;
        FOR(i,0,k)
            res += a[i];
        cout << res << endl;
        return 0;
    }

    int prev = 0;
    int next = 1;
    FOR(i,0,MAX)
        FOR(j,0,MAX * MAX)
            dp[0][i][j] = INF;

    dp[0][0][0] = 0;

    FOR(i,0,n)
    {


        FOR(j,0,min(i + 2 , k) + 1)
            FOR(l,0,min(s , (i + 3) * (i + 3) / 2) + 1)
                dp[next][j][l] = INF;

        FOR(j,0,min(i + 1 , k) + 1)
            FOR(l,0,min(s , (i + 2) * (i + 2) / 2) + 1)
                if (dp[prev][j][l] != INF)
                {
                    dp[next][j][l] = min(dp[next][j][l] , dp[prev][j][l]);
                    dp[next][j + 1][l + i - j] = min(dp[next][j + 1][l + i - j] , dp[prev][j][l] + a[i]);
                }

        swap(prev , next);


    }

    int res = INF;
    FOR(l,0,s + 1)
        res = min(res , dp[prev][k][l]);

    cout << res << endl;


    return 0;
}