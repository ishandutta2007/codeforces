#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
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
const int MAXV = 120;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

struct edge
{
	int a, b, c, f;
	Int p;
	edge(){}
};

int N;
vector<edge> E;
VI G[MAXV];
Int D[MAXV];
int Q[MAXV];
int T[MAXV];
int Par[MAXV];

void add_edge(int u, int v, int c, Int p)
{
	edge e;
	e.a = u; e.b = v;
	e.c = c; e.p = p;
	e.f = 0;
	G[u].PB(SZ(E));
	E.PB(e);
	e.a = v; e.b = u;
	e.c = 0; e.p = -p;
	e.f = 0;
	G[v].PB(SZ(E));
	E.PB(e);
}

pair<Int, Int> Flow(int s, int t)
{
	Int flow = 0;
	Int cost = 0;
	while (1)
	{
		int qh = 0, qt = 1;
		Q[0] = s;
		FOR (i,0,N)
		{
			T[i] = 0;
			Par[i] = -1;
			D[i] = Int(INF) * INF;
		}
		D[s] = 0;
		while (qh != qt)
		{
			int v = Q[qh ++];
			if (qh == N)
				qh = 0;
			T[v] = 2;
			FOR (i,0,SZ(G[v]))
			{
				int id = G[v][i];
				if (E[id].c > E[id].f && D[E[id].b] > D[v] + E[id].p)
				{
					if (T[E[id].b] == 0)
					{
						Q[qt ++] = E[id].b;
						if (qt == N)
							qt = 0;
					}
					else
					if (T[E[id].b] == 2)
					{
						-- qh;
						if (qh == -1)
							qh = N-1;
						Q[qh] = E[id].b;
					}
					D[E[id].b] = D[v] + E[id].p;
					T[E[id].b] = 1;
					Par[E[id].b] = id;
				}
			}
		}
		if (Par[t] == -1)
			break;
		int f = INF, x;
		x = t;
		while (x != s)
		{
			f = min(f, E[Par[x]].c-E[Par[x]].f);
			x = E[Par[x]].a;
		}
		flow += f;
		x = t;
		while (x != s)
		{
			E[Par[x]].f += f;
			E[Par[x]^1].f -= f;
			cost += E[Par[x]].p * f;
			x = E[Par[x]].a;
		}
	}
	return MP(flow, cost);
}

int d[MAXV];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n , m;
	cin >> n >> m;
	N = n + 2;
	int s = 0;
	int t = N - 1;
	add_edge(n , 1 , INF , 0);

	Int res = 0;

	FOR(i,0,m)
	{
		int a , b , c , f;
		cin >> a >> b >> c >> f;

		d[a] += f;
		d[b] -= f;

		if (f <= c)
		{
			add_edge(a , b , c - f , 1);
			add_edge(a , b, INF , 2);
			add_edge(b , a , f , 1);
		}
		else
		{
			res += f - c;
			add_edge(b , a , f - c , 0);
			add_edge(a , b , INF , 2);
			add_edge(b , a , c , 1);
		}

	}

	Int sumd = 0;

	FOR(i,1,n + 1)
	{
		sumd += d[i];
		if (d[i] < 0)
		{
			add_edge(s , i , -d[i] , 0);
		}
		else
		{
			add_edge(i , t , d[i] , 0);
		}
	}

	pair<Int,Int> p = Flow(s , t);

	res += p.second;

	cout << res << endl;

    return 0;
}