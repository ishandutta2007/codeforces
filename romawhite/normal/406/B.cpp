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

const int INF = 1000000000;
const Int INF2 = 5LL * INF * INF;

const int MAXN = 1000000;

bool a[1000007];

int fr[1000007];
int fs = 0;
int res[1000007];
int rs = 0;

int main()
{
    int n;
    cin >> n;

    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        a[x - 1] = 1;
    }

    FOR(i,0,MAXN / 2)
    {
        if (!a[i] && !a[MAXN - i - 1])
        {
            fr[fs++] = i;
        }
    }

    FOR(i,0,MAXN / 2)
    {
        if (a[i] && !a[MAXN - i - 1])
        {
            res[rs++] = MAXN - i - 1;
        }
        if (!a[i] && a[MAXN - i - 1])
        {
            res[rs++] = i;
        }
        if (a[i] && a[MAXN - i - 1])
        {
            res[rs++] = fr[fs - 1];
            res[rs++] = MAXN - fr[fs - 1] - 1;
            fs--;
        }
    }

    cout << rs << endl;
    FOR(i,0,rs)
    {
        printf("%d " , res[i] + 1);
    }

}