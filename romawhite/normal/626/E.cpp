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
const int BASE = 1000000000;
const int MAX = 200007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int a[MAX];
int n;
Int s[MAX];

Int sum(int l , int r)
{
	return s[r] - (l ? s[l - 1] : 0);
}

PII F(double X)
{
	FOR(i,1,n - 1)
	{
		int c = min(n - 1 - i, i);
		int L = 0;
		int R = c;
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			if (a[i - M] + a[n - M] - 2 * a[i] - 2 * X > 0)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		if (sum(i - L , i - 1) + sum(n - L, n - 1) - 2LL * L * a[i] >= (2 * L + 1) * X)
			return MP(i, L);
		if (sum(i - R , i - 1) + sum(n - R, n - 1) - 2LL * R * a[i] >= (2 * R + 1) * X)
			return MP(i, R);
	}
	return MP(-1, -1);
}

int main()
{
    //freopen("in.txt",  "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	cin >> n;

	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
	}

	if (n <= 2)
	{
		cout << 1 << endl;
		cout << a[0] << endl;
		return 0;
	}

	sort(a , a + n);
	s[0] = a[0];
	FOR(i,1,n)
	{
		s[i] = s[i - 1] + a[i];
	}


	double L = 0;
	double R = 10000000;
	FOR(it,0,74)
	{
		double X = (L + R) / 2;
		PII p = F(X);

		if (p.first == -1)
		{
			R = X;
		}
		else
		{
			L = X;
		}
	}

	PII p = F(L);

	cout << 2 * p.second + 1 << endl;
	FOR(i,p.first-p.second, p.first + 1)
	{
		printf("%d " , a[i]);
	}
	FOR(i,n - p.second, n)
	{
		printf("%d " , a[i]);
	}
	printf("\n");


    return 0;
}