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
	vector<int> a(n);
	input(a);
	sort(all(a));
	if (n % 2) {
		cout << "NO\n";
		return;
	}
		vector<int> b;
		for (int i = 0; i < n / 2; ++i) {
			b.push_back(a[i]);
			b.push_back(a[n/2 + i]);
		}
		bool flag = (b[0] > b[1] && b[0] > b[n - 1]) || (b[0] < b[1] && b[0] < b[n - 1]);
		flag &= (b[n - 1] > b[n - 2] && b[n - 1] > b[0]) || (b[n - 1] < b[n - 2] && b[n - 1] < b[0]);
		for (int i = 1; i < n - 1; ++i) {
			flag &= (b[i] > b[i - 1] && b[i] > b[i + 1]) || (b[i] < b[i - 1] && b[i] < b[i + 1]);
		}
		if (!flag)
			cout << "NO\n";
		else {
			cout << "YES\n";
			print(b);
			cout << "\n";
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