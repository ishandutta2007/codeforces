#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")

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
#include <numeric>

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

template<typename T>
bool minravno(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool maxravno(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	if (a[1] != b[1] || a[n] != b[n]) {
		cout << "NO\n";
		return;
	}
	vector<pair<int, int>> ans;
	for (int i = 2; i < n; ++i) {
		if (a[i] == b[i])
			continue;
		bool flag = false;
		for (int j = i + 2; j <= n; ++j) {
			if (a[j] == a[i - 1] && a[j - 1] == b[i]) {
				flag = true;
				reverse(a.begin() + i, a.begin() + j);
				ans.push_back({ i - 1, j });
				break;
			}
		}
		if (flag)
			continue;
		for (int j = i; j < n; ++j) {
			if (a[j] == a[i - 1] && a[j + 1] == b[i]) {
				vector<int> was(n + 1, 0);
				for (int k = i - 1; k <= j; ++k)
					was[a[k]] = k;
				for (int k = j + 1; k <= n; ++k) {
					if (!was[a[k]])
						continue;
					reverse(a.begin() + was[a[k]] + 1, a.begin() + k);
					ans.push_back({ was[a[k]], k });
					reverse(a.begin() + i, a.begin() + k - (j - was[a[k]]));
					ans.push_back({ i - 1, k - (j - was[a[k]])});
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for (auto [a, b] : ans)
		cout << a << " " << b << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}