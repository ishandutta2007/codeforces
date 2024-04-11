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

const int INF = 1e18;
int n;

struct segtree {
	int val = 0;
	int push = 0;
};

vector<segtree> t;

void build(int v, int l1, int r1) {
	if (r1 - l1 <= 1)
		t[v].val = 0;
	else {
		int m = (l1 + r1) / 2;
		build(v * 2, l1, m);
		build(v * 2 + 1, m, r1);
		t[v].val = max(t[v * 2].val, t[v * 2 + 1].val);
	}
}

void push(int v, int tl, int tr) {
	if (t[v].push == 0) {
		return;
	}
	if (tr - tl > 1) {
		t[2 * v].push += t[v].push;
		t[2 * v + 1].push += t[v].push;
	}
	t[v].val += t[v].push;
	t[v].push = 0;
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (tl >= r || l >= tr) {
		return;
	}
	if (l <= tl && tr <= r) {
		t[v].push = x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) / 2;
	upd(2 * v, tl, tm, l, r, x);
	upd(2 * v + 1, tm, tr, l, r, x);
	t[v].val = max(t[v * 2].val, t[v * 2 + 1].val);
}

int get_max(int v, int l1, int r1, int l, int r) {
	if (r1 <= l || l1 >= r)
		return -2e9;
	push(v, l1, r1);
	if (l1 >= l && r1 <= r)
		return t[v].val;
	int m = (r1 + l1) / 2;
	return max(
		get_max(v * 2, l1, m, l, r)
		,
		get_max(v * 2 + 1, m, r1, l, r)
	);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2, INF);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<int> l(n + 1), r(n + 1);
	vector<int> s = { 0 };
	for (int i = 1; i <= n; ++i) {
		while (a[i] >= a[s.back()])
			s.pop_back();
		l[i] = s.back();
		s.push_back(i);
	}
	s = { n + 1 };
	for (int i = n; i >= 1; --i) {
		while (a[i] >= a[s.back()])
			s.pop_back();
		r[i] = s.back();
		s.push_back(i);
	}
	t.clear();
	t.resize(4 * (n + 1));
	build(1, 0, n + 1);
	int mn = INF;
	for (int i = 1; i <= n; ++i) {
		mn = min(mn, -get_max(1, 0, n + 1, l[i] + 1, i));
		upd(1, 0, n + 1, 1, i + 1, a[i]);
	}
	t.clear();
	t.resize(4 * (n + 1));
	build(1, 0, n + 1);
	for (int i = n; i >= 1; --i) {
		mn = min(mn, -get_max(1, 0, n + 1, i + 1, r[i]));
		upd(1, 0, n + 1, i, n + 1, a[i]);
	}
	if (mn < 0)
		cout << "NO\n";
	else
		cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}