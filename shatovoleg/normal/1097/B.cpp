#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

#define int ll
#define all(v) v.begin(), v.end()
#define len(v) (int)(v).size()
#define pii pair<int, int>
#define pb push_back
#define kek pop_back

// template<class t>
// using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

void UseFiles(const string &s) {
#ifndef LOCAL
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void run() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	vector<vector<bool>> dp(n + 1, vector<bool>(360, false));
	dp[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 360; ++j) {
			int d = (j - a[i] + 360) % 360;
			if (dp[i][d])
				dp[i + 1][j] = true;
			d = (j + a[i]) % 360;
			if (dp[i][d])
				dp[i + 1][j] = true;
		}
	}
	if (dp[n][0]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}