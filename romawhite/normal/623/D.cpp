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
const int MAX = 107;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000009;
const int CNT = 0;

const double eps = 1e-9;

int p[MAX];
long double val[MAX];
int cnt[MAX];

set<pair<long double, int> > S;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	//n = 100;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	FOR(i,0,n)
	{
		cin >> p[i];

		//p[i] = 1;

		val[i] = log(1.0 - 0.01 * p[i]);
		cnt[i] = 1;
		S.insert(MP(-(1 - exp(val[i] / cnt[i] * (cnt[i] + 1)))/(1 - exp(val[i])) , i));
	}

	long double res = 0;

	long double P = 1;
	FOR(i,0,n)
	{
		P *= (1 - exp(val[i]));
	}
	res += P * n;
	FOR(it,0,1000000)
	{
		int v = S.begin()->second;
		long double prev = P;
		S.erase(S.begin());

		P /= 1 - exp(val[v]);

		val[v] /= cnt[v];
		++cnt[v];
		val[v] *= cnt[v];


		P *= 1 - exp(val[v]);

		res += (P - prev) * (n + it + 1);
		S.insert(MP(-(1 - exp(val[v] / cnt[v] * (cnt[v] + 1)))/(1 - exp(val[v])) , v));
		//cout << P << endl;
	}
	printf("%.10f\n" , (double)res);



	return 0;
}