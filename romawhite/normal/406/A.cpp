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

const int MAXN = 1007;

int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
bool A[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;
    FOR(i,0,n)
        FOR(j,0,n)
        {
            int x;
            scanf("%d" , &x);
            A[i][j] = x;
        }

    int res = 0;

    FOR(i,0,n)
    {
        d[i] = A[i][i];
        res ^= d[i];
    }

    int q;
    cin >> q;
    FOR(i,0,q)
    {
        int t;
        scanf("%d" , &t);
        if (t == 1 || t == 2)
        {
            int i;
            scanf("%d" , &i);
            res ^= 1;
        }
        if (t == 3)
        {
            printf("%d" , res);
        }
    }
    cout << endl;

}