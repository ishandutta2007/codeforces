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
const int MAX = 1024;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n;
PII A[MAX];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    scanf("%d", &n);
    FOR (i,0,n)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        A[i] = MP(a, b);
    }
    int res = INF;
    FOR (h,1,MAX)
    {
        int sum = 0, ok = 1;
        FOR (i,0,n)
        {
            int c = INF;
            if (A[i].first <= h)
                c = min(c, A[i].second);
            if (A[i].second <= h)
                c = min(c, A[i].first);
            if (c >= INF)
                ok = 0;
            sum += c;
        }
        if (ok)
            res = min(res, sum * h);
    }
    cout << res << endl;






    return 0;
}