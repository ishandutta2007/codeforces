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
const int MAX = 27;
const int MAXV = 1200;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 999999999;

map<Int, Int> M;

int main()
{
    //freopen("in.txt",  "r", stdin);

	int q;
	cin >> q;

	FOR(i,0,q)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			Int u , v, w;
			cin >> u >> v >> w;

			while (u != v)
			{
				if (u < v) swap(u , v);
				M[u] += w;
				u /= 2;
			}

		}
		else
		{
			Int u , v;
			cin >> u >> v;

			Int res = 0;
			while (u != v)
			{
				if (u < v) swap(u , v);
				res += M[u];
				u /= 2;
			}

			cout << res << endl;
		}
	}

    return 0;
}