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

int p[MAX];
int s[MAX];

VI A;
Int sum[MAX];

int P , S;
int n , c;

bool F(int X)
{
	Int R = 0;

	int pos1 = lower_bound(ALL(A) , X + c) - A.begin();
	R += (SZ(A) - pos1) * 1LL * c;
	int pos2 = lower_bound(ALL(A) , X) - A.begin();
	R += (sum[pos1] - sum[pos2]) - 1LL * (pos1 - pos2) * X;

	R += P - X;

	return R <= S;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	cin >> n >> c;
	FOR(i,0,n)
	{
		scanf("%d" , &p[i]);
	}
	FOR(i,0,n)
	{
		scanf("%d" , &s[i]);
	}

	Int res = 0;

	FOR(i,0,n)
	{
		FOR(j,0,SZ(A))
			sum[j + 1] = sum[j] + A[j];

		int L = 0;
		int R = INF;

		P = p[i];
		S = s[i];

		while (R - L > 1)
		{
			int X = (L + R) / 2;
			if (F(X)) R = X;
			else L = X;
		}
		if (F(L)) R = L;

		int add = P - R;
		P -= add;
		S -= add;

		FOR(h,0,SZ(A))
		{
			if (A[h] <= R) continue;
			int add = min(c , A[h] - R);
			S -= add;
			A[h] -= add;
		}

		if (P < R)
		{
			S += R - P;
			P = R;
		}

		A.push_back(P);

		FOR(i,0,SZ(A) - 1)
			if (A[i] >= P)
			{
				RFOR(j,SZ(A) - 1 , i)
					A[j + 1] = A[j];
				A[i] = P;
				break;
			}

		FOR(i,0,SZ(A))
		{
			if (R > 0 && A[i] == R && S > 0)
			{
				A[i] --;
				S --;
			}
		}

		res += s[i] - S;
	}

	cout << res << endl;

    return 0;
}