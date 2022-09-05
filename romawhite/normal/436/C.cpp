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

string s[1005][11];
char buf[11];

int d[1005][1005];
int D[1005];
int p[1005];
bool used[1005];

int main()
{
	int n,m,k,w;
	cin >> n >> m >> k >> w;

	FOR(i,0,k)
	{
		FOR(j,0,n)
		{
			scanf("%s" , buf);
			s[i][j] = buf;

		}
	}


	FOR(i,0,k + 1)
	{
		FOR(j,0,k + 1)
		{
			d[i][j] = n * m;
		}
	}

	FOR(i,1,k + 1)
	{
		FOR(j,i,k + 1)
		{
			int c = 0;
			FOR(x,0,n)
			{
				FOR(y,0,m)
				{
					c += (s[i - 1][x][y] != s[j - 1][x][y]);
				}
			}
			d[i][j] = d[j][i] = min(c * w , d[i][j]);
		}
	}

	FOR(i,1,k + 1)
	{
		D[i] = n * m;
	}
	used[0] = 1;

	vector<pair<int,int> > res;
	int S = 0;

	FOR(it,0,k)
	{
		int id = -1;
		int M = INF;
		FOR(i,1,k + 1)
		{
			if (!used[i])
			{
				if (D[i] < M)
				{
					M = D[i];
					id = i;
				}
			}
		}
		res.push_back(MP(id , p[id]) );
		S += M;
		used[id] = 1;
		FOR(j,1,k + 1)
		{
			if (d[id][j] < D[j])
			{
				D[j] = d[id][j];
				p[j] = id;
			}
		}
	}
	
	cout << S << endl;
	FOR(i,0,res.size())
	{
		cout << res[i].first << ' ' << res[i].second << endl;
	}

    return 0;
}