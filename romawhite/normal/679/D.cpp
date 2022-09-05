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

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 507;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

int d[MAX][MAX];

vector<PII> C[MAX];

double p2[MAX];

int deg[MAX];

pair<int, double> A[MAX];

int To[MAX];

int main()
{
	//freopen("in.txt" , "r" , stdin);

	int n , m;
	cin >> n >> m;

	//n = 400;

	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}

	FOR(i,0,m)
	{
		int a , b;
		scanf("%d %d" , &a , &b);
		--a; --b;
		d[a][b] = d[b][a] = 1;
		deg[a] ++ ;
		deg[b] ++ ;
	}
	/*FOR(i,0,n)
	{
		FOR(j,i - 1, i + 2)
		{
			if (j < 0 || j >= n) continue;
			if (i == j)
				continue;
			d[i][j] = 1;
			++ deg[i];
		}
	}*/

	FOR(k,0,n)
	{
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
			}
		}
	}

	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			C[i].push_back(MP(d[i][j] , j));
		}
		sort(ALL(C[i]));
	}

	double res = 0;



	FOR(i,0,n)
	{
		int ptr = 0;
		double P = 0;
		while (ptr < n)
		{
			int add = 1;
			while (ptr + add < n && C[i][ptr + add].first == C[i][ptr].first) ++add;

			double pp = 1.0 / n;
			FILL(p2, 0);

			FOR(j,ptr , ptr + add)
			{
				int v = C[i][j].second;
				FOR(k,0,n)
				{
					if (d[v][k] == 1)
					{
						p2[k] += 1.0 / n / deg[v];
					}
				}
			}

			int szTo = 0;
			double sum = 0;
			FOR(j,0,n)
			{
				if (p2[j] > 1e-6)
				{
					To[szTo ++] = (j);
					sum += p2[j];
				}
			}

			FOR(j,0,n)
			{
				int szA = 0;
				double cur = 0;
				FOR(k,0,szTo)
				{
					int to = To[k];
					A[szA ++] = (MP(d[j][to] , p2[to]));
				}

				sort(A , A + szA);

				int ptr2 = 0;
				while (ptr2 < szA)
				{
					int add2 = 1;
					while (ptr2 + add2 < szA && A[ptr2].first == A[ptr2 + add2].first) ++ add2;
					cur += A[ptr2 + add2 - 1].second;
					ptr2 += add2;
				}

				pp = max(pp , cur);
			}

			//cout << ptr << ' ' << pp << endl;

			P += pp;
			ptr += add;
		}
		//cout << endl;
		res = max(res , P);


	}

	printf("%.10f\n" , res);

	//cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;

    return 0;
}