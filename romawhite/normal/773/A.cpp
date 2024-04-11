#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 128;
const int MAX2 = 7000;
const int BASE = 1000000000;

Int x, y, p, q;

int main()
{
	//freopen("in.txt", "r", stdin);

	int T;
	cin >> T;
	FOR (test,0,T)
	{
		cin >> x >> y >> p >> q;

		if (x*q == y*p)
		{
			cout << 0 << endl;
			continue;
		}
		if (q == p || p == 0)
		{
			cout << -1 << endl;
			continue;
		}
		Int Min = (y-x)/(q-p);
		if ((y-x)%(q-p) != 0)
			++ Min;
		Min = max(Min, (x+p-1)/p);
		Min = max(Min, (y+q-1)/q);

		cout << Min * q - y << endl;
	}

    return 0;
}