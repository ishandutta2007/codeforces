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
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		string tmp = "  ";
		tmp[0] = s[i];
		tmp[1] = s[i + 1];
		sum += stoi(tmp);
	}
	if (sum == 0)
		cout << "0\n";
	else {
		int i = n - 1;
		for (; i >= 0; --i) {
			if (s[i] == '1')
				break;
		}
		if (i != n - 1 && n - 1 - i <= k) {
			if (i != 0) {
				sum -= 10;
			}
			else {
				sum -= 9;
			}
			swap(s[i], s[n - 1]);
			k -= n - 1 - i;
		}
		i = 0;
		for (; i < n; ++i) {
			if (s[i] == '1')
				break;
		}
		if (i != 0 && i != n - 1 && i <= k)
			sum -= 1;
		cout << sum << "\n";
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