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
#include <functional>
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

const int INF = 1000000000;

int a[107][107];
int b[107];

int main()
{
	//freopen("in.txt" , "r" , stdin);
	
	int n,m,k;
	cin >> n >> m >> k;

	if (n > m)
	{
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cin >> a[i][j];
			}
		}
	}
	else
	{
		swap(n,m);
		FOR(j,0,m)
			FOR(i,0,n)
				cin >> a[i][j];
	}

	if (n > 10)
	{
		int res = 11;
		FOR(chosen , 0 , n)
		{
			int sum = 0;
			FOR(i,0,n)
			{
				int s = 0;
				FOR(j,0,m)
					s += (a[chosen][j] ^ a[i][j]);
				sum += min(s , m - s);
			}
			res = min(res , sum);
		}
		if (res <= k)
		{
			cout << res << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	else
	{
		int res = 11;
		FOR(mask , 0 ,1 << m)
		{
			int sum = 0;
			FOR(i,0,n)
			{
				int s = 0;
				FOR(j,0,m)
					s += (bool(mask ^ (1 << j)) ^ a[0][j] ^ a[i][j]);
				sum += min(s , m - s);
			}
			res = min(res , sum);
		}
		if (res <= k)
		{
			cout << res << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}


	return 0;
}