// #pragma GCC optimize("Ofast,unroll-all-loops")

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

// template<class t>
// using oset = tree<t, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

#define int ll
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int INF = 1e18 + 666;

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

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

int get_sq(int a) {
	return (a * (a + 1)) >> 1;
}

void run() {
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		int mn = min(v >> 1, cnt);
		ans += mn;
		v -= mn << 1;
		cnt -= mn;
		ans += v / 3;
		v %= 3;
		cnt += v;
	}
	cout << ans << endl;
} // kek