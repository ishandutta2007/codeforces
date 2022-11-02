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
bool minravno(T & a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool maxravno(T & a, T b) {
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
	vector<int> a(n);
	input(a);
	vector<int> pref(n, 0), suf(n, 0);
	int all = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0) {
			pref[i] += a[i];
			suf[i] += a[i];
			all += a[i];
		}
		if (a[i] < 0) {
			if (i == 0) {
				suf[1] -= a[i];
				all -= a[i];
			}
			else if (i == n - 1) {
				pref[n - 2] -= a[i];
				all -= a[i];
			}
			else {
				pref[i - 1] -= a[i];
				suf[i + 1] -= a[i];
				all -= a[i];
			}
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		int x = min(pref[i], suf[i + 1]);
		pref[n - 1] += x;
		pref[i] -= x;
		suf[i + 1] -= x;
	}
	int x = min(pref[n - 1], all);
	all -= x;
	pref[n - 1] -= x;

	x = min(suf[0], all);
	suf[0] -= x;
	all -= x;

	int sum = 0;
	for (auto i : pref)
		sum += i;
	for (auto i : suf)
		sum += i;
	sum += all;
	cout << sum << "\n";
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