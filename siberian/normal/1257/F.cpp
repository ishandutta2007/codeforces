#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
}

int ans = -1;

vector<int> make(int x) {
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		ans[i] = __builtin_popcount(((a[i] & ((1 << 15) - 1))) ^ x);
	}
	return ans;
}

vector<int> make2(int x) {
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		ans[i] = __builtin_popcount((a[i] >> 15) ^ x);
	}
	return ans;
}

map <vector<int>, int> masks;

pair<bool, int> check(int len, vector<int> x) {
	for (auto &i : x) {
		if (i > len) return {false, 0};
		i = len - i;
	}
	if (masks.find(x) != masks.end()) {
		return {true, masks[x]};
	}
	return {false, 0};
}

void run() {
	for (int mask = 0; mask < (1 << 15); mask++) {
		masks[make(mask)] = mask;
	}

	for (int len = 0; len <= 30; len++) {
		for (int mask = 0; mask < (1 << 15); mask++) {
			auto x = make2(mask);
			auto fans = check(len, x);
			if(fans.first) {
				ans = (mask << 15) | fans.second;
				return;
			}
		}
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}