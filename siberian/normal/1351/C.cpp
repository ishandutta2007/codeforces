#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
set<pair<pair<int, int>, pair<int, int>>> used;
	
bool check(pair<int, int> a, pair<int, int> b) {
	if (a > b) swap(a, b);
	return used.count({a, b});
}

void add(pair<int, int> a, pair<int, int> b) {
	if (a > b) swap(a, b);
	used.insert({a, b});
}

void solve() {
	string s;
	cin >> s;
	int ans = 0;
	int x = 0, y = 0;
	used.clear();
	for (auto i : s) {
		int it = 0;
		if (i == 'S') it = 0;
		else if (i == 'N') it = 1;
		else if (i == 'W') it = 2;
		else if (i == 'E') it = 3; 
		else assert(false);
		int nx = x + dx[it];
		int ny = y + dy[it];
		if (check({x, y}, {nx, ny})) ans++;
		else ans += 5;
		add({x, y}, {nx, ny});
		x = nx;
		y = ny;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}