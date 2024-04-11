#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#define maxn 100500
#define maxk 20

using namespace std;

vector < pair < int, int > > edge[maxn];
int par[maxn][maxk];
bool used[maxn];
int n, k;
int tin[maxn], tout[maxn];
int cur = 0;
int beg[maxn], en[maxn];
int res[maxn];

int DFS (int x, int car) {
	tin[x] = ++cur;
	used[x] = true;
	par[x][0] = car;
	for (int i = 1; i < maxk; ++i)
		par[x][i] = par[par[x][i - 1]][i - 1];
	for (int i = 0; i < int (edge[x].size ()); ++i)
		if (!used[edge[x][i].first])
			DFS (edge[x][i].first, x);
	tout[x] = ++cur;
	return 0;
}

bool is_par (int x, int y) {
	return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int lca (int x, int y) {
	if (is_par (x, y)) return x;
	if (is_par (y, x)) return y;
	int ans = x;
	for (int i = 19; i >= 0; --i)
		if (par[ans][i] !=0 && !is_par (par[ans][i], y))
			ans = par[ans][i];
	return par[ans][0];
}

int add (int x, int y) {
	++beg[x];
	++en[y];
	return 0;
}

int DFS1 (int x, int num, int &cbeg, int &cen) {
	used[x] = true;
	int ebeg = beg[x], een = en[x];
	for (int i = 0; i < int (edge[x].size ()); ++i)
		if (!used[edge[x][i].first])
			DFS1 (edge[x][i].first, edge[x][i].second, ebeg, een);
	res[num] = een - ebeg;
	//assert (res[num] >= 0);
	cbeg += ebeg;
	cen += een;
	return 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		edge[i].clear ();
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf ("%d%d", &a, &b);
		edge[a].push_back (make_pair (b, i));
		edge[b].push_back (make_pair (a, i));
	}
	memset (used, 0, sizeof (used));
	DFS (1, 0);
	scanf ("%d", &k);
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf ("%d%d", &a, &b);
		int l_c_a = lca (a, b);
		//printf ("a b lca %d %d %d\n", a, b, l_c_a);
		add (l_c_a, a);
		add (l_c_a, b);
	}
	int abeg = 0, aen = 0;
	memset (used, 0, sizeof (used));
	DFS1 (1, 0, abeg, aen);
	for (int i = 1; i < n; ++i)
		printf ("%d ", res[i]);
	return 0;
}