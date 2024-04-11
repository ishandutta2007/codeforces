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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a;
	for (int i = 0; i < m; ++i) {
		string s;
		for (int j = 0; j < m; ++j)
			s += '0';
		s[i] = '1';
		cout << "? " <<  s << endl;
		int x;
		cin >> x;
		a.push_back({ x, i });
	}
	sort(all(a));
	int sum = 0;
	string s;
	for (int j = 0; j < m; ++j)
		s += '0';
	for (int i = 0; i < m; ++i) {
		string s1 = s;
		s1[a[i].second] = '1';
		cout << "? " << s1 << endl;
		int x;
		cin >> x;
		if (x - sum == a[i].first) {
			sum = x;
			s = s1;
		}
	}
	cout << "! " << sum << endl;
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