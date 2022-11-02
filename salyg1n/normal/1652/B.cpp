#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

typedef int_fast64_t ll;
typedef long double ld;

#define int int_fast64_t
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define input(a) for (auto& _ : a) cin >> _
#define print(a) for (auto _ : a) cout << _

//#define x first
//define y second

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	map<char, int> m;
	for (auto i : s) {
		if (!m.count(i))
			m[i] = 0;
		m[i]++;
	}
	vector<int> p(26, -1);
	for (int i = 0; i < n; ++i) {
		p[s[i] - 'a'] = i;
	}
	int mn = 1e9;
	for (auto i : p) {
		if (i != -1)
			mn = min(mn, i);
	}
	cout << s.substr(mn, n - mn) << "\n";
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