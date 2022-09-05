#define _CRT_SECURE_NO_WARNINGS
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
const int MAX = 1000007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int CNT = 800;

const int MOD = 1000000007;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	vector<PII > A;
	FOR(i,0,n)
	{
		int x , y;
		cin >> x >> y;
		A.push_back(MP(x , y));
	}

	double res = 1e47;

	FOR(i,0,n)
	{
		PII x = A[i];
		PII a = A[(i - 1 + SZ(A)) % SZ(A)];
		PII b = A[(i + 1) % SZ(A)];

		Int S = abs(1LL * (a.first - x.first) * (b.second - x.second) - 1LL * (a.second-x.second) * (b.first - x.first));
		Int d2 = 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);


		double d = 1.0 * S / sqrt(d2) / 2;
		res = min(res , d);
	}

	printf("%.10f\n" , res);

    return 0;
}