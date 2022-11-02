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
	int a, b, c, d;
	string s;
	cin >> a >> b >> c >> d >> s;
	int n = s.size();
	int A = 0, B = 0;
	for (auto i : s) {
		if (i == 'A')
			A++;
		else
			B++;
	}
	if (A != a + c + d || B != b + c + d) {
		cout << "NO\n";
		return;
	}
	vector<int> ab, ba;
	int any = 0, absum = 0, basum = 0;
	int last = 0;
	for (int i = 1; i < n; ++i) {
		if (s[i] == s[i - 1]) {
			if (last == i - 1) {
				last = i;
				continue;
			}
			if (s[last] == s[i - 1]) {
				any += (i - 1 - last) / 2;
				last = i;
				continue;
			}
			if (s[last] == 'A') {
				ab.push_back((i - 1 - last + 1) / 2);
				absum += (i - 1 - last + 1) / 2;
				last = i;
				continue;
			}
			ba.push_back((i - 1 - last + 1) / 2);
			basum += (i - 1 - last + 1) / 2;
			last = i;
			continue;
		}
	}
	int i = n;
	if (last != n - 1) {
		if (s[last] == s[i - 1]) {
			any += (i - 1 - last) / 2;
			last = i;
		}
		else if (s[last] == 'A') {
			ab.push_back((i - 1 - last + 1) / 2);
			absum += (i - 1 - last + 1) / 2;
			last = i;
		}
		else {
			ba.push_back((i - 1 - last + 1) / 2);
			basum += (i - 1 - last + 1) / 2;
			last = i;
		}
	}
	if (max(c - absum, 0ll) + max(d - basum, 0ll) <= any) {
		cout << "YES\n";
		return;
	}
	sort(rall(ab));
	sort(rall(ba));
	if (c > absum && d > basum) {
		cout << "NO\n";
		return;
	}
	if (c > absum) {
		absum += any;
		for (auto i : ba) {
			if (c == absum)
				break;
			if (c - absum >= i - 1) {
				basum -= i;
				absum += i - 1;
			}
			else {
				basum -= c - absum + 1;
				absum = c;
				break;
			}
		}
		if (absum >= c && basum >= d)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else {
		swap(ab, ba);
		swap(absum, basum);
		swap(c, d);
		absum += any;
		for (auto i : ba) {
			if (c == absum)
				break;
			if (c - absum >= i - 1) {
				basum -= i;
				absum += i - 1;
			}
			else {
				basum -= c - absum + 1;
				absum = c;
				break;
			}
		}
		if (absum >= c && basum >= d)
			cout << "YES\n";
		else
			cout << "NO\n";
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