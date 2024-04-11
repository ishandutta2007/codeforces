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
	int last, j = 1;
	cin >> last;
	vector<int> ans;
	for (int i = 2; i <= n + 1; ++i) {
		int x;
		if (i <= n)
			cin >> x;
		else
			x = -1;
		if (x != last) {
			if (i - j <= 1) {
				cout << "-1\n";
				for (int k = i + 1; k <= n; ++k)
					cin >> x;
				return;
			}
			else {
				ans.push_back(i - 1);
				j++;
				for (; j < i; ++j) {
					ans.push_back(j - 1);
				}
			}
			last = x;
		}
	}
	print(ans);
	cout << "\n";
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