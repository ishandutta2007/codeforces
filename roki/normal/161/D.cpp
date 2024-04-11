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

int n, k;
vector< int > g[50000];
li ans = 0;

bool read() {
	if (!(cin >> n >> k))
		return false;
    forn (i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].pb(b - 1);
		g[b - 1].pb(a - 1);
	}
	return true;
}

li d[50000][501];

void dfs (int v, int p = -1)
{
	d[v][0]++;
	forn (i, g[v].size())
	{
		int to = g[v][i];
		if (to == p)
			continue;
		dfs(to, v);
		forn (j, k)
			d[v][j + 1] += d[to][j];
	}
	ans += d[v][k];
	li sum = 0;
	forn (i, g[v].size())
	{
		int to = g[v][i];
		if (to == p)
			continue;
		forn (len, k - 1)
			sum += d[to][len] * (d[v][k - len - 1] - d[to][k - len - 2]);
	}
	ans += sum / 2;
}

void solve(){
	dfs(0);
	cout << ans << endl;
}

int main() {
#ifdef SU6
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}