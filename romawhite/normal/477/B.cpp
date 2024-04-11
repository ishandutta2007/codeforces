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

vector<int> a[10007];

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b , a % b);
}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    int n,k;
    cin >> n >> k;

    int p = 1;
    FOR(i,0,n)
    {
        FOR(j,0,3)
        {
            a[i].push_back(p);
            p += 2;
        }
    }

    p = 2;
    FOR(i,0,n)
    {
        while (1)
        {
            bool ok = 1;
            FOR(j,0,3)
            {
                if (gcd(p, a[i][j]) != 1)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                a[i].push_back(p);
                //cout << i << ' ' << p << endl;
                p += 2;
                break;
            }
            p += 2;
        }
    }

    int m = 0;
    FOR(i,0,n)
    {
        FOR(j,0,4)
        {
            a[i][j] *= k;
        }
    }

    FOR(j,0,4)
    {
        m = max(m, a[n - 1][j]);
    }

    cout << m << endl;
    FOR(i,0,n)
    {
        FOR(j,0,4)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}