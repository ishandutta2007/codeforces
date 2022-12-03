#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; char c; };

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void dfs(int u, vector<vector<edge> >& G, char c, vector<int>& a, vector<int>& unko) {
	unko.push_back(u);
	for (edge e: G[u]) {
		if (a[e.v]) continue;
		a[e.v] = a[u];
		if (e.c != c) a[e.v] *= -1;
		dfs(e.v, G, c, a, unko);
	}
}

pair<int, vector<int> > solve(int N, vector<vector<edge> >& G, char c) {
	vector<int> a(N), ans;
	for (int u = 0; u < N; u++)
		if (!a[u]) {
			a[u] = 1;
			vector<int> unko;
			dfs(u, G, c, a, unko);
			int x = 0, y = 0;
			for (int u: unko) {
				if (a[u] == 1) x++;
				if (a[u] == -1) y++;
				for (edge e: G[u])
					if ((e.c == c && a[u] * a[e.v] == 1) || (e.c != c && a[u] * a[e.v] == -1));
					else return make_pair(INF, vector<int>(0));
			}
			if (x < y) {
				for (int u: unko)
					if (a[u] == 1)
						ans.push_back(u);
			}
			else {
				for (int u: unko)
					if (a[u] == -1)
						ans.push_back(u);
			}
		}
	return make_pair(ans.size(), ans);
}

int main() {
	int N, M; cin >> N >> M;
	vector<vector<edge> > G(N);
	while (M--) {
		int u, v; char c;
		scanf("%d %d %c", &u, &v, &c);
		u--; v--;
		G[u].push_back(edge{v, c});
		G[v].push_back(edge{u, c});
	}
	auto ans = min(solve(N, G, 'R'), solve(N, G, 'B'));
	if (ans.first == INF) cout << -1 << endl;
	else {
		cout << ans.first << endl;
		for (int u: ans.second)
			printf("%d ", u + 1);
		cout << endl;
	}
}