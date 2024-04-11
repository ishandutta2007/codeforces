#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
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
const int MAX = 100007;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int g, inv;

int gcd(int a , int b)
{
	if (!b) return a;
	return gcd(b , a % b);
}

Int solve(int b1 , int c1 , int b2 , int c2)
{
	Int b = ((b2 - b1) % c2 + c2) % c2;

	if (b % g != 0) return 1LL * INF * INF;
	b /= g;
	Int k = 1LL * inv * b % (c2 / g);
	return k * c1 + b1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n , m , k;
	cin >> n >> m >> k;

	g = gcd(2 * n , 2 * m);


	FOR(i,0,2 * m)
	{
		if (2LL * n / g * i % (2 * m / g) == 1)
		{
			inv = i;
			break;
		}
	}
	FOR(i,0,k)
	{
		int x , y;
		scanf("%d%d" , &x , &y);

		Int res = 1LL * INF * INF;
		res = min(res , solve(x , 2 * n , y , 2 * m));
		res = min(res , solve(2 * n - x , 2 * n , y , 2 * m));
		res = min(res , solve(x , 2 * n , 2 * m - y , 2 * m));
		res = min(res , solve(2 * n - x , 2 * n , 2 * m - y , 2 * m));

		if (res == 1LL * INF * INF) res = -1;
		cout << res << endl;
	}

    return 0;
}