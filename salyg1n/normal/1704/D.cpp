/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
*/
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
#include <complex>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef double ld;
typedef std::complex<ld> cd;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " "
#define input(a) for (auto& _ : a) cin >> _
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

std::mt19937 rnd(55);

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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		input(a[i]);
	vector<int> cnt(n, 0);
	for (int i = 0; i < m - 1; ++i) {
		int mn = 1e18;
		for (int j = 0; j < n; ++j)
			minravno(mn, a[j][i]);
		for (int j = 0; j < n; ++j) {
			a[j][i + 1] += a[j][i] - mn;
			cnt[j] += a[j][i] - mn;
			a[j][i] = mn;
		}
	}
	int num;
	if (cnt[0] == cnt[1]) {
		for (int i = 2; i < n; ++i)
			if (cnt[i] != cnt[0])
				num = i;
	}
	else {
		if (cnt[0] == cnt[2])
			num = 1;
		else
			num = 0;
	}
	int tr = 0;
	if (num == 0)
		tr = 1;
	cout << num + 1 << " " << abs(cnt[tr] - cnt[num]) << "\n";
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