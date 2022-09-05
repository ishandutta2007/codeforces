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

vector<pair<int,int> > g[100007];
int n;
int M[100007];

vector<pair<Int,int> > djkstra()
{
	vector<pair<Int,int> > d(n, MP(1LL * INF * INF , 1));
	set<pair<Int, int> > s;
	d[0] = MP(0, 1);
	vector<bool> used(n, 0);
	used[0] = 0;
	s.insert(MP(0,0));
	FOR(i,0,n)
	{
		s.insert(MP(1LL * INF * INF, i));
	}
	FOR(i,0,n)
	{
		int v = s.begin()->second;
		Int dist = s.begin()->first;
		used[v] = 1;
		s.erase(s.begin());
		FOR(i,0,g[v].size())
		{
			if (!used[g[v][i].first] && d[g[v][i].first].first >= d[v].first + g[v][i].second)
			{
				if (d[g[v][i].first].first > d[v].first + g[v][i].second)
				{
					s.erase(MP(d[g[v][i].first].first , g[v][i].first));
					d[g[v][i].first] = MP(d[v].first + g[v][i].second, 1);
					s.insert(MP(d[g[v][i].first].first , g[v][i].first));
				}
				else
				{
					d[g[v][i].first].second++;
				}
			}
		}
	}
	return d;
}

int main()
{
	//freopen("in.txt" , "r" , stdin);

	int m,k;
	cin >> n >> m >> k;
	FOR(i,0,m)
	{
		int a,b,c;
		scanf("%d%d%d" , &a , &b , &c);
		--a;--b;
		g[a].push_back(MP(b,c));
		g[b].push_back(MP(a,c));
	}

	//vector<pair<Int,int> > d1 = djkstra();

	FOR(i,0,n)
	{
		M[i] = 2 * INF;
	}
	FOR(i,0,k)
	{
		int b, c;
		scanf("%d%d" , &b, &c);
		--b;
		M[b] = min(M[b] , c);
	}

	FOR(i,1,n)
	{
		if (M[i] < 2 * INF)
		{
			g[0].push_back(MP(i,M[i]));
		}
	}

	vector<pair<Int,int> > d = djkstra();

	int res = k;

	FOR(i,1,n)
		if (M[i] < 2 * INF)
		{
			if (d[i] == MP((Int)M[i] , 1) )
			{
				--res;
			}
		}

	cout << res << endl;

    return 0;
}