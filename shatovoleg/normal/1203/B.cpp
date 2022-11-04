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

const int maxn = 1e4 + 1;

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(maxn, 0);
	int mn = INF, mx = -INF;
	for (int i = 0; i < 4 * n; ++i) {
		int v;
		cin >> v;
		cmax(mx, v);
		cmin(mn, v);
		++cnt[v];
	}
	int s = mx * mn;
	for (auto &x : cnt) {
		if (x & 1) {
			cout << "NO" << endl;
			return;
		}
		x >>= 1;
	}
	for (int i = 1; i < maxn; ++i) {
		if (!cnt[i]) {
			continue;
		}
		if (s % i) {
			cout << "NO" << endl;
			return;
		}
		if (cnt[i] != cnt[s / i]) {
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