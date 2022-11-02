#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 100010;

int n, u, v;
vector<int> g[maxn];
int init[maxn], goal[maxn];
vector<int> ans;

void go(int i, int p1, int p0, int p = -1) {
	if ((init[i] ^ p0) != goal[i]) {
		p0 ^= 1;
		ans.pb(i + 1);
	}

	forn(j, g[i].size())
		if (g[i][j] != p) {
			go(g[i][j], p0, p1, i);
		}
}

int main() {
	scanf("%d", &n);
	forn(i, n - 1) {
		scanf("%d %d", &u, &v);
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	forn(i, n) scanf("%d", &init[i]);
	forn(i, n) scanf("%d", &goal[i]);
	go(0, 0, 0);
	printf("%d\n", int(ans.size()));
	forn(i, ans.size()) printf("%d\n", ans[i]);
	return 0;
}