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
const int MAX = 1000007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int a[MAX];
int b[MAX];

int MA[MAX][21];
int MB[MAX][21];

int Len[MAX];

int get(int L, int R)
{
	int len = Len[R - L + 1];
	return min( max(MA[L][len] , MA[R - (1 << len) + 1][len]) , min(MB[L][len] , MB[R - (1 << len) + 1][len]));
}

int R[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);


	Len[1] = 0;
	FOR(i,2,MAX)
	{
		Len[i] = Len[i / 2] + 1;
	}

	int n , k;
	cin >> n >> k;

	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
		a[i] *= 100;
	}
	FOR(i,0,n)
	{
		scanf("%d" , &b[i]);
	}

	FOR(i,0,n)
	{
		MA[i][0] = a[i];
		MB[i][0] = b[i];
	}
	FOR(j,1,21)
	{
		FOR(i,0,n)
		{
			MA[i][j] = MA[i][j - 1];
			MB[i][j] = MB[i][j - 1];
			if (i + (1 << j) <= n)
			{
				MA[i][j] = max(MA[i][j] , MA[i + (1 << (j - 1))][j - 1]);
				MB[i][j] = min(MB[i][j] , MB[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	FOR(i,0,n)
	{
		int pos = i;
		RFOR(j,21, 0)
		{
			if (MA[pos][j] < MB[pos][j])
			{
				pos += (1 << j);
				if (pos > n) pos = n - 1;
			}
		}

		R[i] = -1;

		FOR(j,pos - 5 , pos + 5)
		{
			if (j >= i && j < n)
			{
				R[i] = max(R[i] , get(i, j));
			}
		}
	}

	sort(R , R + n);


	double p = 1.0 * k / n;
	double res = 0;
	FOR(i,0,n)
	{
		res += R[i] * p;
		if (n == i + k) break;
		p *= 1.0 * (n - i - k) / (n - i - 1);
	}

	printf("%.10f\n" , res);

    return 0;
}