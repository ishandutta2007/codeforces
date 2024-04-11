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
const int MAX = 507;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

vector<vector<bool> > A[62][2];

int n , m;

unsigned AA[MAX][MAX / 32 + 7];
unsigned BB[MAX][MAX / 32 + 7];

vector<vector<bool> > mult(vector<vector<bool> > a , vector<vector<bool> > b)
{
	FILL(AA , 0);
	FILL(BB , 0);
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if (a[i][j])
			{
				AA[i][j / 32] |= (1 << (j % 32));
			}
			if (b[i][j])
			{
				BB[j][i / 32] |= (1 << (i % 32));
			}
		}
	}

	vector<vector<bool> > C = a;

	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			C[i][j] = 0;
			FOR(k,0,n / 32 + 1)
			{
				if ((AA[i][k] & BB[j][k]) != 0)
				{
					C[i][j] = 1;
					break;
				}
			}
		}
	}
	return C;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);


	cin >> n >> m;

	FOR(i,0,62)
	{
		FOR(j,0,2)
		{
			A[i][j] = vector<vector<bool> >(n , vector<bool>(n,0));
		}
	}

	FOR(i,0,m)
	{
		int a , b , t;
		scanf("%d%d%d" , &a , &b, &t);
		-- a; -- b;
		A[0][t][a][b] = 1;
	}

	FOR(j,1,62)
	{
		A[j][0] = mult(A[j - 1][0] , A[j - 1][1]);
		A[j][1] = mult(A[j - 1][1] , A[j - 1][0]);
	}

	Int len = 0;
	int st = 0;
	vector<vector<bool> > C(n , vector<bool>(n, 0));
	FOR(i,0,n)
	{
		C[i][i] = 1;
	}

	RFOR(i,62,0)
	{
		vector<vector<bool> > D = mult(C , A[i][st]);
		bool ok = 0;
		FOR(x,0,n)
			FOR(y,0,n)
				if (D[x][y])
				{
					ok = 1;
					break;
				}
		if (ok)
		{
			len += (1LL << i);
			C = D;
			st ^= 1;
		}
	}
	if (len > 1000000000000000000LL)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << len << endl;
	}

    return 0;
}