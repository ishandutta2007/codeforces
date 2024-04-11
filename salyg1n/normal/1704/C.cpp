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
	vector<int> a(m);
	input(a);
	sort(all(a));
	vector<int> b;
	for (int i = 1; i < m; ++i)
		b.push_back(a[i] - a[i - 1] - 1);
	b.push_back(n - a[m - 1] + a[0] - 1);
	int ans = n;
	int cnt = 0;
	sort(rall(b));
	for (int i = 0; i < m; ++i) {
		b[i] -= cnt * 2;
		if (b[i] <= 0)
			continue;
		if (b[i] == 1) {
			cnt++;
			ans--;
			continue;
		}
		else {
			cnt += 2;
			ans -= b[i] - 1;
		}
	}
	cout << ans << "\n";
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