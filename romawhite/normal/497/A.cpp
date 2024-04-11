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
#define eps 1e-9
typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 7000;
const int BASE = 1000000000;

bool eq[1007];

char s[1007][1007];

int main()
{
    #ifndef ONLINE_JUDGE
     // freopen("in.txt", "r", stdin);
    #endif

    int n,m;
    cin >>n >> m;

    FOR(i,0,n)
    {
        scanf("%s" , &s[i]);
    }

    FOR(i,0,n - 1)
    {
        eq[i] = 1;
    }

    int res = 0;
    FOR(j,0,m)
    {
        bool ok = 1;
        FOR(i,0,n - 1)
        {
            if (eq[i] && s[i][j] > s[i + 1][j])
            {
                ok = 0;
            }
        }
        if (!ok)
        {
            ++res;
        }
        else
        {
            FOR(i,0,n - 1)
            {
                if (s[i][j] != s[i + 1][j])
                {
                    eq[i] = 0;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}