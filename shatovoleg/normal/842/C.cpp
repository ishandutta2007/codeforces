#include <bits/stdc++.h>

// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <random>
// #include <string>
// #include <vector>
// #include <queue>
// #include <map>
// #include <set>

using namespace std;
typedef long long ll;
typedef long double ld;

#define len(v) ((signed)v.size())
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
// #define int ll
#define kek pop_back
#define F first
#define S second
// #define pii pair<int, int>
mt19937 rnd(5654897);
#define rand rnd()

#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << endl;
#else
#define debug(x) ;
#endif

const int INF = numeric_limits<int>::max() >> 2;

template<class T1, class T2>
bool cmin(T1 &a, const T2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T1, class T2>
bool cmax(T1 &a, const T2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

inline void run();

void UseFiles(const string &s) {
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

signed main() {
	// UseFiles("sequence");
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef LOCAL
	// assert(freopen("test.in", "r", stdin));
	#endif
	run();
}

vector<int> divisors(int n) {
	vector<int> ans;
	for (int i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			ans.pb(i);
			if (i * i != n)
				ans.pb(n / i);
		}
	return ans;
}

vector<int> ans, cnt, a;
vector<vector<int>> g;
const int maxn = 2e5 + 100;

int solve(int a, int need) {
	int ans = 0;
	for (auto &x : divisors(a)) {
		if (cnt[x] >= need)
			cmax(ans, x);
	}
	return ans;
}

void change(int a, int m) {
	for (auto &x : divisors(a))
		cnt[x] += m;
}

void dfs(int v, int p = -1, int d = 0) {
	change(a[v], 1);
	if (p == -1)
		ans[v] = a[v];
	else
		ans[v] = max(solve(a[v], d), solve(a[p], d));
	for (auto &x : g[v]) {
		if (x == p)
			continue;
		dfs(x, v, d + 1);
	}
	change(a[v], -1);
}

void run() {
	int n;
	cin >> n;
	a.resize(n);
	cnt.resize(maxn, 0);
	ans.resize(n);
	g.resize(n);
	for (auto &x : a)
		cin >> x;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	for (auto &x : ans)
		cout << x << " ";
	cout << endl;
}