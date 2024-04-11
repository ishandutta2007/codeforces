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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define MP make_pair
#define PB push_back

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 100007;
const int BASE = 1000000000;
const int ST = 1000000007;

VI G[MAX];
int sz[MAX];
bool D[MAX];
VI cmp;

void dfs(int v, int p)
{
	cmp.push_back(v);
	sz[v] = 1;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (to == p) continue;
		if (D[to]) continue;
		dfs(to, v);
		sz[v] += sz[to];
	}
}

int res[MAX];

void build(int v, int ch)
{
	cmp.clear();
	dfs(v, -1);
	while (sz[v] > SZ(cmp) / 2 + 1)
	{
		int id = -1;
		int mx = -1;
		FOR(i,0,SZ(G[v]))
		{
			int to = G[v][i];
			if (D[to]) continue;
			if (sz[to] > sz[v]) continue;
			if (sz[to] > mx)
			{
				mx = sz[to];
				id = to;
			}
		}
		if (mx <= SZ(cmp) / 2) break;
		v = id;
	}
	res[v] = ch;
	D[v] = 1;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i];
		if (D[to]) continue;
		build(to, ch + 1);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	cin >> n;
	FOR(i,0,n  - 1)
	{
		int a , b;
		scanf("%d%d" , &a ,  &b);
		--a;--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	build(0,0);

	FOR(i,0,n)
	{
		cout << (char)(res[i] + 'A') << ' ';
	}



	//cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}