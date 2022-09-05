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
const int MAX = 5007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int a[MAX];
int b[MAX];
int s[MAX];

int main()
{
    //freopen("in.txt",  "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	FOR(i,0,n)
	{
		cin >> a[i];
	}

	sort(a , a + n);
	FOR(i,0,n)
	{
		FOR(j,i + 1 , n)
		{
			b[a[j] - a[i]]++;
		}
	}
	s[0] = b[0];
	FOR(i,1,MAX)
	{
		s[i] = s[i - 1] + b[i];
	}

	Int res = 0;

	FOR(i,3,MAX)
	{
		FOR(j,0,i)
		{
			res += 1LL * b[i] * b[j] * s[i - j - 1];
		}
	}

	Int all = n * (n - 1) / 2;

	printf("%.10f\n" , (double)res / all / all / all);

    return 0;
}