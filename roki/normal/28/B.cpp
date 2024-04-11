#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define xrange(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long li;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int n;
int a[100];
int d[100];


bool read() {
	if (!(cin >> n))
		return false;
	forn (i, n)
		cin >> a[i];
	forn (i, n)
		cin >> d[i];
	return true;
}

bitset<100> dost[100];
bool used[100];

void dfs(int v)
{
	dost[v][v] = true;
	used[v] = true;
	if (v + d[v] < n)
	{
		if (!used[v + d[v]])
			dfs(v + d[v]);
		dost[v] |= dost[v + d[v]];
	}
	if (v - d[v] >= 0)
	{
		if (!used[v - d[v]])
			dfs(v - d[v]);
		dost[v] |= dost[v - d[v]];
	}
	forn (i, n)
	{
		if (i + d[i] == v || i - d[i] == v)
		{
			if (!used[i])
				dfs(i);
			dost[v] |= dost[i];
		}
	}
}

void solve() {
	forn (j, n)
	{
		memset(used, false, sizeof used);
		forn (i, n)
			dfs(i);
	}
	bool ok = true;
	forn (i, n)
	{
		if (!dost[i][a[i] - 1])
			ok = false;
	}
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
#ifdef SU6
	freopen("input.txt","rt",stdin);
	// freopen("output.txt","wt",stdout);
#endif
	while (read())
		solve();
	return 0;
}