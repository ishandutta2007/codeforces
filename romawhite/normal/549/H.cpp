#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int main()
{
    //  freopen("in.txt","r",stdin);

    double L = 0;
    double R = 1e17;

    double a , b , c , d;
    cin >> a >> b >> c >> d;

    FOR(it,0,147)
    {
        double X = (L + R) / 2;
        double a1 = a - X;
        double a2 = a + X;
        double b1 = b - X;
        double b2 = b + X;
        double c1 = c - X;
        double c2 = c + X;
        double d1 = d - X;
        double d2 = d + X;

        double L1 = min(min(a1 * d1, a1 * d2) , min(a2 * d1 , a2 * d2));
        double R1 = max(max(a1 * d1, a1 * d2) , max(a2 * d1 , a2 * d2));

        double L2 = min(min(b1 * c1, b1 * c2) , min(b2 * c1 , b2 * c2));
        double R2 = max(max(b1 * c1, b1 * c2) , max(b2 * c1 , b2 * c2));

        if (L2 > R1 || L1 > R2)
        {
            L = X;
        }
        else
        {
            R = X;
        }
    }

    printf("%.15f\n" , L);

    return 0;
}