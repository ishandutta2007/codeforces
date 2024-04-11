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
const int MAX = 3007;
const int MAX2 = 7000;
const int BASE = 1000000000;
const Int INF2 = 10000000000000007LL;

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    Int A , B , n;
    cin >> A >> B >> n;
    FOR(i,0,n)
    {
        Int l, t , m;
        scanf("%I64d%I64d%I64d" , &l, &t, &m);
        --l;
        Int a = A + l * B;
        if (a > t)
        {
            printf("-1\n");
            continue;
        }
        Int L = 0;
        Int R = 1000007;
        while (R - L > 1)
        {
            Int X = (L + R) / 2;
            Int F = (X + 1) * a + X * (X + 1) / 2 * B;
            Int Mx = a + X * B;
            if (Mx > t || (F + m - 1) / m > t)
            {
                R = X;
            }
            else
            {
                L = X;
            }
        }
        printf("%I64d\n" , l + 1 + L);
    }

    return 0;
}