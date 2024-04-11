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
const int MAX = 100007;
const int MAXV = 1200;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;

Int bpow(Int a, Int k)
{
	Int res = 1;
	a %= MOD;
	while (k)
	{
		if (k & 1)
		{
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		k /= 2;
	}
	return res;
}

int main()
{
    //freopen("in.txt",  "r", stdin);

	int k;
	cin >> k;

	Int q = 2;

	bool ones = 1;

	bool even = 1;

	Int MOD2 = (MOD - 1) * 2;

	Int pwp = 1;

	FOR(i,0,k)
	{
		Int x;
		scanf("%I64d" , &x);
		if (x != 1) ones = 0;

		if (x % 2 == 0 && even)
		{
			even = 0;
			pwp *= (x / 2) % MOD2;
			pwp %= MOD2;
		}
		else
		{
			pwp *= x % MOD2;
			pwp %= MOD2;
		}


		q = bpow(q , x);
	}

	if (even)
	{
		pwp --;
		pwp /= 2;
	}


	Int p;
	if (!even)
	{
		p = (bpow(4 , pwp) + 2) % MOD;
		p *= bpow(6 , MOD - 2);
		p %= MOD;
	}
	else
	{
		p = (bpow(4 , pwp) - 1 + MOD) % MOD;
		p *= bpow(3 , MOD - 2);
		p %= MOD;
	}




	q *= (MOD + 1) / 2;
	q %= MOD;

	if (ones)
	{
		cout << "0/1" << endl;
		return 0;
	}

	cout << p << '/' << q << endl;

    return 0;
}