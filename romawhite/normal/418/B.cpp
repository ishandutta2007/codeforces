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
const double Pi = acos(-1.0);

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

vector<pair<pair<Int ,Int> , int> > a;

const int INF = 1000000000;

Int dp[(1 << 20) + 7];

int main()
{
	//freopen("in.txt" , "r" , stdin);
	int n,m;
	Int b;

	cin >> n >> m >> b;
	FOR(i,0,n)
	{
		int x,k,mm;
		cin >> x >> k >> mm;
		int mask = 0;
		FOR(j,0,mm)
		{
			int y;
			cin >> y;
			--y;
			mask |= (1 << y);
		}
		a.push_back(MP(MP(k,x) , mask) );
	}

	sort(ALL(a));

	Int INF2 = 2LL * INF * INF;

	FOR(i,0,1 << m)
		dp[i] = INF2;

	Int res = INF2;

	dp[0] = 0;

	FOR(i,0,n)
	{
		RFOR(mask , 1 << m , 0)
		{
			dp[mask | a[i].second] = min(dp[mask | a[i].second] , dp[mask] + a[i].first.second);
		}
		res = min(res , dp[(1 << m) - 1] + a[i].first.first * b);
	}

	if (res == INF2)
		res = -1;
	cout << res << endl;

	return 0;
}