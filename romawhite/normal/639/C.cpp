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

Int b[MAX];
Int c[MAX];
int sz;

bool Less()
{
	RFOR(i,sz,0)
	{
		if (b[i] < c[i]) return 1;
		if (b[i] > c[i]) return 0;
	}
	return 0;
}

void sub1()
{
	FOR(i,0,sz)
	{
		b[i] -= c[i];
		if (b[i] < 0)
		{
			b[i] += 2;
			b[i + 1]--;
		}
	}
}

void sub2()
{
	FOR(i,0,sz)
	{
		c[i] -= b[i];
		if (c[i] < 0)
		{
			c[i] += 2;
			c[i + 1]--;
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);

	int n , k;
	cin >> n >> k;
	++n;
	VI a(n);
	FOR(i,0,n)
	{
		scanf("%d" , &a[i]);
	}

	FOR(i,0,n)
	{
		if (a[i] > 0) b[i] = a[i];
		else c[i] = -a[i];
	}

	sz = n + 47;
	Int t = 0;
	FOR(i,0,sz)
	{
		b[i] += t;
		t = b[i] / 2;
		b[i] %= 2;
	}

	t = 0;
	FOR(i,0,sz)
	{
		c[i] += t;
		t = c[i] / 2;
		c[i] %= 2;
	}


	if (!Less())
	{
		int res = 0;

		sub1();


		int sum = 0;
		FOR(i,0,sz)
			sum += b[i];

		Int val = 0;
		RFOR(i,sz,0)
		{
			val = val * 2 + b[i];
			sum -= b[i];
			if (val > 1e12)
				val = 1e12;

			if (i < n && sum == 0)
			{
				Int r = a[i] - val;

				//cout << i << ' ' << r << ' ' << sum << ' ' << val << endl;

				if (r == 0 && i == n - 1) continue;
				if (r >= -k && r <= k)
				{
					++res;
				}
			}
		}
		cout << res << endl;
	}
	else
	{
		int res = 0;

		sub2();

		int sum = 0;
		FOR(i,0,sz)
			sum += c[i];

		Int val = 0;
		RFOR(i,sz,0)
		{
			val = val * 2 + c[i];
			sum -= c[i];
			if (val > 1e12)
				val = 1e12;

			if (i < n && sum == 0)
			{
				Int r = a[i] + val;
				if (r == 0 && i == n - 1) continue;
				if (r >= -k && r <= k)
				{
					++res;
				}
			}
		}
		cout << res << endl;
	}



	return 0;
}