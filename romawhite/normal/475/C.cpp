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

char s[1007][1007];
char ss[1007][1007];

int main()
{
   // freopen("in.txt" , "r" , stdin);
  //  freopen("out.txt" , "w" , stdout);

    int n,m;
    cin >> n >> m;

    FOR(i,0,n)
    {
        scanf("%s" , s[i]);
    }

    int res = INF;

    {
        int x = -1;
        int y = -1;
        FOR(i,0,n)
        {
            if (x != -1) break;
            FOR(j,0,m)
            {
                if (s[i][j] == 'X')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if (x == -1)
        {
            cout << 0 << endl;
            return 0;
        }
        int len = 0;
        int xx = x;
        while (xx < n && s[xx][y] == 'X')
        {
            ++xx;
            ++len;
        }
        vector<pair<int,int> > b;
        bool last = 0;
        FOR(i,x,n)
        {
            int l = -1;
            FOR(j,0,m)
            {
                if (s[i][j] == 'X')
                {
                    l = j;
                    break;
                }
            }
            if (l == -1)
            {

                if (b.size())
                {
                    last = 1;
                }
            }
            else
            {
                if (last)
                {
                    cout << -1 << endl;
                    return 0;
                }
                int r = l;
                while (r < m && s[i][r] == 'X')
                {
                    ++r;
                }
                FOR(j,r,m)
                {
                    if (s[i][j] == 'X')
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
                b.push_back(MP(l,r - 1));
            }
        }

       // FOR(i,0,b.size())
       // {
       //     cout << b[i].first << " - " << b[i].second << endl;
       // }
        //cout << len << endl;
        int h;
        bool ok = 1;
        FOR(i,0,len)
        {
            if (b[i].first != b[0].first)
            {
                ok = 0;
            }
            if (b[b.size() - 1 - i].second != b.back().second)
            {
                ok = 0;
            }
        }
        //cout << ok << endl;
        FOR(i,0,n)
        {
                FOR(j,0,m)
                {
                    ss[i][j] = '.';
                }
        }

        if (ok)
        {
            int L = b[0].first;
            int R = b[0].second;
            if (b.size() == len)
            {
                res = min(res , len);
                //cout << res << endl;
            }
            else
            {
                h =  -b[len].first + b[0].second + 1;
                if (h >= 1)
                {
                    int xx = x;
                    int yy = y;
                    FOR(ii,0,len)
                    {
                        FOR(jj,0,h)
                        {
                            ss[xx+ii][yy + jj]='X';
                        }
                    }
                    while (1)
                    {
                        if (xx + len < n && s[xx + len][yy] == 'X')
                        {
                            FOR(jj,0,h)
                            {
                                ss[xx + len][yy + jj] = 'X';
                            }
                            ++xx;
                        }
                        else
                        {
                            if (yy + h < m && s[xx][yy + h] == 'X')
                            {
                                FOR(ii,0,len)
                                {
                                    ss[xx + ii][yy + h] = 'X';
                                }
                                ++yy;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }

        bool g = 1;
        FOR(i,0,n)
        {
                FOR(j,0,m)
                {
                    if (s[i][j] != ss[i][j])
                    {
                        g = 0;
                    }
                }
        }

       /* FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                cout << ss[i][j];
            }
            cout << endl;
        }

        cout << len << ' ' << h << endl;*/
        if (g)
        {
            res = min(res , len * h);
        }

    }

    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            ss[j][i] = s[i][j];
        }
    }
    swap(n,m);
    FOR(i,0,n)
    {
            FOR(j,0,m)
            {
                s[i][j] = ss[i][j];
            }
    }
//cout << 'r' << res << endl;
/*cout << n << ' ' << m << endl;
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cout << s[i][j];
        }
        cout << endl;
    }*/

     {
        int x = -1;
        int y = -1;
        FOR(i,0,n)
        {
            if (x != -1) break;
            FOR(j,0,m)
            {
                if (s[i][j] == 'X')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if (x == -1)
        {
            cout << 0 << endl;
            return 0;
        }
        int len = 0;
        int xx = x;
        while (xx < n && s[xx][y] == 'X')
        {
            ++xx;
            ++len;
        }
        vector<pair<int,int> > b;
        bool last = 0;
        FOR(i,x,n)
        {
            int l = -1;
            FOR(j,0,m)
            {
                if (s[i][j] == 'X')
                {
                    l = j;
                    break;
                }
            }
            if (l == -1)
            {
                if (b.size())
                {
                    last = 1;
                }
            }
            else
            {
                if (last)
                {
                    cout << -1 << endl;
                    return 0;
                }
                int r = l;
                while (r < m && s[i][r] == 'X')
                {
                    ++r;
                }
                FOR(j,r,m)
                {
                    if (s[i][j] == 'X')
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
                b.push_back(MP(l,r - 1));
            }
        }

       /* FOR(i,0,b.size())
        {
            cout << b[i].first << " - " << b[i].second << endl;
        }*/

        int h;
        bool ok = 1;
        FOR(i,0,len)
        {
            if (b[i].first != b[0].first)
            {
                ok = 0;
            }
            if (b[b.size() - 1 - i].second != b.back().second)
            {
                ok = 0;
            }
        }
        //cout << ok << endl;
        FOR(i,0,n)
        {
                FOR(j,0,m)
                {
                    ss[i][j] = '.';
                }
        }

        if (ok)
        {
            int L = b[0].first;
            int R = b[0].second;
            if (b.size() == len)
            {
                res = min(res , len);
            }
            else
            {
                h =  -b[len].first + b[0].second + 1;
                if (h >= 1)
                {
                    int xx = x;
                    int yy = y;
                    FOR(ii,0,len)
                    {
                        FOR(jj,0,h)
                        {
                            ss[xx+ii][yy + jj]='X';
                        }
                    }
                    while (1)
                    {
                        if (xx + len < n && s[xx + len][yy] == 'X')
                        {
                            FOR(jj,0,h)
                            {
                                ss[xx + len][yy + jj] = 'X';
                            }
                            ++xx;
                        }
                        else
                        {
                            if (yy + h < m && s[xx][yy + h] == 'X')
                            {
                                FOR(ii,0,len)
                                {
                                    ss[xx + ii][yy + h] = 'X';
                                }
                                ++yy;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }

        bool g = 1;
        FOR(i,0,n)
        {
                FOR(j,0,m)
                {
                    if (s[i][j] != ss[i][j])
                    {
                        g = 0;
                    }
                }
        }

       /* FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                cout << ss[i][j];
            }
            cout << endl;
        }

        cout << len << ' ' << h << endl;*/
        if (g)
        {
            res = min(res , len * h);
        }

    }

    if (res == INF) res = -1;

    cout << res << endl;

    return 0;
}