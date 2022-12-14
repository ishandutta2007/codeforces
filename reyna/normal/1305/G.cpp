
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1 << 18, mod = (int) 0;
int a[N], par[N], seen[N];
pair<int, int> dp[N], cur_best[N];
vector<int> all[N], adj[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) {
	par[find(u)] = find(v);	
}
pair<int, int> best(pair<int, int> x, pair<int, int> y) {
	if (x.x == -1) return y;
	if (y.x == -1) return x;
	return a[x.x] + a[x.y] > a[y.x] + a[y.y] ? x : y;
}
pair<int, int> fix(pair<int, int> cur) {
	if (cur.first == -1) return mp(cur.second, cur.first);
	if (cur.second == -1) return cur;
	if (a[cur.first] > a[cur.second]) return cur;
	return mp(cur.second, cur.first);
}
pair<int, int> add(pair<int, int> x, int y) {
	if (y == -1) return x;
	if (x.first == -1) return mp(y, -1);
	if (find(x.first) == find(y)) return fix(mp(a[x.first] < a[y] ? y : x.first, x.second));
	if (x.second == -1) return fix(mp(x.first, y));
	if (find(x.second) == find(y)) return fix(mp(x.first, (a[x.second] < a[y] ? y : x.second)));
	if (a[x.second] < a[y]) return fix(mp(x.first, y));
	return x;
}
pair<int, int> add(pair<int, int> x, pair<int, int> y) {
	return add(add(x, y.first), y.second);	
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		par[j] = j;
		cin >> a[j];
	}
	par[n] = n;
	a[n++] = 0;
	sort(a, a + n);
	reverse(a, a + n);
	long long res = 0;
	for (int j = 0; j < n; ++j) res -= a[j];
	for (int turn = 0; turn < 18; ++turn) {
		for (int mask = 0; mask < 1 << 18; ++mask) dp[mask] = mp(-1, -1), cur_best[mask] = mp(-1, -1);
		for (int j = 0; j < n; ++j) {
			dp[a[j]] = add(dp[a[j]], j);
		}
		for (int mask = 0; mask < 1 << 18; ++mask) {
			for (int j = 0; j < 18; ++j) if (mask >> j & 1) {
				dp[mask] = add(dp[mask], dp[mask ^ (1 << j)]);
			
			}
		}
		for (int j = 0; j < n; ++j) {
			int x = find(j);
			int mask = ((1 << 18) - 1) ^ a[j];
			if (dp[mask].first != -1 && find(dp[mask].first) != x) {
				cur_best[x] = best(cur_best[x], mp(j, dp[mask].first));	
			} else if (dp[mask].second != -1) {
				cur_best[x] = best(cur_best[x], mp(j, dp[mask].second));	
			}
		}
		vector<int> all;
		for (int j = 0; j < n; ++j)
			if (find(j) == j && cur_best[j].x != -1)
				all.pb(j);
		
		for (int j : all) {
			if (find(j) == j && cur_best[j].x != -1) {
				assert(cur_best[j].y != -1);
				int ed = a[cur_best[j].x] + a[cur_best[j].y];
				if (find(cur_best[j].x) != find(cur_best[j].y)) res += ed;
				unite(cur_best[j].x, cur_best[j].y);
			}
		}
	}
	cout << res << endl;
}