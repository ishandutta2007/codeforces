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
const int MAX = 100007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

vector<PII> T[4 * MAX];

VI G[MAX];

int R[MAX];

void Add(int v, int l, int r, int L, int R, int val, int h)
{
	if (L > R) return;
	if (l == L && r == R)
	{
		while (SZ(T[v]) && -T[v].back().first <= h) T[v].pop_back();
		T[v].push_back(MP(-h , val));
		return;
	}
	int m = (l + r) / 2;
	Add(2 * v + 1 , l , m , L , min(R , m) , val , h);
	Add(2 * v + 2 , m + 1 , r , max(L , m + 1) , R , val , h);
}

int res;

void Get(int v, int l, int r, int pos, int h)
{
	int ptr = lower_bound(ALL(T[v]) , MP(-h , 2 * INF + 7)) - T[v].begin() - 1;
	if (ptr != -1)
	{
		res = min(res , T[v][ptr].second);
		//cout << " T " << l << ' ' << r << ' ' << T[v][ptr].second << endl;
	}
	if (l == r) return;
	int m = (l + r) / 2;
	if (pos <= m)
		Get(2 * v + 1 , l , m , pos , h);
	else
		Get(2 * v + 2 , m + 1 , r , pos , h);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int h , w , n;
	cin >> h >> w >> n;
	vector<pair<PII, PII> > A;
	FOR(i,0,n)
	{
		int u , l , r , s;
		scanf("%d%d%d%d" , &u , &l , &r , &s);
		-- u; -- l; -- r;
		A.push_back(MP(MP(u , s) , MP(l, r)));
	}
	sort(ALL(A));

	reverse(ALL(A));

	Add(0,0,w - 1 , 0, w - 1 , n , 2 * INF);

	RFOR(i,n,0)
	{
		int l = A[i].second.first;
		int r = A[i].second.second;
		if (l != 0)
		{
			res = INF;
			Get(0,0,w - 1 , l - 1 , A[i].first.first);
			G[i].push_back(res);
		}
		if (r + 1 != w)
		{
			res = INF;
			Get(0,0,w - 1 , r + 1 , A[i].first.first);
			G[i].push_back(res);
		}
		if (SZ(G[i]) == 1)
			G[i].push_back(G[i][0]);
		Add(0,0,w - 1 , l , r , i , A[i].first.first + A[i].first.second);
	}

	//cout << 'x' << endl;
	FOR(i,0,w)
	{
		res = INF;
		Get(0,0,w - 1 , i , h);
		//cout << res << endl;
		R[res] ++;
	}

	FOR(i,0,n)
	{
		FOR(j,0,2)
		{
			int to = G[i][j];
			R[to] += R[i];
			R[to] %= MOD;
		}
	}

	cout << R[n] << endl;

    return 0;
}