#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 800;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	double r;
	cin >> n >> r;
	double res = Pi * r * r;
	double alpha = 2 * Pi / n;

	res -= n * (Pi * r * r / n - 0.5 * r * r * sin(alpha));

	double x1 = r;
	double y1 = 0;
	double x2 = r * cos((n - 1) / 2 * alpha);
	double y2 = r * sin( (n - 1) / 2 * alpha );
	double x3 = r * cos(alpha);
	double y3 = r * sin(alpha);
	double x4 = r * cos((n + 3) / 2 * alpha);
	double y4 = r * sin((n + 3) / 2 * alpha);


	double a1 = y2 - y1;
	double b1 = x1 - x2;
	double c1 = a1 * x1 + b1 * y1;

	double a2 = y4 - y3;
	double b2 = x3 - x4;
	double c2 = a2 * x3 + b2 * y3;


	double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
	double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

	double S = 0.5 * abs((x1 - x) * (y3 - y) - (x3 - x) * (y1 - y));

	res -= S * n;

	printf("%.10f\n" , res);

    return 0;

}