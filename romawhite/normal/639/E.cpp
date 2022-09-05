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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 250007;
const int MAX2 = 2000000;
const int BASE = 10;
const int ST = 1000000007;
const int CNT = 100;

int p[MAX];
int t[MAX];


bool Comp(PII a , PII b)
{
	return 1LL * a.first * b.second > 1LL * a.second * b.first;
}

bool Eq(PII a, PII b)
{
	return 1LL * a.first * b.second == 1LL * a.second * b.first;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);

	int n;
	cin >> n;
	FOR(i,0,n)
	{
		scanf("%d" , &p[i]);
	}

	Int T = 0;

	FOR(i,0,n)
	{
		scanf("%d" , &t[i]);
		T += t[i];
	}

	vector<PII > A;
	FOR(i,0,n)
	{
		A.push_back(MP(p[i] , t[i]));
	}

	sort(ALL(A), Comp);

	double L = 0;
	double R = 1;
	FOR(it,0,47)
	{
		double X = (L + R) / 2;


		int pos = 0;

		Int time = 0;

		vector<pair<int, pair<double, double> > > Q;

		while (pos < n)
		{
			int add = 1;
			while (pos + add < n && Eq(A[pos + add] , A[pos])) ++add;
			Int sum = 0;
			FOR(i,pos, pos + add)
			{
				sum += A[i].second;
			}

			FOR(i,pos , pos + add)
			{
				double mn = A[i].first * (1.0 - X * (time + sum) / T);
				double mx = A[i].first * (1.0 - X * (time + A[i].second) / T);
				Q.push_back(MP(A[i].first , MP(mn , mx)));
			}
			time += sum;
			pos += add;
		}

		sort(ALL(Q));


		/*FOR(i,0,n)
		{
			cout << Q[i].first << ' ' << Q[i].second.first << ' ' << Q[i].second.second << endl;
		}*/

		bool ok = 1;
		double Mx = -1;
		pos = 0;
		while (pos < n)
		{
			if (!ok) break;
			int add = 1;
			while (pos + add < n && Q[pos + add].first == Q[pos].first) ++add;
			FOR(i,pos , pos + add)
			{
				if (Q[i].second.first < Mx)
				{
					ok = 0;
					break;
				}
			}
			FOR(i, pos, pos + add)
			{
				Mx = max(Mx, Q[i].second.second);
			}
			pos += add;
		}

		if (ok)
		{
			L = X;
		}
		else
		{
			R = X;
		}
	}

	printf("%.10f\n" , L);


	return 0;
}