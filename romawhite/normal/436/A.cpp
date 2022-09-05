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
const int MOD = 1000000007;

vector<pair<int,int> > a;
vector<pair<int,int> > b;
bool used1[2005];
bool used2[2005];


int main()
{
	int n,x;
	cin >> n >> x;

	FOR(i,0,n)
	{
		int t,h,m;
		cin >> t >> h >> m;
		if (t == 0)
		{
			a.push_back(MP(h,m));
		}
		else
		{
			b.push_back(MP(h,m));
		}
	}

	sort(ALL(a));
	sort(ALL(b));

	int res = 0;

	FOR(it,0,2)
	{
		FILL(used1,0);
		FILL(used2,0);
		int H = x;
		int r = 0;
		while (1)
		{
			if ( r % 2 == 0)
			{
				int M = -1;
				int id = -1;
				FOR(i,0,a.size())
				{
					if (H >= a[i].first)
					{
						if (a[i].second > M && !used1[i])
						{
							M = a[i].second;
							id = i;
						}
					}
					else
					{
						break;
					}
				}
				if (id == -1) break;
				used1[id] = 1;
				H += a[id].second;
			}
			else
			{
				int M = -1;
				int id = -1;
				FOR(i,0,b.size())
				{
					if (H >= b[i].first)
					{
						if (b[i].second > M && !used2[i])
						{
							M = b[i].second;
							id = i;
						}
					}
					else
					{
						break;
					}
				}
				if (id == -1) break;
				used2[id] = 1;
				H += b[id].second;
			}
			++r;
		}
		res = max(res , r);
		a.swap(b);
	}

	cout << res << endl;

    return 0;
}