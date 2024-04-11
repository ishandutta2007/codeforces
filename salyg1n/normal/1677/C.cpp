#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
#include <fstream>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

#define int int_fast64_t
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

vector<vector<int>> g;
vector<int> used;
vector<int> cnt;

void dfs(int v) {
	bool end = true;
	for (auto u : g[v]) {
		if (!used[u]) {
			used[u] = used[v] + 1;
			end = false;
			dfs(u);
		}
	}
	if (end) {
		cnt.push_back(used[v] - used[v] % 2);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	input(a);
	input(b);
	g.assign(n + 1, {});
	used.assign(n + 1, false);
	cnt.clear();
	for (int i = 0; i < n; ++i) {
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			used[i] = 1;
			dfs(i);
		}
	}
	int now = n-1;
	int ans = 0;
	for (auto c : cnt) {
		ans += now * (c - 1) - (c - 1) * (c - 2) / 2 + now - c / 2 + 1;
		now -= c;
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}