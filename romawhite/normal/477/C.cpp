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
#include <fstream>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int MAX = 100007;
const int MOD = 1000000007;
const int INF = 1000000000;
int nx[2007];

int dp[2007][2007];

int d[2007];
int res[2007];

int main()
{
    //freopen("in.txt" , "r" , stdin);

    string s, p;
    cin >> s >> p;

    FOR(i,0,s.size())
    {
        int ptr = i;
        nx[i] = -1;
        FOR(j,0,p.size())
        {
            while (ptr < s.size() && s[ptr] != p[j]) ++ptr;
            if (ptr == s.size()) break;
            ++ptr;
            if (j == p.size() - 1)
            {
                nx[i] = ptr;
            }
        }
    }


    FOR(i,0,s.size() + 1)
        FOR(j,0,s.size() + 1)
            dp[i][j] = INF;

    dp[0][0] = 0;
    FOR(i,0,s.size() )
    {
        FOR(j,0,s.size())
        {
            dp[i + 1][j] = min(dp[i][j] , dp[i + 1][j]);
            if (nx[i] != -1)
            {
                dp[nx[i]][j + 1] = min(dp[nx[i]][j + 1], dp[i][j] + nx[i] - i - (int)p.size() );
            }
        }
    }

    /*FOR(i,0,s.size() + 1)
    {
        FOR(j,0,s.size() + 1)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }*/

    FOR(i,0,s.size() + 2)
    {
        d[i] = INF;
    }



    FOR(i,0,s.size() + 1)
    {
        FOR(j,0,s.size() + 1)
        {
            if (dp[i][j] != INF)
            {
                d[j] = min(d[j] , dp[i][j]);
            }
        }
    }

   /* FOR(i,0,s.size() + 1)
    {
        cout << d[i] << ' ';
    }*/

    FOR(i,0,s.size() + 1)
    {
        if (d[i + 1] == INF)
        {
            FOR(j,d[i],(int)s.size() + 1)
            {
                res[j] = i;
            }
            break;
        }
        FOR(j,d[i], d[i + 1])
        {
            res[j] = i;
        }
    }

    FOR(i,0,s.size() + 1)
    {
        res[i] = min(res[i] , ((int)s.size() - i) / (int)p.size());
    }

    FOR(i,0,s.size() + 1)
    {
        cout << res[i] << ' ';
    }

    return 0;
}