#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int sz[3];
vector<int> a[3];

void read() {
	for (int i = 0; i < 3; i++) {
		cin >> sz[i];
		a[i].assign(sz[i], 0);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < sz[i]; j++) {
			cin >> a[i][j];
		}
		sort(all(a[i]));
	}
}

int sq(int a) {
	return a * a;
}

int calc(int a, int b, int c) {
	return sq(a - b) + sq(b - c) + sq(a - c);
}

int solve(vector<int> & a, vector<int> & b, vector<int> & c) {
	int ans = -1;
	for (int i = 0; i < (int)b.size(); i++) {
		int posL = --upper_bound(all(a), b[i]) - a.begin();
		if (posL < 0 || posL >= (int)a.size()) continue;
		int posR = lower_bound(all(c), b[i]) - c.begin();
		if (posR < 0 || posR >= (int)c.size()) continue;
		int fans = calc(a[posL], b[i], c[posR]);
		if (ans == -1 || fans < ans) {
			ans = fans;
		}
	}
	return ans;
} 

int ans;

void run() {
	vector<int> have = {0, 1, 2};
	ans = -1;
	do {
		int fans = solve(a[have[0]], a[have[1]], a[have[2]]);
		if (fans == -1) continue;
		if (ans == -1 || fans < ans) {
			ans = fans;
		}
	} while (next_permutation(all(have)));
}

void write() {
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		read();
		run();
		write();
	}
	return 0;
}