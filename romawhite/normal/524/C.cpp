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
const int MAX = 5007;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n, k, q;
int A[MAX];
VI Q[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif


    scanf("%d %d", &n, &k);
    FOR (i,0,n)
    {
        scanf("%d", &A[i]);
        FOR (j,1,k+1)
            Q[j].PB(A[i] * j);
    }
    FOR (j,1,k+1)
        sort(ALL(Q[j]));
    scanf("%d", &q);
    FOR (i,0,q)
    {
        int x;
        scanf("%d", &x);
        int res = INF;
        FOR (c1,1,k+1)
        {
            FOR (j,0,SZ(Q[c1]))
                if (Q[c1][j] == x)
                    res = min(res, c1);
            FOR (c2,1,k+1)
            {
                if (c1+c2 > k)
                    break;
                int pos = SZ(Q[c2])-1;
                FOR (j,0,SZ(Q[c1]))
                {
                    while (pos >= 0 && Q[c1][j] + Q[c2][pos] > x)
                        -- pos;
                    if (pos >= 0 && Q[c1][j] + Q[c2][pos] == x)
                        res = min(res, c1 + c2);
                }
            }
        }
        if (res >= INF)
            res = -1;
        printf("%d\n", res);
    }







    return 0;
}