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

    double x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 -= x1;
    y2 -= y1;

    double vm , t;
    cin >> vm >> t;

    pair<double, double> v, w;
    cin >> v.first >> v.second;
    cin >> w.first >> w.second;

    double L = 0;
    double R = INF;

    FOR(it,0,447)
    {
        double X = (L + R) / 2;
        double x = x2;
        double y = y2;

        x -= v.first * min(t , X);
        y -= v.second * min(t , X);
        x -= w.first * max(0.0, X - t);
        y -= w.second * max(0.0, X - t);

        if (x * x + y * y <= vm * vm * X * X)
            R = X;
        else L = X;
    }

    printf("%.10f\n" , L);


    return 0;
}