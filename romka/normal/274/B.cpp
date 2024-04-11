#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 100010;

int n, a, b, v[maxn];
vector<int> g[maxn];
ll cp[maxn], cm[maxn];

void dfs(int i, int p = -1) {
	ll maxm = 0, maxp = 0;
	forn(j, g[i].size()) {
		int y = g[i][j];
		if (y == p) continue;
		dfs(y, i);
		if (cp[y] > maxp) maxp = cp[y];
		if (cm[y] > maxm) maxm = cm[y];
	}
	cp[i] = maxp;
	cm[i] = maxm;
	ll val = v[i] + maxp - maxm;
	if (val < 0) cp[i] += -val;
	else cm[i] += val;
}

int main() {
	scanf("%d", &n);
	forn(i, n-1) {
		scanf("%d %d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}	
	forn(i, n) scanf("%d", &v[i]);
	dfs(0);
	cout << cp[0] + cm[0] << endl;
	return 0;
}