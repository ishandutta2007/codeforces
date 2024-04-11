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
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	vector<int> p0(n + 1, 0), p1(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		p0[i] = p0[i - 1];
		p1[i] = p1[i - 1];
		(s[i] == '1' ? p1[i] : p0[i])++;
	}
	int l = -1, r = min(p1[n], p0[n]);
	while (r - l > 1) {
		int m = (r + l) / 2;
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			int L = i, R = n;
			while (R - L > 0) {
				int M = (L + R) / 2;
				if (p1[i - 1] + p1[n] - p1[M] > m)
					L = M + 1;
				else if (p0[M] - p0[i - 1] > m)
					R = M - 1;
				else
					L = R = M;
			}
			if (p1[i - 1] + p1[n] - p1[L] <= m && p0[L] - p0[i - 1] <= m)
				flag = true;
		}
		if (flag)
			r = m;
		else
			l = m;
	}
	cout << r << "\n";
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