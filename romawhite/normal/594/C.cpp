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
const int MAX = 500007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;


int main()
{
    //freopen("in.txt" , "r" , stdin);

    int n , k;
    cin >> n >> k;
    vector<PII> A(n) , B(n);

    FOR(i,0,n)
    {
        int x1 , y1, x2 , y2;
        scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2);
        A[i].first = x1 + x2;
        A[i].second = y1 + y2;
    }



    sort(ALL(A));

    FOR(i,0,n)
    {
        B[i].first = A[i].second;
        B[i].second = i;
    }
    sort(ALL(B));

    VI C;
    Int res = 4LL * INF * INF;

    FOR(i,0,k + 1)
    {
        FOR(j,0,k + 1)
        {
            if (i + j > k) continue;
            C.clear();
            FOR(t,0,n)
            {
                if (B[t].second >= i && B[t].second <= n - j - 1)
                {
                    C.push_back(B[t].first);
                }
            }

            int c = k - i - j;
            int dx = (A[n - j - 1].first - A[i].first + 1) / 2;
            if (dx == 0) dx = 1;
            FOR(t,0,c + 1)
            {
                int dy = (C[C.size() - c + t - 1] - C[t] + 1) / 2;
                if (dy == 0) dy = 1;
                res = min(res , 1LL * dx * dy);
            }

        }
    }

    cout << res << endl;

    return 0;
}