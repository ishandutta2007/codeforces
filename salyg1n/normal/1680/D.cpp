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
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0), p(n + 1, 0), p0(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		p0[i] = p0[i - 1] + (a[i] == 0);
	}
	if (abs(p[n]) > p0[n] * k) {
		cout << -1;
		return;
	}
	int ans = -1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i == j || a[i] < 0 || a[j] > 0)
				continue;
			if (i < j) {
				int r = p[i] + p0[i] * k;
				int l = r + p[j] - p[i] - (p0[j] - p0[i]) * k;
				int end = l + p[n] - p[j];
				if (abs(end) <= (p0[n] - p0[j]) * k)
					ans = max(ans, r - l + 1);
				else if (end > 0) {
					end -= (p0[n] - p0[j]) * k;
					if (p0[i] * k * 2 >= end) {
						r -= end;
						ans = max(ans, r - l + 1);
					}
				}
				else {
					end += (p0[n] - p0[j]) * k;
					if ((p0[j] - p0[i]) * k * 2 >= abs(end)) {
						l -= end;
						ans = max(ans, r - l + 1);
					}
				}
			}
			else {
				swap(i, j);
				int l = p[i] - p0[i] * k;
				int r = l + p[j] - p[i] + (p0[j] - p0[i]) * k;
				int end = r + p[n] - p[j];
				if (abs(end) <= (p0[n] - p0[j]) * k)
					ans = max(ans, r - l + 1);
				else if (end > 0) {
					end -= (p0[n] - p0[j]) * k;
					if ((p0[j] - p0[i]) *k * 2 >= end) {
						r -= end;
						ans = max(ans, r - l + 1);
					}
				}
				else {
					end += (p0[n] - p0[j]) * k;
					if (p0[i] * k * 2 >= abs(end)) {
						l -= end;
						ans = max(ans, r - l + 1);
					}
				}
				swap(i, j);
			}
		}
	}
	cout << ans;
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