#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	for (int i = 0; i + 1 < n; ++i) {
		m += v[i] - max(v[i + 1] - k, 0ll);
		if (m < 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

void run() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}