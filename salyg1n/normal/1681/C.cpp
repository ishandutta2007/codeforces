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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	input(a);
	input(b);
	bool flag = true;
	vector<pair<int, int>> ans;
	while (flag && ans.size() <= (int)1e4) {
		flag = false;
		for (int i = 1; i < n; ++i) {
			if (a[i] > a[i - 1] && b[i] < b[i - 1]) {
				cout << "-1\n";
				return;
			}
			if (a[i] < a[i - 1] && b[i] > b[i - 1]) {
				cout << "-1\n";
				return;
			}
			if (a[i] < a[i - 1] || b[i] < b[i - 1]) {
				flag = true;
				ans.push_back({ i - 1, i });
				swap(a[i], a[i - 1]);
				swap(b[i], b[i - 1]);
			}
		}
	}
	if (ans.size() > (int)1e4)
		cout << "-1\n";
	else {
		cout << ans.size() << "\n";
		for (auto [x, y] : ans)
			cout << x + 1 << " " << y + 1 << "\n";
	}
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