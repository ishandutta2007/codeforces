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

void solve() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> a(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = 0;
		sum += a[i].first;
	}
	int last = 0, lastx = 0;
	for (int i = 1; i <= q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int j, x;
			cin >> j >> x;
			int prev = (last > a[j].second ? lastx : a[j].first);
			sum += x - prev;
			a[j] = { x, i };
		}
		else {
			int x;
			cin >> x;
			sum = x * n;
			last = i, lastx = x;
		}
		cout << sum << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}