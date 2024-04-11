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

int z[5005][5005];

string ss, s;

void Z()
{
    int n = ss.size();
    FOR(id,0,n)
    {
        z[id][id] = 0;
        int l = 0;
        int r = 0;
        FOR(i,1,ss.size())
        {
            if (i <= r)
                z[id][i + id] = min(r - i + 1, z[id][i - l + id]);
            while (i + z[id][i + id] < n && ss[z[id][i + id]] == ss[i + z[id][i + id]])
            {
                ++z[id][i + id];
            }
            if (i+z[id][i + id]-1 > r)
            {
                l = i;
                r = i + z[id][i + id] - 1;
            }
        }
        ss.erase(ss.begin());
    }
}

pair<int,int> dp[5005][5005];

bool GreaterOrEq(int i, int j)
{
    int len = j - i;
    if (z[i][j] >= len) return 1;
    return s[j + z[i][j]] > s[i + z[i][j]];
}

int main()
{
    //freopen("in.txt" , "r" , stdin);
    cin >> s;
    ss = s;
    Z();


    /*FOR(i,0,s.size())
    {
        FOR(j,0,s.size())
        {
            cout << z[i][j] << ' ';
        }
        cout << endl;
    }*/

    FOR(i,0,s.size() + 1)
    {
        FOR(j,0,s.size() + 1)
        {
            dp[i][j] = MP(0, INF);
        }
    }

    FOR(j,1,s.size() + 1)
        dp[0][j] = MP(1, 1);

    FOR(i,1,s.size())
    {
        if (s[i] == '0') continue;
        int c = 0;
        int m = INF;
        FOR(j,1,s.size() - i + 1)
        {
            dp[i][j].first += c;
            dp[i][j].first %= MOD;
            dp[i][j].second = min(dp[i][j].second, m + 1);
            if (i >= j && GreaterOrEq(i - j, i))
            {
                dp[i][j].first += dp[i - j][j].first;
                dp[i][j].first %= MOD;
                dp[i][j].second = min(dp[i][j].second, dp[i - j][j].second + 1);
            }
            if (i >= j)
            {
                c += dp[i - j][j].first;
                c %= MOD;
                m = min(m, dp[i - j][j].second);
            }
        }
    }

    /*FOR(i,0,s.size())
    {
        FOR(j,1,s.size() + 1)
        {
            cout << dp[i][j].first << ' ';
        }
        cout << endl;
    }*/

    int res = 0;
    FOR(i,0,s.size())
    {
        res += dp[i][s.size() - i].first;
        res %= MOD;
    }

    bool found = 0;
    int pw = 1;
    int res2 = 2 * INF;
    int r = 0;
    int cnt = 0;
    RFOR(i,s.size() , 0)
    {
        ++cnt;
        if (cnt > 20 && found) break;
        if (s[i] == '1')
        {
            r += pw;
            r %= MOD;
        }

        pw *= 2;
        pw %= MOD;

        if (dp[i][s.size() - i].second != INF)
        {
            found = 1;
            //cout << r << ' ' << dp[i][s.size() - i].second << endl;
            res2 = min(res2 , (dp[i][s.size() - i].second + r) % MOD);
        }
    }

    cout << res << endl;
    cout << res2 << endl;

    return 0;
}