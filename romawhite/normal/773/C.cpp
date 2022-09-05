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
const int MAX = 207;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int c[47][2];
int C[47][2];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;

	FOR(i,0,n)
	{
		Int x;
		cin >> x;
		FOR(j,0,47)
		{
			if (x == (1LL << j))
			{
				++ C[j][0];
			}
			if (x > (1LL << j) && x < (2LL << j))
			{
				++ C[j][1];
			}
		}
	}

	int any = 0;

	FOR(k,1,n + 1)
	{
		int a = k;
		int b = 0;

		bool ok = 1;


		FOR(i,0,44)
		{
			c[i][0] = C[i][0];
			c[i][1] = C[i][1];

			int mn = min(a + b , c[i][0]);

			if (i == 0 && mn != a)
			{
				ok = 0;
				break;
			}

			int close = a + b - mn;
			int close1 = min(b , close);
			b -= close1;
			close -= close1;

			int close2 = min(a , close);
			close -= close2;
			a -= close2;

			c[i][0] -= mn;

			c[i][0] += c[i][1];

			if (c[i][0] > a)
			{
				ok = 0;
				break;
			}

			a -= c[i][0];
			b += c[i][0];

		}

		if (ok)
		{
			cout << k << ' ';
			any = 1;
		}
	}

	if (!any)
	{
		cout << -1 << endl;
	}


    return 0;
}