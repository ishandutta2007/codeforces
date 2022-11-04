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

int sgn(int v) {
	if (v > 0) {
		return 1;
	}
	if (v < 0) {
		return -1;
	}
	return 1;
}

void run() {
	int n, r;
	cin >> n >> r;
	vector<pii> items(n);
	for (auto &[x, y] : items) {
		cin >> x >> y;
	}
	sort(all(items), [](const pii &a, const pii &b) {
		int s1 = sgn(a.second), s2 = sgn(b.second);
		if (s1 != s2) {
			return s1 > s2;
		}
		if (s1 >= 0) {
			return a.first < b.first;
		}
		return a.first + a.second > b.first + b.second;
	});
	int cnt = 0;
	for (auto &[x, y] : items) {
		if (r >= x) {
			++cnt;
			r += y;
		}
	}
	// cout << cnt << endl;
	if (cnt == n && r >= 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}