

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:128777216")
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
#include <complex>
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
#define free adsgasdg


typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 7801;
const int MAX2 = 200000;
const int BASE = 1000000007;
const int MOD = 1000000007;
const int CNT = 1000;

double dp[7][2][2];

int main()
{
   // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int,int> > a(n);
    FOR(i,0,n)
    {
        cin >> a[i].first >> a[i].second;
    }

    int msk = 1;
    FOR(i,0,n)
    {
        msk *= 3;
    }
    double sp = 0.0;
    double res = 0.0;
    FOR(val,0,10007)
    {
        FOR(j,0,msk)
        {
            double p = 1.0;
            int c1 = 0;
            int c2 = 0;
            int mask = j;
            FOR(i,0,n)
            {
                int t = mask % 3;
                mask /= 3;
                double p1 = 0.0;
                if (t == 0 && a[i].first < val)
                {
                    p1 = 1.0 * (min(a[i].second, val - 1) - a[i].first + 1) / (a[i].second - a[i].first + 1);
                }
                if (t == 1 && a[i].first <= val && a[i].second >= val)
                {
                    p1 = 1.0 / (a[i].second - a[i].first + 1);
                }
                if (t == 2 && a[i].second > val)
                {
                    p1 = 1.0 * (a[i].second - max(a[i].first, val + 1) + 1) / (a[i].second - a[i].first + 1);
                }
                p *= p1;
                //cout << p1 << endl;
                if (t == 1) ++c1;
                if (t == 2) ++c2;
            }
           // cout << val  << ' ' << p << ' ' << j << endl;
            if (c2 <= 1 && c1 + c2 >= 2)
            {
               // cout << p << ' ' << val << endl;
               //if (c2 == 0)
                //sp += (c1 - 2) * p;
                sp += p;
                res += p * val;
            }
        }
    }
    //printf("%.10f\n" , sp);
    printf("%.12f\n" , res);

    return 0;
}