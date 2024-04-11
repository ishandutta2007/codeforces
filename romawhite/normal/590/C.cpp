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

const int INF = 300000000;
const int MAX = 1007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

char s[MAX][MAX];

int d1[MAX][MAX];
int d2[MAX][MAX];
int d3[MAX][MAX];

PII Q[MAX * MAX];

int n , m;

bool ok(int x , int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '#';
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    //freopen("in.txt" , "r" , stdin);

    cin >> n >> m;
    FOR(i,0,n)
    {
        scanf("%s" , s[i]);
    }
    int res = INF;

    {
        int L = 0;
        int R = 0;

        int D1 = INF;
        int D2 = INF;

        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if (s[i][j] == '1')
                {
                    d1[i][j] = 0;
                    Q[R++] = MP(i,j);
                }
                else
                {
                    d1[i][j] = INF;
                }
            }
        }
        while (L < R)
        {
            int x = Q[L].first;
            int y = Q[L].second;

            if (s[x][y] == '2') D1 = min(D1 , d1[x][y]);
            if (s[x][y] == '3') D2 = min(D2 , d1[x][y]);

            ++L;
            FOR(dir,0,4)
            {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (ok(xx , yy) && d1[xx][yy] == INF)
                {
                    d1[xx][yy] = d1[x][y] + 1;
                    Q[R++] = MP(xx, yy);
                }
            }
        }

        res = min(res , D1 - 1 + D2 - 1);
    }

    {
        int L = 0;
        int R = 0;

        int D1 = INF;
        int D2 = INF;

        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if (s[i][j] == '2')
                {
                    d2[i][j] = 0;
                    Q[R++] = MP(i,j);
                }
                else
                {
                    d2[i][j] = INF;
                }
            }
        }
        while (L < R)
        {
            int x = Q[L].first;
            int y = Q[L].second;

            if (s[x][y] == '1') D1 = min(D1 , d2[x][y]);
            if (s[x][y] == '3') D2 = min(D2 , d2[x][y]);

            ++L;
            FOR(dir,0,4)
            {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (ok(xx , yy) && d2[xx][yy] == INF)
                {
                    d2[xx][yy] = d2[x][y] + 1;
                    Q[R++] = MP(xx, yy);
                }
            }
        }

        res = min(res , D1 - 1 + D2 - 1);
    }

    {
        int L = 0;
        int R = 0;

        int D1 = INF;
        int D2 = INF;

        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if (s[i][j] == '3')
                {
                    d3[i][j] = 0;
                    Q[R++] = MP(i,j);
                }
                else
                {
                    d3[i][j] = INF;
                }
            }
        }
        while (L < R)
        {
            int x = Q[L].first;
            int y = Q[L].second;

            if (s[x][y] == '2') D1 = min(D1 , d3[x][y]);
            if (s[x][y] == '1') D2 = min(D2 , d3[x][y]);

            ++L;
            FOR(dir,0,4)
            {
                int xx = x + dx[dir];
                int yy = y + dy[dir];
                if (ok(xx , yy) && d3[xx][yy] == INF)
                {
                    d3[xx][yy] = d3[x][y] + 1;
                    Q[R++] = MP(xx, yy);
                }
            }
        }

        res = min(res , D1 - 1 + D2 - 1);
    }

    FOR(i,0,n)
        FOR(j,0,m)
            if (s[i][j] == '.')
            {
                res = min(res , 1 + d1[i][j] - 1 + d2[i][j] - 1 + d3[i][j] - 1);
            }
    if (res >= INF - 1) res = -1;
    cout << res << endl;

    return 0;
}