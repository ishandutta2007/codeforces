#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;
const int MAXN = 102;

int m[MAXN][MAXN];
int use[MAXN];
bool ind = false;
bool ind1 = false;
int st = 0;
int n;
int rt[MAXN];
int cr = 0;

void find_cycle(int v, int p)
{
	use[v] = true;
	FOR(i, n)
	{
		if (m[v][i] == 0) continue;
		if (i == p) continue;
		if (use[i])
		{
			ind = true;
			st = i;
			m[v][i] = 0;
			m[i][v] = 0;
			rt[cr++] = v;
			return;
		}
		find_cycle(i, v);
		if (ind)
		{
			if (ind1) return;
			rt[cr++] = v;
			m[v][i] = 0;
			m[i][v] = 0;
			if (v == st)
			{
				ind1 = true;
			}
			return;
		}
	}
	return;
}

void check(int v)
{
	use[v] = true;
	FOR(i, n)
	{
		if (m[v][i] == 0) continue;
		if (use[i]) continue;
		check(i);
	}
	return;
}

void kill()
{
	printf("NO");
	exit(0);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	int M;
	scanf("%d%d", &n, &M);
	clr(m);
	FOR(i, M)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		m[a][b] = 1;
		m[b][a] = 1;
	}
	clr(use);
	check(0);
	FOR(i, n)
		if (!use[i]) kill();
	clr(use);
	find_cycle(0, -1);
	if (! ind) kill();
	clr(use);
	ind = false;
	ind1 = false;

	FOR(i, cr)
	{
		if (use[rt[i]]) kill();
		find_cycle(rt[i], -1);
		if (ind) kill();
	}
	FOR(i, n)
        if (! use[i]) kill();
	printf("FHTAGN!");

	return 0;
}