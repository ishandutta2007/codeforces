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

int main()
{
	//freopen("in.txt" , "r" , stdin);
	
	int n , k;
	cin >> n >> k;
	//n = 200;
	//k = 10;
	vector<int> a(n);
	FOR(i,0,n)
	{
		cin >> a[i];
		///a[i] = rand();
	}

	int res = -INF;

	FOR(l,0,n)
		FOR(r,l,n)
		{
			vector<int> b;
			vector<int> c;
			int sum = 0;
			FOR(i,0,n)
			{
				
				if (i >= l && i <= r)
				{
					b.push_back(a[i]);
					sum += a[i];
				}
				else
				{
					c.push_back(a[i]);
				}
			}

			sort(ALL(b));
			sort(ALL(c),greater<int>());
				
			FOR(i,0,min(k, (int)min(b.size() , c.size())))
			{
				if (b[i] < c[i])
				{
					sum += c[i] - b[i];
				}
			}

			res = max(res , sum);
		}
	cout << res << endl;
	return 0;
}